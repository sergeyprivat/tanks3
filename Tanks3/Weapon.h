#ifndef WEAPON_H
#define WEAPON_H
#pragma once

class Entity;

class Weapon 
{
public:
	Weapon(Entity &ent);
	Entity * entity;
	void shoot();
	virtual ~Weapon();

};

#endif // !WEAPON_H