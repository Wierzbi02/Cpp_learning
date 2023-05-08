#include "Vector.h"

Vector::Vector(int size, int* elements) : size(size > 0 ? size : 0), elements(nullptr)
{
	this->elements = new int[this->size];
	if (elements == nullptr) {
		for (size_t i = 0; i < this->size; ++i) {
			this->elements[i] = 0;
		}
	}
	else {
		for (size_t i = 0; i < this->size; ++i) {
			this->elements[i] = elements[i];
		}
	}
}

Vector::~Vector()
{
	delete[] elements;
	size = 0;
}

int Vector::operator()(int i) const
{
	return elements[i];
}

int& Vector::operator()(int i)
{
	return elements[i];
}

Vector::Vector(const Vector& v) : size(v.size)
{
	elements = new int[size];
	for (size_t i = 0; i < size; ++i) {
		elements[i] = v.elements[i];
	}
}

Vector& Vector::operator=(const Vector& v)
{
	if (this == &v) {
		return *this;
	}

	this->~Vector();
	size = v.size;
	elements = new int[size];
	for (size_t i = 0; i < size; ++i) {
		elements[i] = v.elements[i];
	}

	return *this;
}

Vector& Vector::operator++()
{
	Vector temp{ *this };
	delete[] elements;
	++size;

	elements = new int[size];
	for (int i = 0; i < size - 1; ++i) {
		elements[i] = temp.elements[i];
	}
	elements[size - 1] = 0;
	
	return *this;
}

Vector Vector::operator--(int n)
{
	Vector temp{ *this };
	delete[] elements;
	--size;

	elements = new int[size];
	for (int i = 0; i < size; ++i) {
		elements[i] = temp.elements[i];
	}
	

	return temp;
	
}



std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
	os << "[ ";
	for (int i = 0; i < vector.size; ++i) {
		os << vector(i) << ' ';
	}
	os << "]";
	return os;
}
