#pragma once
#include "Cylinder.h";
#include "Cuboid.h";
#include "Sphere.h";

class Rover
{
public:
	Rover();
	~Rover();

	Cylinder *wheel1;
	Cylinder *wheel2;
	Cylinder *wheel3;
	Cylinder *wheel4;

	Cuboid *block1;
	Cuboid *block2;
	Cuboid *block3;

	Sphere *sphere;

	void draw();
};	

