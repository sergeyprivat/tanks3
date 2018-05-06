// Tanks3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Entity.h"
#include "Game.h"
#include <ctime>


int main()
{
	srand((unsigned)time(0)); //So random numbers will be always random.
	Game  game ;
	game.startGame();

	while (1)
	{
		game.update();
		game.render();
		Sleep(20);

	}

	getchar();

    return 0;
}

