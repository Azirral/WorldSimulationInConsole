#pragma once
#include "Organism.h"
#include <string>

class Plant :
    public Organism
{
protected:
    int x;
    int y;
public:
    Plant(World* world);
    Plant(World* world, int x, int y);
    void action(int destinationX, int destinationY);
    Organism* factoryMethod(World* world);
    std::string returnOrganismAsString();
};

