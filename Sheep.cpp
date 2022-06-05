#include "Sheep.h"
#include <iostream>
Sheep::Sheep(World* world) : Animal(world)
{
    initiative = 4;
    age = 0;
    strength = 4;
    symbol = 's';
}
void Sheep::action(int destinationX, int destinationY)
{
    Animal::action(destinationX, destinationY);
}

void Sheep::collision(int destinationX, int destinationY)
{
    Animal::collision(destinationX, destinationY);
}

void Sheep::draw()
{
    std::cout << symbol;
}

bool Sheep::isSameSpecies(Organism* organism)
{
    return dynamic_cast<Sheep*>(organism);
}

Organism* Sheep::factoryMethod(World* world)
{
    return new Sheep(world);
}

std::string Sheep::returnOrganismAsString()
{
    return "Sheep";
}
