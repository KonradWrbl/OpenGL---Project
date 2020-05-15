#pragma once
class Cuboid
{
public:
	Cuboid(double, double, double);
	double getWidth();
	double getDepth();
	double getHeight();
	void draw(double, double, double);
private:
	double width, depth, height;
	void setWidth(double);
	void setDepth(double);
	void setHeight(double);
};

