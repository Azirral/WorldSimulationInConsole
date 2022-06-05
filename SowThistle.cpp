#include "SowThistle.h"
#include <iostream>
SowThistle::SowThistle(World* world) : Plant(world)
{
    age = 0;
    strength = 0;
    symbol = 'm';
}

void SowThistle::action(int destinationX, int destinationY) {

	// - sawing of sowthistle
	for (int i = 0; i < 3; i++) {
		int emptyX = -1, emptyY = -1;
		greedyFindEmptyFieldCoordinates(x, y, &emptyX, &emptyY);
		int number = std::rand() % 101;
		if (emptyX != -1 && emptyY != -1 && (number >= 0 && number <= 10)) {
			Organism* newBorn = this->factoryMethod(world);
			newBorn->place(emptyX, emptyY);
		}
	}
}

Organism* SowThistle::factoryMethod(World* world)
{
    return new SowThistle(world);
}

void SowThistle::draw()
{
	std::cout << symbol;
}

std::string SowThistle::returnOrganismAsString()
{
	return "SowThistle";
}

