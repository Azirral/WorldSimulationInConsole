#include "Animal.h"
#include <iostream>
#include "Plant.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "SosnowskysHogweed.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Fox.h"
#include "Sheep.h"
#include "Wolf.h"

Animal::Animal(World* world) : Organism(world)
{
	Organism::initPoint();
	length = 1;
	x = 0;
	y = 0;
}

Animal::Animal(World* world, int x, int y) : Organism(world), x(x), y(y)
{
	Organism::initPoint();
}

void Animal::action(int destinationX, int destinationY)
{
	this->point->SetX(destinationX);
	this->point->SetY(destinationY);
	world->place(destinationX, destinationY, this);
	world->place(this->getX(), this->getY(), nullptr);
	this->setX(destinationX);
	this->setY(destinationY);
}

void Animal::collision(int destinationX, int destinationY)
{
	if (isPlant(world->getWorld()[destinationX][destinationY])) // if neighbourgh is plant
		performActionForPlant(this, this->getX(), this->getY(), destinationX, destinationY);
	else // if neighbourgh is animal 
	{
		if (this->isSameSpecies(world->getWorld()[destinationX][destinationY])) // if of the same type (then breed) 
			performActionForBreed(this, this->getX(), this->getY());
		else // not of the same type
			performFight(this->getX(), this->getY(), destinationX, destinationY);
	}
}

//TODO: Header - begin 
bool Animal::isPlant(Organism* organism) {
	return dynamic_cast<Plant*>(organism) != nullptr;
}

void Animal::performActionForPlant(Organism* organism, int x, int y, int destinationX, int destinationY)
{
	/*
		Instead of calling the plant's collision method, the action is handled in the
		performActionForPlant because the collision action is strictly related to the movement,
		when the destination field is already taken.
	*/
	// death condition
	std::string temp1, temp2;
	temp1 = this->returnOrganismAsString();
	temp2 = world->getWorld()[destinationX][destinationY]->returnOrganismAsString();
	if (isPoisonousPlant(world->getWorld()[destinationX][destinationY])) 
	{
		std::cout << temp1 << " from (" << x << "," << y << ")" << " ate a poisonous plant " << temp2
			<< " at (" << destinationX << "," << destinationY << ")" << std::endl;
		this->world->place(this->getX(), this->getY(), nullptr);					
		this->world->place(destinationX, destinationY, nullptr);
	}
	// increase strength condition
	else if (isStrengtheningPlant(world->getWorld()[destinationX][destinationY]))
	{
		std::cout << temp1 << " from (" << x << "," << y << ")" << " ate " << temp2
			<< " at (" << destinationX << "," << destinationY << ")" << std::endl;
		this->action(destinationX, destinationY);
		this->increaseStrength(this);
	}
	// do nothing means perform move (eating grass and sow thistles)
	else
	{
		std::cout << temp1 << " from (" << x << "," << y << ")" << " ate " << temp2
			<< " at (" << destinationX << "," << destinationY << ")" << std::endl;
		this->action(destinationX, destinationY);
	}
}

bool Animal::isPoisonousPlant(Organism* organism)
{
	return dynamic_cast<Belladonna*>(organism) != nullptr || dynamic_cast<SosnowskysHogweed*>(organism) != nullptr;
}

bool Animal::isStrengtheningPlant(Organism* organism)
{
	return dynamic_cast<Guarana*>(organism) != nullptr;
}

void Animal::performActionForBreed(Organism* organism, int x, int y)
{
	// - breeding of animals
	int emptyX = -1, emptyY = -1;
	greedyFindEmptyFieldCoordinates(x, y, &emptyX, &emptyY);
	if (emptyX != -1 && emptyY != -1) {
		Organism* newBorn = this->factoryMethod(world);
		std::string temp = newBorn->returnOrganismAsString();
		std::cout << temp << " multiplied to (" << emptyX << "," << emptyY << ")" << std::endl;
		newBorn->action(emptyX, emptyY);
	}
}

void Animal::draw()
{
}

void Animal::performFight(int x, int y, int destinationX, int destinationY)
{
	std::string temp1, temp2;
	temp1 = this->returnOrganismAsString();
	temp2 = world->getWorld()[destinationX][destinationY]->returnOrganismAsString();
	if (this->strength >= this->world->getWorld()[destinationX][destinationY]->strength)
	{
		this->action(destinationX, destinationY);
		std::cout << temp1 << " from (" << x << "," << y << ")" << " killed " << temp2
			<< " at (" << destinationX << "," << destinationY << ")" << std::endl;
	}
	else if (dynamic_cast<Turtle*>(this->world->getWorld()[destinationX][destinationY]) != nullptr
		&& this->world->getWorld()[x][y]->strength >= 5)
	{
		this->action(destinationX, destinationY);
		std::cout << temp1 << " from (" << x << "," << y << ")" << " fend of the attacker " << temp2
			<< " from (" << destinationX << "," << destinationY << ")" << std::endl;
	}
	else
	{
		std::cout << temp1 << " from (" << x << "," << y << ")" << " was killed by " << temp2
			<< " from (" << destinationX << "," << destinationY << ")" << std::endl;
		this->world->getWorld()[x][y] = nullptr;
	}
}

int Animal::getLength() {
	return Organism::getLength();
}

Organism* Animal::factoryMethod(World* world) {
	return Organism::factoryMethod(world);
}

std::string Animal::returnOrganismAsString()
{
	return "Animal";
}
