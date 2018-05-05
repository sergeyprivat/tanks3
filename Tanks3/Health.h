#ifndef HEALTH_H
#define HEALTH_H
#pragma once
#include"Entity.h"


class Health 
{
public:
	Health(Entity &ent);
	Entity *entity;
	void hit(int damage);
	void setHitPoints(int points);
	int getHitpoints();
	virtual ~Health();

private:
	int hitPoints;
	

};

#endif // !HEALTH_H