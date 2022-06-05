#pragma once
#include "Organism.h"
#include <string>
class Animal :
    public Organism
{
protected:
    int x;
    int y;
    int length;
public:
    Animal(World* world);
    Animal(World* world, int x, int y);
    virtual void action(int destinationX, int destinationY);
    virtual void collision(int destinationX, int destinationY);
    virtual void performFight(int x, int y, int destinationX, int destinationY);
    virtual void draw();
    virtual int getLength();
    virtual bool isSameSpecies(Organism* organism) = 0;
    virtual Organism* factoryMethod(World* world);
    bool isPlant(Organism* organism);
    void performActionForPlant(Organism* organism, int x, int y, int destinationX, int destinationY);
    bool isPoisonousPlant(Organism* organism);
    bool isStrengtheningPlant(Organism* organism);
    void performActionForBreed(Organism* organism, int x, int y); 
    std::string returnOrganismAsString();
};

