#include "Entity.h"
#include "Game.h"

int Entity::lastId = 0;

Entity::Entity()
{
	Entity::lastId++;
	id = Entity::lastId;
}

int Entity::getId()
{
	return id;
}

void Entity::setEtityType(EntityType type)
{
	this->type = type;
}

EntityType Entity::getEntityType()
{
	return type;
}

void Entity::setGroup(Group group)
{
	this->group = group;
}

Group Entity::getGroup()
{
	return group;
}

void Entity::update()
{
	if (view)
	{
		view->clear();
	}
	if (control)
	{
		Command command = control->getCommand();

		switch (command)
		{

		case Command::shoot:
		{
			weapon->shoot();
			return;
		}
		
		case Command::left:
		{
			body->setDirection(Direction::Left);
			break;
		}
		case Command::right:
		{
			body->setDirection(Direction::Right);
			break;
		}
		case Command::up:
		{
			body->setDirection(Direction::Up);
			break;
		}
		case Command::down:
		{
			body->setDirection(Direction::Down);
			break;
		}

		
		default:
			break;
		}

		if (physics && command != Command::Nothing)
		{
			physics->move();
		}
			
	}
	else
	{
		if (physics)
			{
				physics->move();
			}
	}
	
	
}

void Entity::render()
{
	view->render();
}


void Entity::addObserver(IObserver *o)
{
	observer = o;
}

void Entity::removeObserver(IObserver *o)
{

}

void Entity::notifyObservers(Signal sig, Entity *entity)
{
	observer->handleEvent(sig, *entity);
}

Entity::~Entity()
{
}
