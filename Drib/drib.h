#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Fraction
{
	int numerator = 0;
	int denominator = 1;

	static int gcd(int a, int b) {
		a = a < 0 ? -a : a;
		b = b < 0 ? -b : b;
		while (b) { int t = b; b = a % b; a = t; }
		return a;
	}

	void validate(int den) {
		if (den == 0) denominator = 1;
		else if (den < 0) { numerator = -numerator; denominator = -den; }
		else denominator = den;
	}

public:
	Fraction() : numerator{ 0 }, denominator{ 1 } {}

	Fraction(int num) : numerator{ num }, denominator{ 1 } {}

	Fraction(int num, int den) : numerator{ num } {
		validate(den);
	}

	int getNumerator()   const { return numerator; }
	int getDenominator() const { return denominator; }

	void reduce() {
		int g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;
	}

	void print() const {
		cout << numerator << " / " << denominator << endl;
	}

	Fraction operator+(const Fraction& other) const {
		Fraction result(numerator * other.denominator + other.numerator * denominator,
			denominator * other.denominator);
		result.reduce();
		return result;
	}

	Fraction operator-(const Fraction& other) const {
		Fraction result(numerator * other.denominator - other.numerator * denominator,
			denominator * other.denominator);
		result.reduce();
		return result;
	}

	Fraction operator*(const Fraction& other) const {
		Fraction result(numerator * other.numerator, denominator * other.denominator);
		result.reduce();
		return result;
	}

	Fraction operator/(const Fraction& other) const {
		Fraction result(numerator * other.denominator, denominator * other.numerator);
		result.reduce();
		return result;
	}

	Fraction& operator++() {
		numerator += denominator;
		return *this;
	}

	Fraction operator++(int) {
		Fraction temp = *this;
		numerator += denominator;
		return temp;
	}

	Fraction& operator--() {
		numerator -= denominator;
		return *this;
	}

	Fraction operator--(int) {
		Fraction temp = *this;
		numerator -= denominator;
		return temp;
	}

	bool operator==(const Fraction& other) const {
		return numerator * other.denominator == other.numerator * denominator;
	}

	bool operator!=(const Fraction& other) const {
		return !(*this == other);
	}

	bool operator>(const Fraction& other) const {
		return numerator * other.denominator > other.numerator * denominator;
	}

	bool operator<(const Fraction& other) const {
		return numerator * other.denominator < other.numerator * denominator;
	}
};