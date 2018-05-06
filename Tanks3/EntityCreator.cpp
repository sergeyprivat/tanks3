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
		newEnt->setEtityType(EntityType::Bullet);
		newEnt->body = new Body(*newEnt);
		newEnt->physics = new Physics(*newEnt);
		newEnt->view = new View(*newEnt);
		newEnt->view->setSymbol('o');
		newEnt->control = nullptr;
		newEnt->health = nullptr;
		newEnt->weapon = nullptr;
		return newEnt;

	}
	case EntityType::EnemyTank:
	{
		newEnt->setEtityType(EntityType::EnemyTank);
		newEnt->body = new Body(*newEnt);
		newEnt->physics = new Physics(*newEnt);
		newEnt->view = new View(*newEnt);
		newEnt->view->setSymbol('E');
		newEnt->control = new BotControl(*newEnt);
		newEnt->health = new Health(*newEnt);
		newEnt->health->setHitPoints(1);

		newEnt->weapon = new Weapon(*newEnt);
		return newEnt;

	}

	case EntityType::Tank:
	{
		newEnt->setEtityType(EntityType::Tank);
		newEnt->body = new Body(*newEnt);
		newEnt->physics = new Physics(*newEnt);
		newEnt->view = new View(*newEnt);
		newEnt->view->setSymbol('T');
		newEnt->control = new PlayerControl(*newEnt);
		newEnt->health = new Health(*newEnt);
		newEnt->health->setHitPoints(3);
		newEnt->weapon = new Weapon(*newEnt);

		return newEnt;
	}

	case EntityType::Gold:
	{
		newEnt->setEtityType(EntityType::Gold);
		newEnt->body = new Body(*newEnt);		
		newEnt->view = new View(*newEnt);
		newEnt->view->setSymbol('G');
		newEnt->health = new Health(*newEnt);
		newEnt->health->setHitPoints(1);

		newEnt->control = nullptr;
		newEnt->weapon = nullptr;
		newEnt->physics = nullptr;

		return newEnt;
	}
	case EntityType::Wall:
	{
		newEnt->setEtityType(EntityType::Wall);
		newEnt->body = new Body(*newEnt);
		newEnt->view = new View(*newEnt);
		newEnt->view->setSymbol('W');
		newEnt->health = new Health(*newEnt);
		newEnt->health->setHitPoints(1);

		newEnt->physics = nullptr;
		newEnt->control = nullptr;
		newEnt->weapon = nullptr;
		return newEnt;
	}

	}
	
	return nullptr;
}



EntityCreator::~EntityCreator()
{
}
