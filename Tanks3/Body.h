#ifndef BODY_H
#define BODY_H
#include "stdafx.h"
#include "Enums.h"
#include "Entity.h"

class Body
{
public:
	Body(Entity &entity);
	Entity *entity;
	bool testCollision(Entity &otherEntity);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	Direction getDirection();
	void setDirection(Direction direct);
	Body *getBody();
	virtual ~Body();


private:
	
	int x, y;
	Direction direct;

};

#endif
