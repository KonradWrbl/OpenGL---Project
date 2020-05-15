#include "Sphere.h"
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <stdio.h>
#include "RESOURCE.H"

Sphere::Sphere(double r)
{
	this->setRadius(r);
}

double Sphere::getRadius()
{
	return this->radius;
}

void Sphere::draw(double x, double y, double z)
{
    double PI = 3.141593, alpha, beta, radius = this->getRadius(), gradation = 20;
    glTranslatef(x, y, z);
    for (alpha = 0.0; alpha < PI; alpha += PI / gradation)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (beta = 0.0; beta < 2.01 * PI; beta += PI / gradation)
        {
            x = radius * cos(beta) * sin(alpha);
            y = radius * sin(beta) * sin(alpha);
            z = radius * cos(alpha);
            glVertex3f(x, y, z);
            x = radius * cos(beta) * sin(alpha + PI / gradation);
            y = radius * sin(beta) * sin(alpha + PI / gradation);
            z = radius * cos(alpha + PI / gradation);
            glVertex3f(x, y, z);
        }
        glEnd();
    }
}

void Sphere::setRadius(double r)
{
	this->radius = r;
}
