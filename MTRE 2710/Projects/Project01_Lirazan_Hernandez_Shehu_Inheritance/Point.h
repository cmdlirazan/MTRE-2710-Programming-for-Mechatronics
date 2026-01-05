#pragma once
#include <iostream>
#include <cmath>

class Point {
	double x, y;

public:
	Point();
	void setValues(double xVal, double yVal);
	double getXvalue();
	double getYvalue();
	void display();
	double dist(Point p);
};