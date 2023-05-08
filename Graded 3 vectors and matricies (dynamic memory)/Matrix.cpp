#include "Matrix.h"

Matrix::Matrix(int rows_count, int columns_count) : rows(nullptr)
{
	if (rows_count < 0 || columns_count < 0) {
		this->rows_count = 0;
		this->columns_count = 0;
		return;
	}
	this->rows_count = rows_count;
	this->columns_count = columns_count;

	rows = new Vector * [this->rows_count];

	for (int i = 0; i < this->rows_count; ++i) {
		rows[i] = new Vector(this->columns_count);
	}

}

Matrix::~Matrix()
{
	for (int i = 0; i < rows_count; ++i) {
		delete rows[i];
	}
	delete rows;
	rows_count = 0;
	columns_count = 0;
}

int Matrix::operator()(int i, int j) const
{
	return (*rows[i])(j);
}

int& Matrix::operator()(int i, int j)
{
	return (*rows[i])(j);
}

Matrix::Matrix(const Matrix& matrix) : rows_count(matrix.rows_count), columns_count(matrix.columns_count)
{
	rows = new Vector * [rows_count];
	for (int i = 0; i < rows_count; ++i) {
		rows[i] = new Vector(columns_count);
		for (int j = 0; j < columns_count; ++j) {
			(*this)(i, j) = matrix(i, j);
		}
	}
	
}

Matrix& Matrix::operator=(const Matrix& matrix)
{
	if (this == &matrix) {
		return *this;
	}

	this->~Matrix();
	rows_count = matrix.rows_count;
	columns_count = matrix.columns_count;
	rows = new Vector * [rows_count];
	for (int i = 0; i < rows_count; ++i) {
		rows[i] = new Vector(columns_count);
		for (int j = 0; j < columns_count; ++j) {
			(*this)(i, j) = matrix(i, j);
		}
	}
	return *this;
}

Matrix& Matrix::operator--()
{
	if (rows_count == 0) {
		return *this;
	}
	delete rows[rows_count - 1];
	--rows_count;
	if (rows_count == 0) {
		columns_count = 0;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
	os << "[\n";
	for (int i = 0; i < matrix.rows_count; ++i) {
		os << *(matrix.rows[i]) << std::endl;
	}
	os << "]\n";
	return os;
}

Matrix* operator*(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.columns_count != rhs.rows_count) {
		return nullptr;
	}

	Matrix* result = new Matrix(lhs.rows_count, rhs.columns_count);
	for (int i = 0; i < result->rows_count; i++) {
		for (int j = 0; j < result->columns_count; j++) {
			(*result)(i, j) = 0;
			for (int k = 0; k < lhs.columns_count; k++) {
				(*result)(i, j) += lhs(i, k) * rhs(k, j);
			}
		}
	}
	return result;
}
