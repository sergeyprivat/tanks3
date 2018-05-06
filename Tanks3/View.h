#ifndef VIEW_H
#define VIEW_H
#pragma once
#include <windows.h>
#include <iostream>

class Entity;

class View 	
{
public:
	View(Entity &ent);
	Entity *entity;
	char getSymbol() ;
	void setSymbol(char ch);
	void render();
	void clear();
	
	virtual ~View();

private:
	
	char symbol;
	void setCursorPosition();

};

#endif // !VIEW_H