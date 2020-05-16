#pragma once
#include "Cylinder.h";
#include "Cone.h";

class Rocket
{
public:
	Rocket();
	~Rocket();

	Cylinder* body;

	Cone* cone;

	void draw();
};

