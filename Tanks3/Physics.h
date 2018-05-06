#ifndef PHYSICS_H
#define PHYSICS_H
#pragma once

class Entity;

class Physics 
	
{
public:
	
	Physics(Entity &ent);
	Entity *entity;
	void move();
	int drug = 0;
	virtual ~Physics();

	

};

#endif // !PHYSICS_H
