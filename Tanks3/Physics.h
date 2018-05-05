#ifndef PHYSICS_H
#define PHYSICS_H
#pragma once
#include"Entity.h"


class Physics 
	
{
public:
	
	Physics(Entity &ent);
	Entity *entity;
	void move();
	virtual ~Physics();

	

};

#endif // !PHYSICS_H
