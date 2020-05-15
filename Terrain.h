#pragma once
class Terrain
{
public:
	Terrain(double, double);
	double getX();
	double getY();
	void draw();
private:
	double x, y;
	void setX(double);
	void setY(double);
};

