#include "Terrain.h"
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <stdio.h>
#include "RESOURCE.H"

Terrain::Terrain(double x, double y)
{
	setX(x);
	setY(y);
}

double Terrain::getX()
{
	return this->x;
}

double Terrain::getY()
{
	return this->y;
}

void Terrain::draw()
{
    double PI = 3.141593, alpha, beta, radius = 10000, gradation = 20, x, y, z;
    glTranslatef(0, -60, 0);
    glRotated(90, 1, 0, 0);
    glScalef(.1, .1, .1);
    glColor3d(0.850, 0.705, 0.627);
    for (alpha = 0.0; alpha < PI; alpha += PI / gradation)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (beta = 0.0; beta < 2.01 * PI; beta += PI / gradation)
        {
            x = radius * cos(beta);
            y = radius * sin(beta);
            z = radius * cos(x) * sin(y);
            glVertex3f(x, y, z/10);
            x = radius * cos(beta) * sin(alpha + PI / gradation);
            y = radius * sin(beta) * sin(alpha + PI / gradation);
            z = radius * cos(x + PI / gradation) * sin(y + PI / gradation);
            glVertex3f(x, y, z/10);
        }
        glEnd();
    }
}

void Terrain::setX(double x)
{
	this->x = x;
}

void Terrain::setY(double y)
{
	this->y = y;
}
