#pragma once
#include "Animal.h"
#include <string>
class Human :
    public Animal
{
public:
    Human(World* world);
    void action(int destinationX, int destinationY);
    void collision(int destinationX, int destinationY);
    void draw();
    bool isSameSpecies(Organism* organism);
    Organism* factoryMethod(World* world);
    int getLength();
    std::string returnOrganismAsString();
};

    