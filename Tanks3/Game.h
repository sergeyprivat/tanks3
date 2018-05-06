#ifndef GAME_H
#define GAME_H
#pragma once
#include<map>
#include <vector>
#include "Entity.h"
#include <windows.h>

class Game : public IObserver
{
public:
	Game();
	void stopGame();
	void update();
	void render();
	void startGame();
	void addEntity(Entity & entity);
	void onEntityDestroyed(Entity & entity);
	void onPlayerDestroyed();
	void gameOver();
	void handleEvent(Signal sig, Entity & sender);
	//game options
	static const int FIELD_LENGTH = 30;
	static const int FIELD_WIDTH = 30;
	static const  int NUMBER_OF_ENEMY = 1;
	static const  int NUMBER_OF_WALL = 10;
	static const  int MAX_LENGTH_OF_WALL = 10;
	// chance 1/n
	static const  int CHANCE_ENEMY_ACTION = 2;

	COORD genPosition(int maxX, int maxY);

	void setWalls_();
	void setCastle_();
	bool isAvailablePosition_(int x, int y, int length, Direction direct);
	void SetWindow_(int Width, int Height);

	~Game();
private:
	std::map<int, Entity *> entities;
	std::vector<Entity *> newEntities;
	std::vector<int> diedEntitiesID;

	bool checkTarget(std::vector <Group> group, Group entityTarget);
};

#endif // !GAME_H