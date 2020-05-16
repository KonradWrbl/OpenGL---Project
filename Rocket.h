#pragma once
#include "Cylinder.h";
#include "Cone.h";
#include "Cuboid.h"

class Rocket
{
public:
	Rocket();
	~Rocket();

	Cylinder* body;
	Cuboid* leg1;
	Cuboid* leg2;

	Cone* cone;

	void draw();
};

