#ifndef WEAPON
#define WEAPON
#pragma once
#include"Entity.h"


class Weapon 
{
public:
	Weapon(Entity &ent);
	Entity * entity;
	void shoot();
	virtual ~Weapon();

};

#endif // !WEAPON