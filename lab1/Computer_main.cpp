#include <iostream>
#include "Computer.h"

int main()
{
    Computer c1;
    c1.init("China", "i3", 2100);

    Computer c2;
    c2.init("China", "i5", 1500);

    Computer c3;
    c3.init("China", "i5", 500);

    Computer array[100] = { c1, c2, c3 };
    int size = 3;
    
    for (int i = 0; i < size; i++)
    {
        array[i].print();
    }

    //bubble sort
    for (int i = 0; i < size  - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j].is_greater(array[j + 1])) 
            {
                Computer tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }

    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        array[i].print();
    }

    array->clear();
    //tested the clear func
    array->clear();
    array->clear();

    return 0;
}