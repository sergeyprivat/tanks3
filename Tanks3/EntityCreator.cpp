#include "stdafx.h"
#include "EntityCreator.h"
#include "Entity.h"
#include"Body.h"
#include"Physics.h"
#include"View.h"
#include"PlayerControl.h"
#include"BotControl.h"
#include"Weapon.h"
#include "Health.h"

EntityCreator::EntityCreator()
{
}

Entity *EntityCreator::getEntity(EntityType entName)
{
	
	Entity * newEnt = new Entity();
	switch (entName)
	{
	case EntityType::Bullet:
	{
		newEnt->body = new Body(*newEnt);
		newEnt->physics = new Physics(*newEnt);
		newEnt->view = new View(*newEnt);

		return newEnt;

	}
	case EntityType::EnemyTank:
	{
		newEnt->body = new Body(*newEnt);
		newEnt->physics = new Physics(*newEnt);
		newEnt->view = new View(*newEnt);
		newEnt->control = new BotControl(*newEnt);
		newEnt->health = new Health(*newEnt);

		return newEnt;

	}

	case EntityType::Tank:
	{
		newEnt->body = new Body(*newEnt);
		newEnt->physics = new Physics(*newEnt);
		newEnt->view = new View(*newEnt);
		newEnt->control = new PlayerControl(*newEnt);
		newEnt->health = new Health(*newEnt);
		return newEnt;
	}

	case EntityType::Gold:
	{
		newEnt->body = new Body(*newEnt);		
		newEnt->view = new View(*newEnt);		
		newEnt->health = new Health(*newEnt);
		return newEnt;
	}
	case EntityType::Wall:
	{
		newEnt->body = new Body(*newEnt);
		newEnt->view = new View(*newEnt);
		newEnt->health = new Health(*newEnt);
		return newEnt;
	}



	}
	
	

	return nullptr;
}



EntityCreator::~EntityCreator()
{
}
