#include <iostream>
#include "List.h"

int main()
{
	List<int> l;
	l.push_back(1);
	std::cout << l.front_data();
	return 0;
}