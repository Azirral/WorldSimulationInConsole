#include "Plant.h"
#include <iostream>
Plant::Plant(World* world) : Organism(world)
{
	Organism::initPoint();
	x = 0;
	y = 0;
}

Plant::Plant(World* world, int x, int y) : Organism(world), x(x), y(y)
{
	Organism::initPoint();
}

void Plant::action(int destinationX, int destinationY) {
	int emptyX = -1, emptyY = -1;
	greedyFindEmptyFieldCoordinates(x, y, &emptyX, &emptyY);
	int number = std::rand() % 101;
	// - sawing of plants
	if (emptyX != -1 && emptyY != -1 && (number >= 0 && number <= 10))
	{		
		Organism* newBorn = this->factoryMethod(world);
		newBorn->place(emptyX, emptyY);
		std::string temp = newBorn->returnOrganismAsString();
		std::cout << temp << " from (" << this->getX() << "," << this->getY() << ")" << " saw to (" << emptyX << "," << emptyY <<")" << std::endl;
	}
}

Organism* Plant::factoryMethod(World* world)
{
    return Organism::factoryMethod(world);
}

std::string Plant::returnOrganismAsString()
{
	return "Plant";
}
