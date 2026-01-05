#pragma once
#include"Point.h"
#include<string>
using namespace std;

class Polygon {
protected:
	Point vertex[10];
	int numPoints;
	string shapeName;

public:
	Polygon();
	void setPoints(double x[], double y[], int numP);
	void displayPoints();
	double getPerimeter();
	double pointLineDist(int p, int pL1, int pL2);
};

class Triangle : public Polygon {
public:
	Triangle(double x1, double y1, double x2, double y2,
		double x3, double y3);
	double getArea();
};

class EQ_Triangle : public Triangle {
public:
	EQ_Triangle(double x1, double y1, double x2,
		double y2, double x3, double y3);
};

class R_Triangle : public Triangle {
public:
	R_Triangle(double x1, double y1, double x2,
		double y2, double x3, double y3);
};

class Parallelogram : public Polygon {
public:
	Parallelogram(double x1, double y1, double x2,
		double y2, double x3, double y3,
		double x4, double y4);
	double getArea();
};

class Rectangle : public Parallelogram {
public:
	Rectangle(double x1, double y1, double x2,
		double y2, double x3, double y3,
		double x4, double y4);
};