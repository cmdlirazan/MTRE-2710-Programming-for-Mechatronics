/*
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine Marie Lirazan
Homework: 04 Operator Overloading
*/

#include <iostream>

using namespace std;

// helper gcd function (used in reduce)
int gcd(int a, int b) {
    if (b == 0) return (a < 0 ? -a : a); // make gcd always positive
    return gcd(b, a % b);
}

// Requirement: class with constructors, operator overloads, getters, and reduce
class Rational {
    int numer, denom;

public:
    // Requirement: default constructor
    Rational() {
        numer = 0;
        denom = 1;
    }

    // Requirement: parameterized constructor
    Rational(int n, int d) {
        if (d == 0) {
            cerr << "Denominator cannot be zero. Setting to 1." << endl;
            d = 1;
        }
        numer = n;
        denom = d;
        reduce();
    }

    // Requirement: Rational + Rational
    Rational operator+(Rational r) {
        Rational temp(numer * r.denom + r.numer * denom, denom * r.denom);
        temp.reduce();
        return temp;
    }

    // Requirement: Rational - Rational
    Rational operator-(Rational r) {
        Rational temp(numer * r.denom - r.numer * denom, denom * r.denom);
        temp.reduce();
        return temp;
    }

    // Requirement: Rational * Rational
    Rational operator*(Rational r) {
        Rational temp(numer * r.numer, denom * r.denom);
        temp.reduce();
        return temp;
    }

    // Requirement: Rational / Rational
    Rational operator/(Rational r) {
        Rational temp(numer * r.denom, denom * r.numer);
        temp.reduce();
        return temp;
    }

    // Requirement: Rational + int
    Rational operator+(int x) {
        Rational temp(numer + x * denom, denom);
        temp.reduce();
        return temp;
    }

    // Requirement: Rational - int
    Rational operator-(int x) {
        Rational temp(numer - x * denom, denom);
        temp.reduce();
        return temp;
    }

    // Requirement: Rational * int
    Rational operator*(int x) {
        Rational temp(numer * x, denom);
        temp.reduce();
        return temp;
    }

    // Requirement: Rational / int
    Rational operator/(int x) {
        Rational temp(numer, denom * x);
        temp.reduce();
        return temp;
    }

    // Requirement: get numerator
    int getNumer() const { return numer; }

    // Requirement: get denominator
    int getDenom() const { return denom; }

    // Requirement: reduce fraction
    void reduce() {
        int g = gcd(numer, denom);
        if (g != 0) {
            numer /= g;
            denom /= g;
        }
        if (denom < 0) {
            numer = -numer;
            denom = -denom;
        }
    }
};

// Requirement: overload << for output
ostream& operator<<(ostream& out, const Rational& r) {
    out << r.getNumer() << "/" << r.getDenom();
    return out;
}

int main() {
    // Requirement: test class with given expression
    Rational a(1, 2), b(5, 2), c(1, 4), d(5, 3), e(3, 2);

    cout << (a + 1) + b * (c - 2) * 3 - d / e / 2 << endl;

    return 0;
}