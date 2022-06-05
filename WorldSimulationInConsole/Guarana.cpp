#include "Guarana.h"
#include <iostream>
Guarana::Guarana(World* world) : Plant(world)
{
    age = 0;
    strength = 0;
    symbol = 'g';
}

Organism* Guarana::factoryMethod(World* world)
{
    return new Guarana(world);
}
void Guarana::draw()
{
    std::cout << symbol;
}

std::string Guarana::returnOrganismAsString()
{
    return "Guarana";
}
