#include "stdafx.h"
#include "Physics.h"
#include"Game.h"
#include"Body.h"



Physics::Physics(Entity &ent)
{
	entity = &ent;
	
}

void Physics::move()
{
	Body *thisBody_;
	int curX_, curY_; //current x, y
	if (entity->body)
	{
		thisBody_ = entity->body;

	}
	else
	{
		return;
	}

	curX_ = thisBody_->getX();
	curY_ = thisBody_->getY();
	Direction direct = thisBody_->getDirection();

	switch (direct)
	{
	case Direction::Left:
	{
		if (curX_ > 1)
		{
			thisBody_->setX(--curX_);
		}

		break;

	}

	case Direction::Right:
	{
		if (curX_ < Game::FIELD_WIDTH)
		{
			thisBody_->setX(++curX_);
		}

		break;

	}

	case Direction::Up:
	{

		if (curY_ > 1)
		{
			thisBody_->setY(--curY_);
		}

		break;

	}

	case Direction::Down:
	{

		if (curY_ < Game::FIELD_LENGTH)
		{
			thisBody_->setY(++curY_);
		}
		break;

	}


	}



}


Physics::~Physics()
{
}
