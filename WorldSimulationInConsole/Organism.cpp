#include "Organism.h"
#include <iostream>

Organism::Organism(World* world) : world(world)
{
	initiative = 0;
	age = 0;
	strength = 0;
	symbol = '|';
	toBeMove = true;
}

void Organism::action(int destinationX, int destinationY)
{
	place(x, y);
}

void Organism::collision(int destinationX, int destinationY)
{
}

void Organism::draw()
{
	
}

int Organism::getLength() {
	return 1;
}


int Organism::getInitiative()
{
	return this->initiative;
}

int Organism::getNumberOfTries() {
	return numberOfTries;
}

void Organism::setNumberOfTries(int numberOfTries) {
	this->numberOfTries = numberOfTries;
}

Organism* Organism::factoryMethod(World* world) 
{
	return nullptr;
}

void Organism::place(int x, int y) {
	world->place(x, y, this);
	this->x = x;
	this->y = y;
}

void Organism::greedyFindEmptyFieldCoordinates(int x, int y, int* emptyX, int* emptyY) {
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++) {
			if ((i != 0 || j != 0) && world->validateCollision(this->getX() + i, this->getY() + j)) {
				*emptyX = this->getX() + i;
				*emptyY = this->getY() + j;
				return;
			}
		}
}

void Organism::setX(int x)
{
	this->x = x;
}

void Organism::setY(int y)
{
	this->y = y;
}

int Organism::getX()
{
	return this->x;
}

int Organism::getY()
{
	return this->y;
}

void Organism::increaseStrength(Organism* organism)
{
	organism->strength = organism->strength + 3;
}

void Organism::initPoint() {
	this->point = new Point();
	this->point->SetX(this->x);
	this->point->SetY(this->y);
}

std::string Organism::returnOrganismAsString()
{
	return "Organism";
}

