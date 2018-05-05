#include "stdafx.h"
#include "Weapon.h"
//#include "Bullet.h"
#include"EntityCreator.h"



Weapon::Weapon(Entity &ent)
{
	entity = &ent;
}

void Weapon::shoot()
{
	/*
	Entity *bullet =  EntityCreator::getEntity(BulletInst);
	std::vector<Entity *> targets = entity->getTargets();
	std::vector<Entity *> group = entity->getGroup();
	bullet->setTargets(targets);
	bullet->setGroup(group);

	bullet->getBody()->setX(entity->getBody()->getX());
	bullet->getBody()->setY(entity->getBody()->getY());
	bullet->getBody()->setDirection(entity->getBody()->getDirection());
	entity->notifyObservers(Signal::CreateEntity, bullet);
	
	*/
	
	
}

Weapon::~Weapon()
{
}
