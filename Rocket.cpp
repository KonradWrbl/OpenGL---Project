#include "Rocket.h"
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "RESOURCE.H"

Rocket::Rocket() {
	body = new Cylinder(50, 150);
	cone = new Cone(50, 50);
}

Rocket::~Rocket() {

}

void Rocket::draw() {
	glColor3d(0.6, 0.6, 0.6);
	body->draw(-200, 0, -100, 90, 1, 0, 0);
	
	glColor3d(1, 1, 1);
	cone->draw(-200, 0, -100, -90, 1, 0, 0);
}