#pragma once
#include "Plant.h"
#include <string>
class Guarana :
    public Plant
{
public:
    Guarana(World* world);
    Organism* factoryMethod(World* world);
    void draw();
    std::string returnOrganismAsString();
};

