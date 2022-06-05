#include "Antelope.h"
#include <iostream>
#include <string>

Antelope::Antelope(World* world) : Animal(world)
{
	initiative = 4;
	age = 0;
	strength = 4;
	symbol = 'a';
}

void Antelope::action(int destinationX, int destinationY)
{
	Animal::action(destinationX, destinationY);
}

void Antelope::collision(int destinationX, int destinationY)
{
	Animal::collision(destinationX, destinationY);
}

void Antelope::performFight(int direction, int x, int y, int destinationX, int destinationY) 
{
	int chance = std::rand() % 2;
	if (chance == 0) //Antelope has to fight
		Animal::performFight(x, y, destinationX, destinationY);
	else {   //move antelope to a neighbouring free cell 	
		int emptyX = -1, emptyY = -1;
		greedyFindEmptyFieldCoordinates(x, y, &emptyX, &emptyY);
		if (emptyX != -1 && emptyY != -1)
		{
			std::string temp1, temp2;
			temp1 = this->returnOrganismAsString();
			std::cout << temp1 << " from (" << x << "," << y << ")" << " fled from a fight to " << temp2
				<< " at (" << emptyX << "," << emptyY << ")" << std::endl;
			temp2 = world->getWorld()[emptyX][emptyY]->returnOrganismAsString();
			Animal::action(emptyX, emptyY);
		}
	}
}

void Antelope::draw()
{
	std::cout << symbol;
}

bool Antelope::isSameSpecies(Organism* organism)
{
	return dynamic_cast<Antelope*>(organism);
}

int Antelope::getLength() {
	return 2;
}

Organism* Antelope::factoryMethod(World* world) 
{
	return new Antelope(world);
}

std::string Antelope::returnOrganismAsString()
{
	return "Antelope";
}