#ifndef ACOMPONENT
#define ACOMPONENT
#pragma once
#include "Entity.h"


class AComponent
{
public:
	AComponent();
	Entity *getEntity();
	void setEntity(Entity &ent);
	~AComponent();
private:
	Entity *entity;
};

#endif // !ACOMPONENT