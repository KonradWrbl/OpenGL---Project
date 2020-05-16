#pragma once
class Cone
{
public:
	Cone();
	Cone(double, double);
	~Cone();

	double getRadius();
	double getHeight();

	void draw(double, double, double, double = 0, double = 0, double = 0, double = 0);
private:
	double radius, height;
	void setRadius(double);
	void setHeight(double);
};

