#pragma once
#include "Animal.h"
#include <string>
class Sheep :
    public Animal
{
public:
    Sheep(World* world);
    void action(int destinationX, int destinationY);
    void collision(int destinationX, int destinationY);
    void draw();
    bool isSameSpecies(Organism* organism);
    Organism* factoryMethod(World* world);
    std::string returnOrganismAsString();
};

