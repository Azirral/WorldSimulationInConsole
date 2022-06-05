#include "World.h"
#include <iostream>
#include <typeinfo>
#include <windows.h>
#include "Animal.h"
#include "Human.h"
#include "Belladonna.h"
#include "SosnowskysHogweed.h"
#include "Guarana.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Fox.h"
#include "Wolf.h"
#include "Sheep.h"
#include "SowThistle.h"
#include "Grass.h"
#include <algorithm>
#include <set>
#include <string>
#include <fstream>
#define POPULATION 0.1

World::World()
{
	this->sizeX = 0;
	this->sizeY = 0;
	round_number = 0;
	human_life = true;
	turtleMove = true;
	roundTurn = 0;
}

World::World(int sizeX, int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	std::vector<std::vector<Organism*>> w(sizeX, std::vector<Organism*>(sizeY));
	world = w;
}

int World::getSizeX()
{
	return this->sizeX;
}

int World::getSizeY()
{
	return this->sizeY;
}

bool compareInterval(int i1, int i2)
{
	return (i1 > i2);
}

void World::makeTurn(int humanDirection)
{
	std::set<int> initiativesSet;
	std::set<int> ageSet;
	// - initializing a set of initiatives from the board
	for (int i = 0; i < sizeX; i++)
		for (int j = 0; j < sizeY; j++)
			if (world[i][j] != nullptr)
				initiativesSet.insert(world[i][j]->initiative);

	// - sorting set of initiatives
	std::vector<int> initiatives;
	std::set<int>::iterator seetItVec = initiativesSet.begin();
	for (int i = 0; i < initiativesSet.size(); i++) {
		initiatives.insert(initiatives.begin() + i, *seetItVec);
		seetItVec++;
	}
	std::sort(initiatives.begin(), initiatives.end(), compareInterval);
	for (int i = 0; i < initiatives.size(); i++) {
		// - initiating a set of ages within a given age
			for (int k = 0; k < sizeX; k++)
				for (int l = 0; l < sizeY; l++)
					if (world[k][l] != nullptr && world[k][l]->initiative == initiatives[i])
						ageSet.insert(world[k][l]->age);
			std::vector<int> ages;
			// - sorting the set of ages
			std::set<int>::iterator seetAgVec = ageSet.begin();
			for (int m = 0; m < ageSet.size(); m++) {
				ages.insert(ages.begin() + m, *seetAgVec);
				seetAgVec++;
			}
			std::sort(ages.begin(), ages.end(), compareInterval);
			// - moving all of organisms within a given initiative and age
			for (int h = 0; h < ages.size(); h++)
			{
				for (int a = 0; a < sizeX; a++)
					for (int b = 0; b < sizeY; b++)
						if (world[a][b] != nullptr && world[a][b]->initiative == initiatives[i]
							&& world[a][b]->age == ages[h] && world[a][b]->toBeMove == true)
							move(a, b, world[a][b], humanDirection);
			}
	}
	// - updating the state of the game
	for (int k = 0; k < sizeX; k++)
		for (int l = 0; l < sizeY; l++) {
			if (world[k][l] != nullptr) {
				world[k][l]->age++;
				world[k][l]->toBeMove = true;
			}
		}
	drawWorld();
}

void World::drawWorld()
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
			if (world[i][j] != nullptr)
				world[i][j]->draw();
			else
				std::cout << "-";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "x(X) - exiting the game" << std::endl;
	std::cout << "s(S) - saving the game" << std::endl;
	std::cout << "p(P) - activating human special ability - antelope's speed" << std::endl;
	std::cout << "arrow keys - playing the game with a human and making the next turn" << std::endl;
}

bool World::move(int x, int y, Organism* organism, int humanDirection)
{
	organism->toBeMove = true;
	turtleMove = true;
	int destinationX = x, destinationY = y;
	this->calculateCoordinates(organism, &destinationX, &destinationY, humanDirection);
	bool vBorder = validateBorder(destinationX, destinationY),
		vCollision = validateCollision(destinationX, destinationY),
		vPlant = validatePlant(organism);
	if (!vBorder && organism->getNumberOfTries() < 20 && !validateHuman(organism)) {
		organism->setNumberOfTries(organism->getNumberOfTries() + 1);
		move(x, y, world[x][y], -1);
	}
	else if (organism->getNumberOfTries() >= 20) {
		organism->setNumberOfTries(0);
		return vBorder;
	}
	else if (vPlant)
		organism->action(-1, -1); // plant is not moving
	else if (vBorder && vCollision)  // if no border or collision issues
		organism->action(destinationX, destinationY);
	else if (vBorder) {
		if (turtleMove)
		{
			organism->collision(destinationX, destinationY);
		}
	}
	organism->setNumberOfTries(0);
	turtleMove = true;
	organism->toBeMove = false;
	return vBorder;
}

std::vector<std::vector<Organism*>> World::getWorld()
{
	return this->world;
}

