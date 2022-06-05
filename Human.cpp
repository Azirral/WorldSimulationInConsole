#include "Human.h"
#include <iostream>

Human::Human(World* world) : Animal(world)
{
	initiative = 4;
	age = 0;
	strength = 5;
	symbol = 'C';
}

void Human::action(int destinationX, int destinationY)
{
	Animal::action(destinationX, destinationY);
}

void Human::collision(int destinationX, int destinationY)
{
	Animal::collision(destinationX, destinationY);
}

void Human::draw()
{
	std::cout << symbol;
}

bool Human::isSameSpecies(Organism* organism)
{
	return dynamic_cast<Human*>(organism);
}

Organism* Human::factoryMethod(World* world)
{
	return new Human(world);
}

int Human::getLength() 
{
	// - human special ability - antelope's speed
	if (this->world->roundTurn < 4 && this->world->roundTurn != 0)
	{
		this->world->roundTurn++;
		return 2;
	}
	else if(this->world->roundTurn >= 4 && this->world->roundTurn <= 5)
	{
		int chances[4] = { 1, 1, 2, 2 };
		this->world->roundTurn++;
		if (this->world->roundTurn == 11)
			this->world->roundTurn = 0;
		return chances[std::rand() % 4];
	}
	return 1;
}

std::string Human::returnOrganismAsString()
{
	return "Human";
}