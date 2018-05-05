#include "Entity.h"

int Entity::lastId = 0;

Entity::Entity()
{
	Entity::lastId++;
	id = Entity::lastId;
}

int Entity::getId()
{
	return id;
}

void Entity::setGroup(Group group)
{
	this->group = group;
}

Group Entity::getGroup()
{
	return group;
}

void Entity::update()
{
}

void Entity::render()
{
	view->render();
}


Entity::~Entity()
{
}
