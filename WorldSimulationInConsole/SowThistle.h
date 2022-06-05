#pragma once
#include "Plant.h"
#include <string>
class SowThistle :
    public Plant
{
public:
    SowThistle(World* world);
    void action(int destinationX, int destinationY);
    Organism* factoryMethod(World* world);
    void draw();
    std::string returnOrganismAsString();
};

