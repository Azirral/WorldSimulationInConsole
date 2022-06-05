#include "Fox.h"
#include <iostream>

Fox::Fox(World* world) : Animal(world)
{
	initiative = 7;
	age = 0;
	strength = 3;
	symbol = 'f';
}

void Fox::action(int destinationX, int destinationY)
{
	// - fox never moves to a stronger opponent cell
	if (world->getWorld()[destinationX][destinationY] != nullptr 
		&& this->strength < world->getWorld()[destinationX][destinationY]->strength)
	{
		int emptyX = -1, emptyY = -1;
		greedyFindEmptyFieldCoordinates(x, y, &emptyX, &emptyY);
		if (emptyX != -1 && emptyY != -1)
			Animal::action(emptyX, emptyY);
	}
	else
		Animal::action(destinationX, destinationY);
}

void Fox::collision(int destinationX, int destinationY)
{
	Animal::collision(destinationX, destinationY);
}

bool Fox::isSameSpecies(Organism* organism)
{
	return dynamic_cast<Fox*>(organism);
}

void Fox::draw()
{
	std::cout << symbol;
}

Organism* Fox::factoryMethod(World* world)
{
	return new Fox(world);
}

std::string Fox::returnOrganismAsString()
{
	return "Fox";
}
