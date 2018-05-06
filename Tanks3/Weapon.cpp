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

	Entity *bullet =  EntityCreator::getEntity(Bullet);
	
	bullet->setGroup(entity->getGroup());
	bullet->targetsGroups = entity->targetsGroups;

	bullet->body->setX(entity->body->getX());
	bullet->body->setY(entity->body->getY());
	bullet->body->setDirection(entity->body->getDirection());
	
	entity->notifyObservers(Signal::CreateEntity, bullet);
	
	
	
	
}

Weapon::~Weapon()
{
}
