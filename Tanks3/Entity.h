#ifndef ENTITY_H
#define ENTITY_H
#pragma once
#include<map>
#include"Enums.h"

class AComponent;

class Entity
{
public:
	Entity();
	static int lastId;
	int id;
	Group group;
	EntityType type;
	std::map < ComponentName, AComponent *> components;
	~Entity();
};
	

#endif // !ENTITY_H