#include "realization.cpp"

int main()
{
	Furniture* arr[3];
	arr[0] = new Furniture(50, "modern", "classroom");
	arr[1] = new Table(30, "rococco", "bedroom", 110, 90, "wood");
	arr[2] = new Chair(25, "vintage", "kitchen", 95, false);

	for (int i = 0; i < 3; i++)
	{
		arr[i]->print();
		arr[i]->apply_discount_in_percent(50);
		arr[i]->print();
		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
		delete arr[i];

	return 0;
}