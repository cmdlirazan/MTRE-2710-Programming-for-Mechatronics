#include <iostream>
#include <cmath>
#include "Shapes.h"
using namespace std;

// POLYGON
Polygon::Polygon() {
    numPoints = 0;
    shapeName = "Polygon";
}

double Polygon::pointLineDist(int p, int pL1, int pL2) {
    double x0 = vertex[p].getXvalue(), y0 = vertex[p].getYvalue(),
        x1 = vertex[pL1].getXvalue(), y1 = vertex[pL1].getYvalue(),
        x2 = vertex[pL2].getXvalue(), y2 = vertex[pL2].getYvalue();
    return abs((y2 - y1) * x0 - (x2 - x1) * y0 + x2 * y1 - y2 * x1) / sqrt((y2 - y1) * (y2 - y1) + (x2 -
        x1) * (x2 - x1));
}

void Polygon::setPoints(double x[], double y[], int numP) {
    numPoints = numP;
    for (int i = 0; i < numPoints; i++) {
        vertex[i].setValues(x[i], y[i]);
    }
}

void Polygon::displayPoints() {
    cout << "Points for " << shapeName << ":" << endl;
    for (int i = 0; i < numPoints; i++) {
        vertex[i].display();
    }
}

double Polygon::getPerimeter() {
    double P = 0;
    for (int i = 0; i < numPoints; i++) {
        P += vertex[i].dist(vertex[(i + 1) % numPoints]);
    }
    return P;
}

// TRIANGLE
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    numPoints = 3;
    shapeName = "triangle";
    vertex[0].setValues(x1, y1);
    vertex[1].setValues(x2, y2);
    vertex[2].setValues(x3, y3);
}

double Triangle::getArea() {
    return vertex[1].dist(vertex[2]) * pointLineDist(0, 1, 2) / 2;
}

// EQUILATERAL TRIANGLE
EQ_Triangle::EQ_Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : Triangle(x1, y1, x2, y2, x3, y3) {
    shapeName = "equilateral triangle";

    double side1 = vertex[0].dist(vertex[1]);
    double side2 = vertex[1].dist(vertex[2]);
    double side3 = vertex[2].dist(vertex[0]);
    double tolerance = 1e-6;

    if (abs(side1 - side2) > tolerance || abs(side2 - side3) > tolerance) {
        cout << "Triangle is not equilateral" << endl;
    }
}

// RIGHT TRIANGLE
R_Triangle::R_Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : Triangle(x1, y1, x2, y2, x3, y3) {
    shapeName = "right Triangle";

    double side1 = vertex[0].dist(vertex[1]);
    double side2 = vertex[1].dist(vertex[2]);
    double side3 = vertex[2].dist(vertex[0]);

    double a = side1, b = side2, c = side3;
    if (b > a && b > c) {
        double temp = a;
        a = b;
        b = temp;
    }
    if (c > a) {
        double temp = a;
        a = c;
        c = temp;
    }

    double tolerance = 1e-6;
    if (abs(a * a - (b * b + c * c)) > tolerance) {
        cout << "Triangle is not right" << endl;
    }
}

// PARALLELOGRAM
Parallelogram::Parallelogram(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4) {
    numPoints = 4;
    shapeName = "parallelogram";

    vertex[0].setValues(x1, y1);
    vertex[1].setValues(x2, y2);
    vertex[2].setValues(x3, y3);
    vertex[3].setValues(x4, y4);

    double side1 = vertex[0].dist(vertex[1]); // Side 0-1
    double side2 = vertex[1].dist(vertex[2]); // Side 1-2
    double side3 = vertex[2].dist(vertex[3]); // Side 2-3
    double side4 = vertex[3].dist(vertex[0]); // Side 3-0
    double tolerance = 1e-6;

    if (abs(side1 - side3) > tolerance || abs(side2 - side4) > tolerance) {
        cout << "Opposite sides are not parallel" << endl;
    }
}

double Parallelogram::getArea() {
    return vertex[1].dist(vertex[2]) * pointLineDist(0, 1, 2);
}

// RECTANGLE
Rectangle::Rectangle(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
    : Parallelogram(x1, y1, x2, y2, x3, y3, x4, y4) {
    shapeName = "rectangle";

    double v1x = vertex[1].getXvalue() - vertex[0].getXvalue();
    double v1y = vertex[1].getYvalue() - vertex[0].getYvalue();
    double v2x = vertex[3].getXvalue() - vertex[0].getXvalue();
    double v2y = vertex[3].getYvalue() - vertex[0].getYvalue();

    double dotProduct = v1x * v2x + v1y * v2y;
    double tolerance = 1e-6;

    static bool printed = false;
    if (abs(dotProduct) > tolerance && !printed) {
        cout << "Angles not right" << endl;
        printed = true;
    }
}