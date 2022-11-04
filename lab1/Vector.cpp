#include <iostream>
#include "Vector.h"

void Vector::init(const double* const array = { 0 }, const unsigned int size = 1)
{
	this->size = size;
	this->data = new double[size];
	for (unsigned int i = 0; i < size; i++)
		this->data[i] = array[i];
}

void Vector::print() const
{
	if (this->data != nullptr)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			std::cout << this->data[i] << "\t";
		}
		std::cout << std::endl;
	}
}

void Vector::clear()
{
	if (this->data != nullptr)
	{
		delete[] this->data;
		this->size = 0;
		this->data = nullptr;
	}
	else
		std::cout << "Nothing to delete" << std::endl;
}

void Vector::set_size(const unsigned int new_size)
{
	if (this->data == nullptr)
		return;

	Vector new_vec;
	new_vec.size = new_size;
	new_vec.data = new double[new_size];
	for (unsigned int i = 0; i < new_size; i++)
	{
		new_vec.data[i] = this->data[i];
	}

	this->clear();
	this->data = new double[new_size];
	this->size = new_vec.size;
	for (unsigned int i = 0; i < new_size; i++)
	{
		this->data[i] = new_vec.data[i];
	}

	new_vec.clear();
}

double& Vector::at(int index) const
{
	if (index <= 0)
		return this->data[0];
	else if (index >= this->size)
		return this->data[size - 1];
	else
		return this->data[index];
}

double Vector::positive_sum() const
{
	double result = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		if (this->data[i] > 0)
			result += this->data[i];
	}
	return result;
}

unsigned int Vector::get_size() const
{
	return this->size;
}