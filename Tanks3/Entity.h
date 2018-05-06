#ifndef ENTITY_H
#define ENTITY_H
#pragma once
#include<map>
#include<vector>
#include"Enums.h"
#include"IObserver.h"
#include"IObservable.h"
#include"Health.h"
#include"IControl.h"
#include"Weapon.h"
#include"View.h"
#include"Body.h"
#include"Physics.h"


class Entity: public IObservable
{
public:
	Entity();
	std::vector<Group> targetsGroups;
	int getId();
	void setEtityType(EntityType type);
	EntityType getEntityType();
	void setGroup(Group group);
	Group getGroup();
	void update();
	void render();

	void addObserver(IObserver *o);
	void removeObserver(IObserver *o);
	void notifyObservers(Signal sig, Entity *entity);

	Body *body;
	Physics *physics;
	Health *health;
	IControl *control;
	Weapon *weapon;
	View *view;
		
	~Entity();

private:
	Group group;
	EntityType type;
	static int lastId;
	IObserver *observer;
	int id;

	
};


#endif // !ENTITY_H