void World::place(int x, int y, Organism* organism) {
	this->world[x][y] = organism;
}

void World::calculateCoordinates(Organism* organism, int* destinationX, int* destinationY, int humanDirection) {
	int length = organism->getLength(), direction = !validateHuman(organism) ? std::rand() % 4 : humanDirection; 
	if (length != 0)
	{
		switch (direction) {
		case 0:					// 0 means up
			*destinationX -= length;
			break;
		case 1:					// 1 means right
			*destinationY += length;
			break;
		case 2:					// 2 means down
			*destinationX += length;
			break;
		case 3:					// 3 means left
			*destinationY -= length;
			break;
		}
	}
	else
	{
		turtleMove = false;
	}
}

bool World::validateBorder(int x, int y) {
	return ((x >= 0 && x < this->sizeX) && (y >= 0 && y < this->sizeY));
}

bool World::validateCollision(int x, int y) {
	return validateBorder(x, y) && world[x][y] == nullptr;
}

bool World::validatePlant(Organism* organism)
{
	return dynamic_cast<Plant*>(organism) != nullptr;
}

bool World::validateHuman(Organism* organism)
{
	return dynamic_cast<Human*>(organism) != nullptr;
}


void World::initializePopulation()
{
	int numberOfOrganisms = floor(sizeX * sizeY * POPULATION);
	initializeOrganism('C');
	for (int i = 0; i < numberOfOrganisms; i++)
	{
		initializeOrganism(randomizeOrganisms());
	}
}

void World::initializeOrganism(char symbol)
{
	int randX, randY;
	getRandomCoordinates(&randX, &randY);
	Organism* org = this->chooseOrganism(symbol);
	org->place(randX, randY);
}

void World::getRandomCoordinates(int* randX, int* randY)
{
	do
	{
		*randX = rand() % sizeX;
		*randY = rand() % sizeY;
	} while (world[*randX][*randY] != nullptr);
}

Organism* World::chooseOrganism(char symbol)
{
	switch (symbol)
	{
	case 'C':
		return new Human(this);
		break;
	case 'w':
		return new Wolf(this);
		break;
	case 's':
		return new Sheep(this);
		break;
	case 'a':
		return new Antelope(this);
		break;
	case 'f':
		return new Fox(this);
		break;
	case 't':
		return new Turtle(this);
		break;
	case 'b':
		return new Belladonna(this);
		break;
	case 'H':
		return new SosnowskysHogweed(this);
		break;
	case 'm':
		return new SowThistle(this);
		break;
	case 'g':
		return new Guarana(this);
		break;
	case '|':
		return new Grass(this);
		break;
	default:
		break;
	}
}

char World::randomizeOrganisms()
{
	int tmp = rand() % 10;
	if (tmp == 0) return 'a';
	if (tmp == 1) return 'H';
	if (tmp == 2) return 'g';
	if (tmp == 3) return 'f';
	if (tmp == 4) return 'm';
	if (tmp == 5) return 's';
	if (tmp == 6) return '|';
	if (tmp == 7) return 'b';
	if (tmp == 8) return 'w';
	if (tmp == 9) return 't';
}

void World::saveWorld()
{
	std::ofstream fout;
	std::string filePath;
	std::cout << "Enter the name of the file in which you want to save the state of the world" << std::endl;
	std::cin >> filePath;
	filePath += ".txt";
	fout.open(filePath, std::ofstream::app);
	if (!fout.is_open())
		std::cout << "Error in creating file" << std::endl;
	else
	{
		fout << sizeX;
		fout << " ";
		fout << sizeY;
		fout << " ";
		for (int i = 0; i < sizeX; i++)
			for (int j = 0; j < sizeY; j++)
			{
				if (world[i][j] != nullptr)
				{
					fout << world[i][j]->symbol;
					fout << " ";
					fout << world[i][j]->getX();
					fout << " ";
					fout << world[i][j]->getY();
					fout << " ";
					fout << world[i][j]->strength;
					fout << " ";
					fout << world[i][j]->age;
					fout << " ";
				}
			}
	}
}

World* World::readWorld()
{
	std::ifstream fin;
	std::string filepath;
	std::cout << "Enter the name of the file" << std::endl;
	std::cin >> filepath;
	filepath += ".txt";
	fin.open(filepath);
	if (!fin.is_open())
	{
		std::cout << "Error in reading file" << std::endl;
		exit(0);
	}
	else
	{
		int posx, posy, s, a, tempX, tempY;
		char o;
		fin >> tempX;
		fin >> tempY;
		World* tempWorld = new World(tempX, tempY);
		while (!fin.eof())
		{
			fin >> o;
			fin >> posx;
			fin >> posy;
			fin >> s;
			fin >> a;
			Organism* temp = tempWorld->chooseOrganism(o);
			temp->place(posx, posy);
			temp->strength = s;
			temp->age = a;
		}
		return tempWorld;
	}
}