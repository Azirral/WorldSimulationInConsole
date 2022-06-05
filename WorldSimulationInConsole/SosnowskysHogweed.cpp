#include "SosnowskysHogweed.h"
#include "Animal.h"
#include <iostream>

SosnowskysHogweed::SosnowskysHogweed(World* world) : Plant(world)
{
    age = 0;
    strength = 10;
    symbol = 'H';
}

Organism* SosnowskysHogweed::factoryMethod(World* world)
{
    return new SosnowskysHogweed(world);
}

void SosnowskysHogweed::action(int destinationX, int destinationY)
{
    Plant::action(destinationX, destinationY);
	int emptyX = -1, emptyY = -1;
	greedyFindAnimalFieldCoordinates(this->getX(), this->getY(), &emptyX, &emptyY);
}

void SosnowskysHogweed::greedyFindAnimalFieldCoordinates(int x, int y, int* emptyX, int* emptyY) 
{
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++) 
			if (validateBorder(x + i, y + j) && dynamic_cast<Animal*>(this->world->getWorld()[x + i][y + j]) != nullptr)
			{
				std::string temp = world->getWorld()[x + i][y + j]->returnOrganismAsString();
				std::string temp2 = this->returnOrganismAsString();
				std::cout << temp2 << " from (" << this->getX() << "," << this->getY() << ")" << " killed " << temp
					<< " at (" << x + i << "," << y + j << ")" << std::endl;
				this->world->place(x + i, y + j, nullptr);
			}
}
bool SosnowskysHogweed::validateBorder(int x, int y) {
	return ((x >= 0 && x < this->world->getSizeX()) && (y >= 0 && y < this->world->getSizeY()));
}
void SosnowskysHogweed::draw()
{
	std::cout << symbol;
}

std::string SosnowskysHogweed::returnOrganismAsString()
{
	return "SosnowskysHogweed";
}

