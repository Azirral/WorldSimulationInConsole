#pragma once
#include "Plant.h"
#include <string>
class SosnowskysHogweed :
	public Plant
{
public:
	SosnowskysHogweed(World* world);
	Organism* factoryMethod(World* world);
	void action(int destinationX, int destinationY);
	void greedyFindAnimalFieldCoordinates(int x, int y, int* emptyX, int* emptyY);
	bool validateBorder(int x, int y);
	void draw();
	std::string returnOrganismAsString();
};

