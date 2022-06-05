#pragma once
#include "Animal.h"
#include <string>
class Antelope :
    public Animal
{
public:
    Antelope(World* world);
    void action(int destinationX, int destinationY);
    void collision(int destinationX, int destinationY);
    void performFight(int direction, int x, int y, int destinationX, int destinationY);
    void draw();
    bool isSameSpecies(Organism* organism);
    int getLength();
    Organism* factoryMethod(World* world);
    std::string returnOrganismAsString() override;
};

