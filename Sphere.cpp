#include "Sphere.h"

Sphere::Sphere(double r)
{
	this->setRadius(r);
}

double Sphere::getRadius()
{
	return this->radius;
}

void Sphere::draw(double, double, double, double, double, double)
{
}

void Sphere::setRadius(double r)
{
	this->radius = r;
}
