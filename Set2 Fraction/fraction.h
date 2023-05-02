#pragma once
#include <iostream>

using namespace std;

struct Fraction
{
	int numerator;
	int denominator;

	Fraction(int n = 0, int d = 1);
	void read();
	void write() const;
	void shorten();
};

int gcd(int a, int b);
Fraction add(Fraction a, Fraction b);

ostream& operator<<(ostream& out, Fraction u);
istream& operator>>(istream& in, Fraction& u);