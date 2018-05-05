#ifndef IENTITYCREATOR_H
#define IENTITYCREATOR_H
#pragma once
#include "Entity.h"
#include "Enums.h"

class IEntityCreator
{
public:
	
	virtual Entity *getEntity(EntityType type)  = 0;

	virtual ~IEntityCreator() {}
	
};
#endif
