#pragma once

#include <ostream>
#include "Vector.h"

class Matrix {

private:
    Vector** rows;
    int rows_count;
    int columns_count;

public:
    Matrix() = delete;

    //PART 4 (1.5 pts)
    Matrix(int rows_count, int columns_count);
    ~Matrix();
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    int operator()(int i, int j) const;
    int& operator()(int i, int j);

    // PART 5 (1 pt)
    Matrix(const Matrix& matrix);
    Matrix& operator=(const Matrix& matrix);

    //PART 6 (1 pt)
    Matrix& operator--();

    //PART 7 (1 pt)
    friend Matrix* operator*(const Matrix& lhs, const Matrix& rhs);
};
