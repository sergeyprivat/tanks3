#include "AComponent.h"



AComponent::AComponent()
{
}

Entity *AComponent::getEntity()
{
	return this->entity;
}

void AComponent::setEntity(Entity & ent)
{
	this->entity = &ent;
}


AComponent::~AComponent()
{
}
