#include "Controller.h"
#include <iostream>
#include "World.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ARROW_KEY 224
#define EXIT1 120
#define EXIT2 88
#define SAVE1 115
#define SAVE2 83
#define SPECIAL_ABILITY1 112
#define SPECIAL_ABILITY2 80
Controller::Controller()
{
	World* world;
}

void Controller::control()
{
	srand(time(NULL));
	std::cout << "Adam Sobczuk 188656" << std::endl;
	std::cout << "Welcome to the Jungle!" << std::endl;
	int height, width;
	char round = 'n';
	int input;
	std::cout << "If you want to start a new round enter n(N), if you want to read a state of game from a file enter r(R)" << std::endl;
	std::cin >> round;
	if (round == 'n' || round == 'N')
	{
		std::cout << "Enter height of the board" << std::endl;
		std::cin >> height;
		std::cout << "Enter width of the board" << std::endl;
		std::cin >> width;
		world = new World(height, width);
		world->initializePopulation();
	}
	if (round == 'r' || round == 'R')
		world = World::readWorld();
	world->drawWorld();
	while(true)
	{
		int humanMoveKey = 0, humanDirection = 0;
		input = _getwch();
		if (input == ARROW_KEY)
		{
			system("CLS");
			humanMoveKey = _getwch();
			switch (humanMoveKey)
			{
			case KEY_UP:
				humanDirection = 0;
				break;
			case KEY_RIGHT:
				humanDirection = 1;
				break;
			case KEY_DOWN:
				humanDirection = 2;
				break;
			case KEY_LEFT:
				humanDirection = 3;
				break;
			}
		}
		if (input == EXIT1 || input == EXIT2)
			break;
		if (input == SAVE1 || input == SAVE2)
		{
			world->saveWorld();
			break;
		}
		if (input == SPECIAL_ABILITY1 || input == SPECIAL_ABILITY2)
		{
			if(world->roundTurn == 0)
			world->roundTurn = 1;
			continue;
		}
		world->makeTurn(humanDirection);
	}
}