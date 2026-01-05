#include "Point.h"
#include <iostream>

using namespace std;

Point::Point() {
	x = y = 0;
}

void Point::setValues(double xVal, double yVal) {
	x = xVal;
	y = yVal;
}

double Point::getXvalue() {
	return x;
}

double Point::getYvalue() {
	return y;
}
void Point::display() {
	cout << "(" << x << "," << y << ")" << endl;
}

double Point::dist(Point p) {
	return sqrt((abs(pow(x - p.x, 2)) + (abs(pow(y - p.y, 2)))));
}