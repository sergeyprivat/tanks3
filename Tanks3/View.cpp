#include "stdafx.h"
#include "View.h"
#include "Body.h"


View::View(Entity &ent)
{
	entity = &ent;
}

char View::getSymbol()
{
	return symbol;
}

void View::setSymbol(char ch)
{
	symbol = ch;
}

void View::render()
{
	
	setCursorPosition();
	std::cout << symbol;

	
}

void View::clear()
{
	setCursorPosition();
	std::cout << ' ';
}

void View::setCursorPosition()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Body *thisBody_;
	
	if (entity->body)
	{
		thisBody_ = entity->body;

	}
	else
	{
		return;
	}

	Position.X = thisBody_->getX();
	Position.Y = thisBody_->getY();
	SetConsoleCursorPosition(hOut, Position);
}


View::~View()
{
}
