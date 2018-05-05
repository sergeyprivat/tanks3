#ifndef BOTCONTROL_H
#define BOTCONTROL_H
#pragma once
#include"Entity.h"
#include"BotControl.h"
#include"IControl.h"

class BotControl : public IControl
{
public:
	BotControl(Entity &ent);
	Entity *entity;
	Command getCommand();

	virtual ~BotControl();

	
	
};

#endif // !BOTCONTROL_H