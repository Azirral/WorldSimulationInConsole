#pragma once
#include "Plant.h"
#include <string>
class Grass :
    public Plant
{
public:
    Grass(World* world);
    Organism* factoryMethod(World* world);
    void draw();
    std::string returnOrganismAsString();
};

