#ifndef ENTITY_H
#define ENTITY_H
#pragma once
#include<map>
#include<vector>
#include"Enums.h"

class Health;
class IControl;
class Weapon;
class View;
class Body;
class Physics;

class Entity
{
public:
	Entity();
	std::vector<Group> targetsGroups;
	int getId();
	void setGroup(Group group);
	Group getGroup();
	void update();
	void render();

	Body *body;
	Physics *physics;
	Health *health;
	IControl *control;
	Weapon *weapon;
	View *view;

	//std::map < ComponentName, AComponent *> components;
	~Entity();

private:
	Group group;
	EntityType type;
	static int lastId;
	int id;
};


#endif // !ENTITY_H