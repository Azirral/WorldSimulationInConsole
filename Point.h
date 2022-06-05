#pragma once
#include "Organism.h"

class Point
{
public:
	Point(int x, int y);
	Point();
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
protected:
	int x;
	int y;
	//TODO: Check the 'recursive' include issue Organism organism;
};

