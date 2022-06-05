#include "Belladonna.h"
#include <iostream>
Belladonna::Belladonna(World* world) : Plant(world)
{
	age = 0;
	strength = 99;
	symbol = 'b';
}
Organism* Belladonna::factoryMethod(World* world)
{
	return new Belladonna(world);
}

void Belladonna::draw()
{
	std::cout << symbol;
}

std::string Belladonna::returnOrganismAsString()
{
	return "Belladonna";
}