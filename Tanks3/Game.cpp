#include "Game.h"
#include <windows.h> 
#include<iostream>
#include"EntityCreator.h"



Game::Game()
{
}


void Game::stopGame() {
}


void Game::update() {

	std::map<int, Entity *>::iterator it;
	std::map<int, Entity *>::iterator it2;
	for (it = entities.begin(); it != entities.end(); it++)
	{

		int oldX_ = it->second->body->getX();
		int	oldY_ = it->second->body->getY();

		it->second->update();

		//check if bullet on border field an destroy it
		if (it->second->getEntityType() == EntityType::Bullet)
		{
			if (it->second->body->getX() == oldX_ &&  it->second->body->getY() == oldY_)
			{
				it->second->notifyObservers(Signal::DestroyEntity, it->second);
				continue;
			}
			
		}


		//testCollision with other Entities
		bool isCollision = false;

		for (it2 = entities.begin(); it2 != entities.end(); it2++)

		{
			//skip check colision with yourself
			if (it->second != it2->second)
			{
				if (it->second->body->testCollision(*it2->second))
				{
					isCollision = true;
					
					if (it->second->getEntityType() == EntityType::Bullet)
					{
						if (checkTarget(it->second->targetsGroups, it2->second->getGroup()))
						{
							if (it2->second->health)
							{
								it2->second->health->hit(1);
							}
						}
						it->second->notifyObservers(Signal::DestroyEntity, it->second);
					}
				}

			}

		}

		if (isCollision)
		{
			it->second->body->setX(oldX_);
			it->second->body->setY(oldY_);
		}

	}

	//add new entities in map
	for each (Entity *newEnt in newEntities)
	{
		addEntity(*newEnt);

	}
	newEntities.clear();

	//remove died entities from map
	for each (int diedId in diedEntitiesID)
	{
		delete(entities[diedId]);
		entities.erase(diedId);

	}
	diedEntitiesID.clear();

}

void Game::render() {

	std::map<int, Entity *>::iterator it;

	for (it = entities.begin(); it != entities.end(); it++)
	{
		it->second->render();

	}

}

void Game::startGame() {


	//draw borders

	HANDLE hOut;
	COORD Position;

	SetWindow_(80, 40);

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	for (int x = 0; x < FIELD_WIDTH + 2; x++)
	{
		for (int y = 0; y < FIELD_LENGTH + 2; y++)
		{
			if (x == 0 || y == 0 || x == FIELD_WIDTH + 1 || y == FIELD_LENGTH + 1)
			{

				Position.X = x;
				Position.Y = y;

				SetConsoleCursorPosition(hOut, Position);

				std::cout << '8';
			}

		}
	}


	setCastle_();

	setWalls_();

	//set player's tank
	Entity *playerTank = EntityCreator::getEntity(EntityType::Tank);
	playerTank->addObserver(this);

	playerTank->setGroup(Group::Players);
	playerTank->targetsGroups.push_back(Group::Enemies);
	playerTank->targetsGroups.push_back(Group::Neutrals);

	playerTank->body->setX(5);
	playerTank->body->setY(5);
	addEntity(*playerTank);

	//set enemy's tank
	Entity *enemyT = EntityCreator::getEntity(EntityType::EnemyTank);
	enemyT->addObserver(this);

	enemyT->body->setX(20);
	enemyT->body->setY(20);
	enemyT->setGroup(Group::Enemies);
	enemyT->targetsGroups.push_back(Group::Players);
	enemyT->targetsGroups.push_back(Group::Neutrals);

	addEntity(*enemyT);

}


void Game::addEntity(Entity &entity) {
	entities[entity.getId()] = &entity;
}

void Game::onEntityDestroyed(Entity &entity) {
	//add  id of entities which destryed to vector 
	diedEntitiesID.push_back(entity.getId());

}



void Game::onPlayerDestroyed()
{
}

void Game::gameOver()
{
}



