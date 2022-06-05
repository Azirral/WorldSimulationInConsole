#include "Wolf.h"
#include <iostream>
Wolf::Wolf(World* world) : Animal(world)
{
    initiative = 5;
    age = 0;
    strength = 9;
    symbol = 'w';
}
void Wolf::action(int destinationX, int destinationY)
{
    Animal::action(destinationX, destinationY);                     
}

void Wolf::collision(int destinationX, int destinationY)
{
    Animal::collision(destinationX, destinationY);
}

void Wolf::draw()
{
    std::cout << symbol;
}

bool Wolf::isSameSpecies(Organism* organism)
{
    return dynamic_cast<Wolf*>(organism);
}

Organism* Wolf::factoryMethod(World* world)
{
    return new Wolf(world);
}

std::string Wolf::returnOrganismAsString()
{
    return "Wolf";
}