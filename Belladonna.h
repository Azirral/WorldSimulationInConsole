#pragma once
#include "Plant.h"
#include <string>
class Belladonna :
    public Plant
{
public:
    Belladonna(World* world);
    Organism* factoryMethod(World* world);
    void draw();
    std::string returnOrganismAsString();
};

