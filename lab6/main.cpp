#include "Progression.h"

int main()
{
	Progression* arr[2];
	arr[0] = new ArithmeticProgression(1, 5);
	arr[1] = new GeometricProgression(1, 5);
	
	for (int i = 0; i < 2; i++)
		std::cout << arr[i]->sum_progression(3) << std::endl;

	for (int i = 0; i < 2; i++)
		delete arr[i];

	return 0;
}