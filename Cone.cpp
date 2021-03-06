#include "Cone.h"
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <stdio.h>
#include "RESOURCE.H"

Cone::Cone() {}

Cone::~Cone() {}

Cone::Cone(double r, double h) {
	this->setRadius(r);
	this->setHeight(h);
}

double Cone::getRadius()
{
	return this->radius;
}

double Cone::getHeight()
{
	return this->height;
}

void Cone::setRadius(double r)
{
	this->radius = r;
}

void Cone::setHeight(double h)
{
	this->height = h;
}

void Cone::draw(double x, double y, double z, double rotA, double rotX, double rotY, double rotZ)
{
	double alpha, PI = 3.14, h = this->getHeight(), r = this->getRadius();
	
	glTranslatef(x, y, z);
	glPushMatrix();
	glRotated(rotA, rotX, rotY, rotZ);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.0f, h);
	for (int angle = 0; angle < 360; angle++) {
		glVertex3f(sin(angle) * r, cos(angle) * r, 0);
	}
	glEnd();

	//base
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.0f, 0.0f);
	for (int angle = 0; angle < 360; angle++) {
		glNormal3f(0, -1, 0);
		glColor3d(0.9f, 0.9f, 0.9f);
		glVertex3f(sin(angle) * r, cos(angle) * r, 0.0f);
	}
	glEnd();
	glPopMatrix();
}