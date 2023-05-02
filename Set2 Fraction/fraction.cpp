#include <iostream>
using namespace std;
#include "fraction.h"

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

Fraction add(Fraction a, Fraction b)
{
	Fraction temp;
	temp.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
	temp.denominator = a.denominator * b.denominator;
	temp.shorten();
	return temp;
}

ostream& operator<<(ostream& out, Fraction u)
{
	out << u.numerator << "/" << u.denominator << endl;
	return out;
}

istream& operator>>(istream& in, Fraction& u)
{
	cout << "Enter numerator: ";
	in >> u.numerator;
	cout << "\nEnter denominator: ";
	in >> u.denominator;
	if (u.denominator == 0) {
		u.numerator = 0;
		u.denominator = 1;
	}
	u.shorten();
	return in;
}

Fraction::Fraction(int n, int d)
{
	this->numerator = n;
	if (d == 0) {
		this->numerator = 0;
		this->denominator = 1;
	}
	this->denominator = d;
	this->shorten();
}

void Fraction::read()
{
	cout << "Enter numerator: ";
	cin >> this->numerator;
	cout << "\nEnter denominator: ";
	cin >> this->denominator;
	if (this->denominator == 0) {
		this->numerator = 0;
		this->denominator = 1;
	}
	this->shorten();
}

void Fraction::write() const
{
	cout << this->numerator << "/" << this->denominator << endl;
}

void Fraction::shorten()
{
	int d = gcd(this->numerator, this->denominator);
	if (d != 1) {
		this->numerator = this->numerator / d;
		this->denominator = this->denominator / d;
	}
}
