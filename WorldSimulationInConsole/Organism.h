#pragma once
#include "Point.h"
#include "World.h"
#include <string>
class Point;
class World;

class Organism
{
private:
	int x;
	int y;
	int numberOfTries;
public:
	void increaseStrength(Organism* organism);
	virtual void action(int destinationX, int destinationY);
	virtual void collision(int destinationX, int destinationY);
	virtual void draw();
	virtual int getLength();
	virtual int getInitiative();
	virtual Organism* factoryMethod(World* world);
	virtual void place(int x, int y);
	void greedyFindEmptyFieldCoordinates(int x, int y, int* emptyX, int* emptyY);
	Point* point;
	Organism(World* world);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getNumberOfTries();
	void setNumberOfTries(int numberOfTries);
	virtual std::string returnOrganismAsString() = 0;
public:
	int strength;
	int initiative;
	int age;
	char symbol;
	bool toBeMove;
	World* world;
	void initPoint();
};

