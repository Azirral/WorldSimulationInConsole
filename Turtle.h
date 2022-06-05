#pragma once
#include "Animal.h"
#include <string>
class Turtle :
    public Animal
{
public:
    Turtle(World* world);
    void action(int destinationX, int destinationY);
    void collision(int destinationX, int destinationY);
    void draw();
    int getLength();
    bool isSameSpecies(Organism* organism);
    Organism* factoryMethod(World* world);
    std::string returnOrganismAsString();
};

