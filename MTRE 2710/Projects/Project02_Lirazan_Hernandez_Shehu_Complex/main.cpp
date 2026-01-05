/*
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine Marie Lirazan
Group: Julian Hernandez, Hadassah Shehu
Final Project: Complex number class
*/

#include "Complex.h"
#include <iostream>
#include <fstream>
using namespace std;

const double pi = 3.141592;

int main() {
	// Requirement: Completed Complex class demonstrates correct calculation of z^2 + z
	Complex z1(1.4, 2.1), z2(-3.2, 4.6);
	cout << z1 * z2 + z1 / (z2 - z1) << endl << endl;

	// Requirement: Single-row text file created with magnitudes of complex numbers with -1.2 imaginary part
	ofstream FID("LabData.txt");

	// Requirement: Surface plot from complex numbers ranging between -1.5 to 0.5 real and -1.2 to 1.2 imaginary
	const int numRows = 24, numCols = 20;
	Complex z[numRows][numCols];

	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			z[row][col].setVals(2.0 / (numCols - 1) * col - 1.5, 2.4 / (numRows - 1) * row - 1.2);
			z[row][col] = z[row][col] * z[row][col] + z[row][col];
			FID << z[row][col].getMag() << " ";
		}
		FID << endl;
	}
	FID.close();
	return 0;
}
