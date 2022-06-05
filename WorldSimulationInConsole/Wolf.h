#pragma once
#include "Animal.h"
#include <string>
class Wolf :
    public Animal
{
public:
    Wolf(World* world);
    void action(int destinationX, int destinationY);
    void collision(int destinationX, int destinationY);
    void draw();
    bool isSameSpecies(Organism* organism);
    Organism* factoryMethod(World* world);
    std::string returnOrganismAsString();
};

