#pragma once

#include <ostream>

class Vector {

private:
    int* elements;
    int size;

public:
    Vector() = delete;

    //PART 1 (1.5 pts)
    Vector(int size, int* elements = nullptr);
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
    ~Vector();
    int operator()(int i) const;
    int& operator()(int i);

    //PART 2 (1 pt)
    Vector(const Vector& v);
    Vector& operator=(const Vector& v);

    //PART 3 (1 pt)
    Vector& operator++();
    Vector operator--(int n);
};
