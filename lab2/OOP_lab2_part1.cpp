#include <iostream>
#include "Stack.h"


int main()
{
	Stack s1(2, 2);
	s1.Print();

	s1.Push(1);
	s1.Print();

	s1.Push(1);
	s1.Print();

	s1.Push(1);
	s1.Print();

	return 0;
}