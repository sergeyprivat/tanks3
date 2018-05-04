#include"stdafx.h"
#include "body.h"


Body::Body(Entity *ent)
{
	setEntity(*ent);
	x = 0;
	y = 0;
	direct = Up;

}

// return true if point not available
bool Body::testCollision(Entity &otherEntity)
{
	int oX_ = 0;
	int oY_ = 0;
	if (otherEntity.components[ComponentName::Body])
	{
		 oX_ = static_cast<Body *>(otherEntity.components[ComponentName::Body])->getX();
		 oY_ = static_cast<Body *>(otherEntity.components[ComponentName::Body])->getY();
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




Body::~Body()
{
}
