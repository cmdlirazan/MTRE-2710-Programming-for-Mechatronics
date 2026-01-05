/*
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine Marie Lirazan
Homework: 01 Bubble Sort
*/

#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()

using namespace std;

int main() {
	const int SIZE = 10; // Requirement: array of 10 values
	int arr[SIZE];

	srand(time(0)); // Requirement: Random values each run (seed w/ current time)

	// Requirement: Generate array with random values between 25-50
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 26 + 25; // (50-25 + 1) + 25 = range 25-50
	}

	// Print the initial array
	cout << "Initial array: ";
	for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
	cout << endl << endl;

	// Requirement: Bubble sort algorithm
	// Outer Loop: Each pass shortens the bubbling range by 1
	for (int j = SIZE - 1; j > 0; j--) { // specifies the end at which the bubbling can stop
		// Inner Loop: bubble the largest value up to end
		for (int i = 0; i < j; i++) {
			if (arr[i] > arr[i + 1]) {
				// Swap adjacent values if out of order
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
		// Requirement: Display array after each bubbling pass
		cout << "After pass " << (SIZE - j) << ": ";
		for (int k = 0; k < SIZE; k++) cout << arr[k] << " ";
		cout << endl;

	}
	// Requirement: Print final sorted array
	cout << endl << "Sorted array: ";
	for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
	cout << endl;

	return 0;
}