#include"stdafx.h"
#include "body.h"
#include"Entity.h"


Body::Body(Entity &ent)
{
	entity = &ent;
	x = 0;
	y = 0;
	direct = Up;

}

// return true if point not available
bool Body::testCollision(Entity &otherEntity)
{
	Body *otherBody; 
	int oX_ = -1;
	int oY_ = -1;
	if (otherEntity.body)
	{
		otherBody = otherEntity.body;
		 oX_ = otherBody->getX();
		 oY_ = otherBody->getY();
	}
	
	if (x == oX_ && y == oY_)
	{
		return true;
	}

	return false;
}

int Body::getX()
{
	return this->x;
}

void Body::setX(int x_)
{
	x = x_;
}

int Body::getY()
{
	return y;
}

void Body::setY(int y_)
{
	y = y_;
}



Direction Body::getDirection()
{
	return this->direct;
}

void Body::setDirection(Direction direct)
{
	this->direct = direct;
}

Body * Body::getBody()
{
	return this;
}




Body::~Body()
{
}
