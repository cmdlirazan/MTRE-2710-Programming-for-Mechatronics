/*
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine Marie Lirazan
Homework: 01 Random Number Guessing Game
*/

#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()

using namespace std;

int main() {
	srand(time(0)); // Requirement: Seed sandom number generator

	char playAgain = 'y';

	cout << "Guess the Number!\n\n";

	// Game Loop
	while (playAgain == 'y' || playAgain == 'Y') {
		int number = rand() % 100 + 1; // Requirement: Computer generates a random number 1-100
		int guess;

		// Requirement: Loop unter player guesses correctly
		do {
			cout << "Enter your guess: ";
			cin >> guess; // Requirement: Player inputs guess

			// Requirement: Feedback
			if (guess > number) cout << "Too high!\n";
			else if (guess < number) cout << "Too low!\n";
			else cout << "\nCorrect! You guessed the number.\n";

		} while (guess != number); // Requirement: Loop until correct

		cout << "\nPlay again? (y/n): ";
		cin >> playAgain;
		cout << "\n";

	}

	cout << "Thanks for playing!\n";
	return 0;
}