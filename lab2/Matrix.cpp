#include <iostream>
#include "Matrix.h"

Matrix::Matrix()
{
	m_data = nullptr;
	m_cols = m_rows = 0;
}

Matrix::Matrix(const unsigned int size)
{
	m_data = new float* [size];
	for (unsigned int i = 0; i < size; i++)
		m_data[i] = new float[size];

	for (unsigned int i = 0; i < size; i++)
		for (unsigned int j = 0; j < size; j++)
			m_data[i][j] = 0;

	m_cols = m_rows = size;
}

Matrix::Matrix(const unsigned int cols, const unsigned int rows, const int val)
{
	m_data = new float* [rows];
	for (unsigned int i = 0; i < rows; i++)
		m_data[i] = new float[cols];

	for (unsigned int i = 0; i < rows; i++)
		for (unsigned int j = 0; j < cols; j++)
			m_data[i][j] = val;

	m_cols = cols;
	m_rows = rows;
}

Matrix::Matrix(const Matrix& other)
{
	m_data = new float* [other.m_rows];

	for (unsigned int i = 0; i < other.m_rows; i++)
		m_data[i] = new float[other.m_cols];

	for (unsigned int i = 0; i < other.m_rows; i++)
		for (unsigned int j = 0; j < other.m_cols; j++)
			m_data[i][j] = other.m_data[i][j];

	m_cols = other.m_cols;
	m_rows = other.m_rows;
}

Matrix::~Matrix()
{
	for (unsigned int i = 0; i < m_rows; i++)
		delete[] m_data[i];
	delete[] m_data;
}

float& Matrix::at(const unsigned int pos_col, const unsigned int pos_row)
{
	if (!this->is_Empty() && pos_col < m_cols && pos_row < m_rows)
		return m_data[pos_row][pos_col];
	else
		std::cout << "Out of range" << std::endl;
}

bool Matrix::is_Empty() const
{
	return m_cols <= 0 || m_rows <= 0;
}

Matrix Matrix::operator+(const Matrix& other) const
{
	if (m_cols == other.m_cols && m_rows == other.m_rows && m_rows > 0 && m_cols > 0)
	{
		Matrix sum(m_cols, m_rows);

		for (unsigned int i = 0; i < m_rows; i++)
			for (unsigned int j = 0; j < m_cols; j++)
				sum.m_data[i][j] = m_data[i][j] + other.m_data[i][j];
		return sum;
	}
	else
		std::cout << "Cannot add the given matrices, NOT THE SAME DIMENSIONS" << std::endl;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	if (m_cols == other.m_cols && m_rows == other.m_rows && m_rows > 0 && m_cols > 0)
	{
		Matrix dif(m_cols, m_rows);

		for (unsigned int i = 0; i < m_rows; i++)
			for (unsigned int j = 0; j < m_cols; j++)
				dif.m_data[i][j] = m_data[i][j] - other.m_data[i][j];
		return dif;
	}
	else
		std::cout << "Cannot substract the given matrices, NOT THE SAME DIMENSIONS" << std::endl;
}

Matrix Matrix::operator*(const Matrix& other) const
{
	if (m_cols == other.m_cols && m_rows == other.m_rows && m_rows > 0 && m_cols > 0)
	{
		Matrix res(m_cols, m_rows);

		for (unsigned int i = 0; i < m_rows; i++)
			for (unsigned int j = 0; j < m_cols; j++)
				res.m_data[i][j] = m_data[i][j] * other.m_data[i][j];
		return res;
	}
	else
		std::cout << "Cannot multiply the given matrices, NOT THE SAME DIMENSIONS" << std::endl;
}

Matrix Matrix::operator*(const float num) const
{
	if (!this->is_Empty())
	{
		Matrix result(m_cols, m_rows);

		for (unsigned int i = 0; i < m_rows; i++)
			for (unsigned int j = 0; j < m_cols; j++)
				result.m_data[i][j] = m_data[i][j] * num;

		result.m_cols = m_cols;
		result.m_rows = m_rows;

		return result;
	}
	else
		std::cout << "Matrix is empty!" << std::endl;
}

Matrix operator*(const float num, const Matrix& m)
{
	return m * num;
}

void Matrix::print() const
{
	if (!this->is_Empty())
	{
		for (unsigned int i = 0; i < m_rows; i++)
		{
			for (unsigned int j = 0; j < m_cols; j++)
				std::cout << m_data[i][j] << "  ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "Matrix is empty!" << std::endl;
}
