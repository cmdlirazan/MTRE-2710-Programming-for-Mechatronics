/*
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine Marie Lirazan
Group: Julian Hernandez, Hadassah Shehu
Final Project: Displaying Fractals from the Mandelbrot Set
*/

# include <iostream>
# include <fstream>
# include "Complex.h"
using namespace std;

int main() {
	// Requirement: Read real/imaginary domain bounds from file
	ifstream domain("domain.txt");
	ofstream nFile("nFile.txt");

	// Requirement: Initialize Complex numbers for z0 and z
	Complex z0, z;

	// Requirement: Define domain resolution and max iterations
	double numRows = 500, numCols = 500, nMax = 5000, row, col, n;
	double realMin, realMax, imagMin, imagMax;

	// Requirement: Read domain bounds from domain.txt
	domain >> realMin; domain >> realMax; domain >> imagMin; domain >> imagMax;
	cout << realMin << " ";
	cout << realMax << " ";
	cout << imagMin << " ";
	cout << imagMax << endl;

	// Requirement: Loop through imaginary values (rows)
	for (row = 0; row < numRows; row++) {
		// Requirement: Loop through real values (columns)
		for (col = 0; col < numCols; col++) {

			// Requirement: Set z0 based on linear mapping from indices to real/imag values
			z0.setVals((realMax - realMin) * col / (numCols - 1.0) + realMin, (imagMax - imagMin) * row / (numRows - 1.0) + imagMin);
			
			// Requirement: Initialize z and iteration counter
			z = z0; n = 0;

			// Requirement: Innermost while loop to determine Mandelbrot set membership
			while (n < nMax && z.getMag() < 2) {
				z = z * z + z0;
				n++;
			}

			// Requirement: Write n value for each real/imag pair to file
			nFile << n << " ";
		}

		// Requirement: End line for each row to form a matrix
		nFile << endl;
	}

	// Requirement: Close files
	domain.close(); nFile.close();

	return 0;
}