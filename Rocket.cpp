#include "Rocket.h"
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "RESOURCE.H"

Rocket::Rocket() {
	body = new Cylinder(50, 300);
	cone = new Cone(60, 90);
	leg1 = new Cuboid(15, 70, 30);
	leg2 = new Cuboid(15, 70, 30);
}

Rocket::~Rocket() {

}

void Rocket::draw() {
	glColor3d(0.713, 0.168, 0.086);
	leg1->draw(-205, 0, -160);

	glColor3d(0.713, 0.168, 0.086);
	leg2->draw(-205, 0, -270);

	glColor3d(0.6, 0.6, 0.6);
	body->draw(-200, 180, -200, 90, 1, 0, 0);
	
	glColor3d(0.713, 0.168, 0.086);
	cone->draw(0, 140, 0, -90, 1, 0, 0);
}