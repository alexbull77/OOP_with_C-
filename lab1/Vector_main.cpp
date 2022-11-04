#include <iostream>
#include "Vector.h"

int main()
{
	double arr[5] = { 1.45, 2.87, 3.00, -476.1, 51.09 };
	unsigned int size = 5;

	Vector v1;
	v1.init(arr, size);
	v1.print();


	int multiplier = 5;
	for (int i = 0; i < v1.get_size(); i++)
	{
		v1.at(i) *= multiplier;
	}

	v1.print();

	v1.clear();

	return 0;
}