void Game::handleEvent(Signal sig, Entity & sender)
{
	switch (sig)
	{
	case Signal::CreateEntity:
	{
		if (&sender != nullptr)
		{
			sender.addObserver(this);
			newEntities.push_back(&sender);
		}
		break;
	}
	case Signal::DestroyEntity:
	{
		onEntityDestroyed(sender);

		break;

	}

	default:
	{


	}
	}
}



COORD Game::genPosition(int maxX, int maxY)
{

	COORD pos;
	pos.X = rand() % (maxX + 1);
	pos.Y = rand() % (maxY + 1);
	return pos;

}

void Game::setWalls_()
{
	//set walls
	int wallsNumb_ = 0; // current generated number of walls

	while (wallsNumb_ < NUMBER_OF_WALL)
	{

		int length = rand() % (MAX_LENGTH_OF_WALL)+1;
		Direction direct = static_cast <Direction>(rand() % 2);
		COORD newCoord = genPosition(FIELD_WIDTH, FIELD_LENGTH);

		int x2 = 0, y2 = 0;
		if (isAvailablePosition_(newCoord.X, newCoord.Y, length, direct))
		{
			if (direct == Direction::Right)
			{
				x2 = newCoord.X + length; y2 = newCoord.Y;

			}
			else if (direct = Direction::Down)
			{
				y2 = newCoord.Y + length; x2 = newCoord.X;
			}

			for (int x = newCoord.X; x <= x2; x++)
			{
				for (int y = newCoord.Y; y <= y2; y++)
				{
					Entity *wall = EntityCreator::getEntity(EntityType::Wall);
					wall->addObserver(this);
					wall->body->setX(x);
					wall->body->setY(y);
					wall->setGroup(Group::Neutrals);
					addEntity(*wall);

				}

			}
			wallsNumb_++;
		}

	}


}

void Game::setCastle_()
{
	//set gold
	Entity *gold = EntityCreator::getEntity(EntityType::Gold);
	gold->addObserver(this);
	int x = Game::FIELD_WIDTH / 2;
	int y = Game::FIELD_LENGTH - 1;
	gold->body->setX(x);
	gold->body->setY(y);
	gold->setGroup(Group::Players);
	addEntity(*gold);

	//set walls of castle
	for (int xw = x - 1; xw <= x + 1; xw++)
	{
		for (int yw = y - 1; yw <= y + 1; yw++)
		{
			if (xw == x && yw == y)
			{
				continue;
			}
			Entity *wall = EntityCreator::getEntity(EntityType::Wall);
			wall->addObserver(this);
			wall->body->setX(xw);
			wall->body->setY(yw);
			wall->setGroup(Group::Neutrals);
			addEntity(*wall);

		}

	}


}

bool Game::isAvailablePosition_(int x, int y, int length, Direction direct)
{
	int x2 = 0, y2 = 0; // calculated coordinates for area

	if (x < 1 || y < 1)
	{
		return false;
	}

	if (direct == Direction::Right)
	{
		x2 = x + length; y2 = y;
		if (Game::FIELD_WIDTH <= x2)
		{
			return false;
		}

	}
	if (direct == Direction::Down)
	{
		x2 = x; y2 = y + length;

		if (Game::FIELD_LENGTH <= y2)
		{
			return false;
		}

	}

	//check if other entity busy this place
	std::map<int, Entity *>::iterator it;
	for (int xe = x; xe <= x2; xe++)
	{
		for (int ye = y; ye <= y2; ye++)
		{
			for (it = entities.begin(); it != entities.end(); it++)
			{
				if (it->second->body->getX() == xe && it->second->body->getY() == ye)
				{
					return false;
				}
			}
		}


	}

	return true;

}

void Game::SetWindow_(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}



Game::~Game()
{
}

bool Game::checkTarget(std::vector<Group> Targets, Group entityTarget)
{
	bool result = false;

	for each(Group target in Targets)
	{
		if (target == entityTarget)
		{
			result = true;
		}
	}
	return result;
}
