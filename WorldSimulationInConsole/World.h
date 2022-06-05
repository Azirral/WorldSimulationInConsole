#pragma once
#include "Organism.h"
#include <vector>
#include <algorithm>

class Organism;
class Human;

class World
{
private:
	bool validateBorder(int x, int y);
	bool validatePlant(Organism* organism);
	bool validateHuman(Organism* organism);
	void performActionForFox(Organism* organism, int direction, int x, int y, int destinationX, int destinationY);
public:
	World();
	World(int sizeX, int sizeY);
	int getSizeX();
	int getSizeY();
	void makeTurn(int humanDirection);
	void drawWorld();
	void calculateCoordinates(Organism* organism, int* destinationX, int* destinationY, int humanDirection);
	bool move(int x, int y, Organism* organism, int humanDirection);
	bool validateCollision(int x, int y);
	std::vector<std::vector<Organism*>> getWorld();
	void place(int x, int y, Organism* organism);
	void initializePopulation();
	void getRandomCoordinates(int* randX, int* randY);
	void initializeOrganism(char symbol);
	Organism* chooseOrganism(char symbol);
	char randomizeOrganisms();
	void saveWorld();
	static World* readWorld();
	int roundTurn;
protected:
	int sizeX;
	int sizeY;
	int round_number;
	bool human_life;
	bool turtleMove;
	std::vector<std::vector<Organism*>> world;
};