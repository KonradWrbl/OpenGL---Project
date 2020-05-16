#pragma once
#include "Cylinder.h";
#include "Cuboid.h";
#include "Sphere.h";
#include "Cone.h";

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
	Cuboid* block4;

	Sphere *sphere;

	Cone* antenna;

	void draw();
};	

