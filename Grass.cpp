#include "Grass.h"
#include <iostream>
Grass::Grass(World* world) : Plant(world)
{
    age = 0;
    strength = 0;
    symbol = '|';
}
Organism* Grass::factoryMethod(World* world)
{
    return new Grass(world);
}

void Grass::draw()
{
    std::cout << symbol;
}

std::string Grass::returnOrganismAsString()
{
    return "Grass";
}