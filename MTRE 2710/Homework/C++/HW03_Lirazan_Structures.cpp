/*
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine Marie Lirazan
Homework: 03 Structures
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct Student {
	int credit[100];
	char grade[100];
	int numCourses;

	void setGrades(int creditIn[], char gradeIn[], int numIn); // Requirement: store initial course info
	void addGrade(int creditIn, char gradeIn); // Requirement: add a new course to record
	double getGPA(); // Requirement: calculate weighted GPA

};

int main() {
	const int numStart = 5;
	int startCredit[numStart] = { 3, 4, 3, 2, 4 };
	char startGrade[numStart] = { 'A', 'A', 'B', 'C', 'B' };

	Student me, you;

	me.setGrades(startCredit, startGrade, numStart); // Requirement: initialize student with given courses
	you.setGrades(startCredit, startGrade, numStart);

	me.addGrade(4, 'C'); // Requirement: append additional course
	me.addGrade(3, 'F');
	you.addGrade(2, 'B'); 
	you.addGrade(4, 'A');

	cout << "I have a " << me.getGPA() << " GPA" << endl; // Requirement: output GPA
	cout << "You have a " << you.getGPA() << " GPA" << endl;

	return 0;
}

// Requirement: store intial course info
void Student::setGrades(int creditIn[], char gradeIn[], int numIn) {
	numCourses = numIn;
	for (int i = 0; i < numIn; i++) {
		credit[i] = creditIn[i];
		grade[i] = gradeIn[i];
	}
}

// Requirement: add a new course to record
void Student::addGrade(int creditIn, char gradeIn) {
	credit[numCourses] = creditIn;
	grade[numCourses] = gradeIn;
	numCourses++;
}

// Requirement: calculate weighted GPA
double Student::getGPA() {
	double totalPoints = 0.0;
	int totalCredits = 0;

	for (int i = 0; i < numCourses; i++) {
		double  gradePoint;
		switch (grade[i]) {
		case 'A': gradePoint = 4.0; break;
		case 'B': gradePoint = 3.0; break;
		case 'C': gradePoint = 2.0; break;
		case 'D': gradePoint = 1.0; break;
		case 'F': gradePoint = 0.0; break;
		default: gradePoint = 0.0;

		}
		totalPoints += gradePoint * credit[i];
		totalCredits += credit[i];
	}
	if (totalCredits == 0) return 0.0;
	return totalPoints / totalCredits;
}