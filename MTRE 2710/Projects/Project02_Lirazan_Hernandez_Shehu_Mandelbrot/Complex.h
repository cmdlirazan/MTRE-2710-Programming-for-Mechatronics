#include <iostream>
#include <math.h>
using namespace std;

class Complex {
	double real, imag;
public:
	// Requirement: Create class to instantiate complex numbers
	Complex();
	Complex(double r, double i);
	void    setVals(double r, double i) { real = r;imag = i; };
	double  getReal() { return real; };
	double  getImag() { return imag; };

	// Requirement: Return magnitude
	double  getMag() { return sqrt(real * real + imag * imag); };
	Complex operator+(Complex r); // Requirement: Add two complex numbers
	Complex operator-(Complex r); // Requirement: Subtract two complex numbers
	Complex operator*(Complex r); // Requirement: Multiply two complex numbers
	Complex operator/(Complex r); // Requirement: Divide two complex numbers
};

// Requirement: Default constructor
Complex::Complex() {
	real = imag = 0;
}

// Requirement: Constructor with real and imaginary values
Complex::Complex(double r, double i) {
	real = r; imag = i;
}

// Requirement: Addition operator
Complex Complex::operator+(Complex z) {
	Complex temp;
	temp.real = real + z.real;
	temp.imag = imag + z.imag;
	return temp;
}

// Requirement: Subtraction operator
Complex Complex::operator-(Complex z) {
	Complex temp;
	temp.real = real - z.real;
	temp.imag = imag - z.imag;
	return temp;
}

// Requirement: Multiplication operator
Complex Complex::operator*(Complex z) {
	Complex temp;
	temp.real = real * z.real - imag * z.imag;
	temp.imag = real * z.imag + imag * z.real;
	return temp;
}

// Requirement: Division operator using reciprocal and conjugate
Complex Complex::operator/(Complex z) {
	z.imag *= -1;
	Complex temp = (*this) * z;
	temp.real /= z.real * z.real + z.imag * z.imag;
	temp.imag /= z.real * z.real + z.imag * z.imag;
	return temp;
}

// Requirement: Write complex number to output stream
ostream& operator<<(ostream& out, Complex z) {
	if (z.getImag() >= 0)
		return out << z.getReal() << " + " << z.getImag() << "i";
	else
		return out << z.getReal() << " - " << -1 * z.getImag() << "i";
}

// Requirement: Return reciprocal of complex multiplied by scalar
Complex operator/(double x, Complex c) {
	Complex numer(x, 0);
	return numer / c;
}
