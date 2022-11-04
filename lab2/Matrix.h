#ifndef MATRIX_H_
#define MATRIX_H_

#include <string>

class Matrix
{
private:
	float** m_data;
	unsigned int m_rows;
	unsigned int m_cols;

public:
	Matrix();
	Matrix(const unsigned int);
	Matrix(const unsigned int, const unsigned int, const int = 0);
	Matrix(const Matrix&);
	~Matrix();
	float& at(const unsigned int, const unsigned int);
	bool is_Empty() const;
	void print() const;
	Matrix operator+(const Matrix&) const;
	Matrix operator-(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	Matrix operator*(const float) const;
};

Matrix operator*(const float, const Matrix&);

#endif