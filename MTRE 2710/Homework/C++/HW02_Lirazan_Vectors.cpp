/*
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine Marie Lirazan
Homework: 02 Vectors
*/

#include <iostream>   // Requirement: Input/Output
#include <fstream>    // Requirement: File I/O
#include <vector>     // Requirement: Use vectors
#include <cmath>      // Requirement: sin(), acos()
#include <iomanip>    // Requirement: setprecision()

using namespace std;

// 1. Fibonacci
void Problem01() {
    cout << "1. Fibonacci Numbers up to 1000: " << endl;

    // Requirement: Begin the vector with values 0 and 1
    vector<int> fib;
    fib.push_back(0); // Requirement: First value = 0
    fib.push_back(1); // Requirement: Second value = 1

    // Requirement: Loop to create Fibonacci numbers
    // Requirement: Each new is number is the sum of the previous two numbers
    // Requirement: Stop once the next number would exceed 1000
    while (true) {
        int next = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next > 1000) { // Requirement: Do not exceed 1000
            break;
        }
        fib.push_back(next);
    }

    // Requirement: Loop through the vector and display each value
    for (int i = 0; i < fib.size(); i++) {
        cout << fib[i] << " ";
    }
    cout << endl;

}

// 2. Turning Radii
void Problem02() {
    cout << endl << "2. Turning Radii: " << endl;

    vector<double> omega1, omega2, r;
    const int L = 28;   // Requirement: Axle track length in cm
    double o1 = 0.0, o2 = 0.0;

    // Requirement: Load data from file
    ifstream inData("HW01Data.txt");
    while (inData >> o1 >> o2) {
        omega1.push_back(o1);
        omega2.push_back(o2);
    }
    inData.close();

    // Requirement: Compute turning radius for each pair
    for (int i = 0; i < omega1.size(); i++) {
        double radius = (L * (omega1[i] + omega2[i])) / (2.0 * (omega2[i] - omega1[i]));
        r.push_back(radius);
        cout << "omega1 = " << omega1[i] << " rad/s, "
            << "omega2 = " << omega2[i] << " rad/s, "
            << "Turning Radius = " << radius << " cm" << endl;
    }
}

// 3: Sine Values
void Problem03() {
    cout << endl << "3. X and Sin(x) Values: " << endl;

    // Requirement: Define pi constant since M_PI is not standard
    const double PI = 3.141592653589793;

    // Requirement: Create a vector of 10 evenly spaced points between -π and π
    vector<double> xValues;
    int n = 10;
    double start = -PI, end = PI;
    double step = (end - start) / (n - 1); // spacing between points

    for (int i = 0; i < n; i++) {
        xValues.push_back(start + i * step);
    }

    // Requirement: Create another vector containing sine values at each x
    vector<double> yValues;
    for (int i = 0; i < n; i++) {
        yValues.push_back(sin(xValues[i]));
    }

    // Requirement: Display the (x, y) pairs
    for (int i = 0; i < n; i++) {
        cout << "(" << xValues[i] << ", " << yValues[i] << ")" << endl;
    }

}

int main() {
    Problem01();
    cout << endl;

    Problem02();
    cout << endl;

    Problem03();
    cout << endl;

    return 0;
}
