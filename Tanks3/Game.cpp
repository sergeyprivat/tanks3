#include "Game.h"
#include <windows.h> 



Game::Game()
{
}


void Game::stopGame() {
}


void Game::update() {


	int size = entities.size();
	for (int i = 0; i < size;i++)
	{
		entities[i]->update();

	}


}

void Game::render() {


	int size = entities.size();
	for (int i = 0; i < size; i++)
	{
		entities[i]->render();

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

	Entity *playerTank = EntityCreator::getEntity(EntityType::TankInst);
	playerTank->addObserver(this);

	playerTank->setGroup(players);

	players.push_back(playerTank);
	addEntity(*playerTank);
	playerTank->getBody()->setX(5);
	playerTank->getBody()->setY(5);

	Entity *enemyT = EntityCreator::getEntity(EntityType::EnemyTankInst);
	enemyT->addObserver(this);

	enemyT->getBody()->setX(20);
	enemyT->getBody()->setY(20);
	enemies.push_back(enemyT);
	addEntity(*enemyT);

	update();
	render();
}


void Game::addEntity(Entity &entity) {
	entities.push_back(&entity);
}

void Game::onEntityDestroyed(Entity &entity) {
	// remove destroyed entity
	std::vector<Entity*>::iterator it;
	for (it = entities.end(); it != entities.begin(); )
	{
		it--;
		if ((*it) == &entity)
		{
			delete * it;
			it = entities.erase(it);
		}

	}



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
			addEntity(sender);
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
					Entity *wall = EntityCreator::getEntity(EntityType::WallInst);
					wall->addObserver(this);
					wall->getBody()->setX(x);
					wall->getBody()->setY(y);
					neutral.push_back(wall);
					wall->setGroup(neutral);
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
	Entity *gold = EntityCreator::getEntity(EntityType::GoldInst);
	gold->addObserver(this);
	int x = Game::FIELD_WIDTH / 2;
	int y = Game::FIELD_LENGTH - 1;
	gold->getBody()->setX(x);
	gold->getBody()->setY(y);
	players.push_back(gold);
	gold->setGroup(players);
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
			Entity *wall = EntityCreator::getEntity(EntityType::WallInst);
			wall->addObserver(this);
			wall->getBody()->setX(xw);
			wall->getBody()->setY(yw);
			neutral.push_back(wall);
			wall->setGroup(neutral);
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
	for (int xe = x; xe <= x2; xe++)
	{
		for (int ye = y; ye <= y2; ye++)
		{
			for each (Entity *ent in entities)
			{
				if (ent->body->getX() == xe && ent->getBody()->getY() == ye)
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
