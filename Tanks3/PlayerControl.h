#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#include "Enums.h"
#include"Entity.h"
#include"IControl.h"


class PlayerControl : public IControl
{
public:
	PlayerControl(Entity &entity);
	Entity * entity;
	Command PlayerControl::getCommand();
	virtual ~PlayerControl();

};


#endif // !CONTROL_H
