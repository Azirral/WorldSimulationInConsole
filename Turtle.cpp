#include "Turtle.h"
#include <iostream>
Turtle::Turtle(World* world) : Animal(world)
{
	initiative = 1;
	age = 0;
	strength = 2;
	symbol = 't';
}
void Turtle::action(int destinationX, int destinationY)
{
	Animal::action(destinationX, destinationY);
}

void Turtle::collision(int destinationX, int destinationY)
{
	Animal::collision(destinationX, destinationY);
}

void Turtle::draw()
{
	std::cout << symbol;
}

int Turtle::getLength() {
	int chances[4] = { 1, 0, 0, 0 };
	int randomLength = std::rand() % 4;
	if (randomLength == 0)
		std::cout << "Turtle stayed at postition (" << this->getX() << "," << this->getY() <<")" << std::endl;
	return chances[randomLength];
}

bool Turtle::isSameSpecies(Organism* organism)
{
	return dynamic_cast<Turtle*>(organism);
}

Organism* Turtle::factoryMethod(World* world)
{
    return new Turtle(world);
}

std::string Turtle::returnOrganismAsString()
{
	return "Turtle";
}

