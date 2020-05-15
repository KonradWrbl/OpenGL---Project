#include "Cuboid.h"
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <stdio.h>
#include "RESOURCE.H"

Cuboid::Cuboid(double w, double h, double d)
{
	this->setWidth(w);
	this->setHeight(h);
	this->setDepth(d);
}


double Cuboid::getWidth()
{
	return this->width;
}

double Cuboid::getDepth()
{
	return this->depth;
}

double Cuboid::getHeight()
{
	return this->height;
}

void Cuboid::draw(double x, double y, double z, double rotA, double rotX, double rotY, double rotZ)
{
	width = this->getWidth();
	height = this->getHeight();
	depth = this->getDepth();
	glRotated(rotA, rotX, rotY, rotZ);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3d(1, 0, 0);
	glVertex3d(x, y, z);
	glVertex3d(x, y + height, z);
	glVertex3d(x + width, y, z);
	glVertex3d(x + width, y + height, z);
	glVertex3d(x + width, y + height, z + depth);
	glVertex3d(x, y + height, z);
	glVertex3d(x, y + height, z + depth);
	glVertex3d(x, y, z + depth);
	glVertex3d(x + width, y + height, z + depth);
	glVertex3d(x + width, y, z + depth);
	glVertex3d(x + width, y, z);
	glVertex3d(x, y, z + depth);
	glVertex3d(x, y, z);
	glVertex3d(x, y + height, z);
	glEnd();
}

void Cuboid::setWidth(double w)
{
	this->width = w;
}

void Cuboid::setDepth(double d)
{
	this->depth = d;
}

void Cuboid::setHeight(double h)
{
	this->height = h;
}
