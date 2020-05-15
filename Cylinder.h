#pragma once
class Cylinder
{
public:
	Cylinder(double, double);
	double getRadius();
	double getHeight();
	void draw(double, double, double, double, double, double);
private:
	double radius, height;
	void setRadius(double);
	void setHeight(double);
};

