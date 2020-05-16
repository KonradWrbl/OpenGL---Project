#include "Rover.h"
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "RESOURCE.H"

Rover::Rover() {
	wheel1 = new Cylinder(20, 10);
	wheel2 = new Cylinder(20, 10);
	wheel3 = new Cylinder(20, 10);
	wheel4 = new Cylinder(20, 10);

	block1 = new Cuboid(100, 30, 50);
	block2 = new Cuboid(60, 30, 50);
	block3 = new Cuboid(60, 10, 10);
	block4 = new Cuboid(5, 60, 5);

	sphere = new Sphere(20);

	antenna = new Cone(40, 40);
}

Rover::~Rover() {

}

void Rover::draw() {
	glColor3d(0.2, 0.2, 0.2);
	wheel1->draw(0, 0, 0);
	wheel2->draw(0, 0, 50);
	wheel3->draw(100, 0, 0);
	wheel4->draw(0, 0, -50);

	glColor3d(0.321, 0.101, 0.6);
	block1->draw(-100, 0, 0);
	glColor3d(0.321, 0.101, 0.6);
	block2->draw(-100, 30, 0);
	glColor3d(0.321, 0.101, 0.6);
	block3->draw(0, 30, 22.5);
	glColor3d(1, 1, 1);
	block4->draw(-100, 60, 22.5);
	glColor3d(0.941, 0.866, 0.098);
	sphere->draw(0, 30, 25);

	glColor3d(0.8, 0.8, 0.8);
	antenna->draw(-100, 110, -35, 35, 1, 0, 0);
}