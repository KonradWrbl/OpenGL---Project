#pragma once
class Sphere
{
public:
	Sphere(double);
	double getRadius();
	void draw(double, double, double, double, double, double);
private:
	double radius;
	void setRadius(double);
};

