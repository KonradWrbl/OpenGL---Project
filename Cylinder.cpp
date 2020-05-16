#include "Cylinder.h"
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <stdio.h>
#include "RESOURCE.H"

Cylinder::Cylinder() {}

Cylinder::Cylinder(double r, double h)
{
	this->setRadius(r);
	this->setHeight(h);
}

double Cylinder::getRadius()
{
	return this->radius;
}

double Cylinder::getHeight()
{
	return this->height;
}

void Cylinder::draw(double x, double y, double z, double rotA, double rotX, double rotY, double rotZ)
{
	double alpha, PI = 3.14, h = this->getHeight(), r = this->getRadius();

	glTranslatef(x, y, z);
	glPushMatrix();
	glRotated(rotA, rotX, rotY, rotZ);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0, 0, -h * 0.5);
	for (alpha = 0; alpha <= 2 * PI; alpha += PI / 20)
	{
		x = r * sin(alpha);
		y = r * cos(alpha);
		glVertex3d(x, y, -h * 0.5);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < 10; i++) {
		for (alpha = 0.0; alpha <= 2 * PI; alpha += PI / 20) {
			x = r * sin(alpha);
			y = r * cos(alpha);
			glVertex3d(x, y, -0.5 * h + i * h / 10);
			glVertex3d(x, y, -0.5 * h + (i + 1) * h / 10);
		}
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0, 0, 0.5 * h);
	for (alpha = 0; alpha >= -2 * PI; alpha -= PI / 20)
	{
		x = r * sin(alpha);
		y = r * cos(alpha);
		glVertex3d(x, y, 0.5 * h);
	}
	glEnd();
	glPopMatrix();
}


void Cylinder::setRadius(double r)
{
	this->radius = r;
}

void Cylinder::setHeight(double h)
{
	this->height = h;
}