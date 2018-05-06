#ifndef HEALTH_H
#define HEALTH_H
#pragma once

class Entity;

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