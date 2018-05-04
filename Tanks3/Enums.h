#ifndef ENUMS_H
#define ENUMS_H
#pragma once

enum Direction
{
	Right = 0, Down = 1, Left = 2, Up = 3

};

enum EntityType
{
	Tank, EnemyTank, Bullet, Gold, Wall

};

enum Command
{
	Nothing = 0, left, right, up, down, shoot, pause

};

enum Group
{
	Players, Enemies, Neutrals
};

enum ComponentName
{
	Body, Health, Phisics, Weapon, Control
};

enum Signal
{
	CreateEntity,
	DestroyEntity
};
#endif // !ENUMS_H