#ifndef PROGRESSION_H_
#define PROGRESSION_H_

#include <iostream>
#include <cmath>

class Progression
{
public:
	virtual double sum_progression(const int size) const = 0;
};

class ArithmeticProgression : public Progression
{
	double first_element;
	const double difference;

public:
	ArithmeticProgression(const double first_el, const double diff)
		:first_element(first_el), difference(diff) {}

	double sum_progression(const int size) const
	{
		return (((2 * first_element + difference * (size - 1)) * size) / 2);
	}
};

class GeometricProgression : public Progression
{
	double first_element;
	const double product;
	
public:
	GeometricProgression(const double first_el, const double prod)
		:first_element(first_el), product(prod) {}

	double sum_progression(const int size) const
	{
		return (first_element * (std::pow(product, size) - 1)) / (product - 1);
	}
};

#endif