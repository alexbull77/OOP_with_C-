#include <iostream>
#include "Computer.h"

void Computer::init(const char* man = "NONE", const char* proc = "NONE", const int cs = 0)
{

    this->manufacturer = new char[strlen(man) + 1];
    for (unsigned int i = 0; i < strlen(man); i++)
    {
        this->manufacturer[i] = man[i];
    }
    this->manufacturer[strlen(man)] = '\0';


    this->processor = new char[strlen(proc) + 1];
    for (unsigned int i = 0; i < strlen(proc); i++)
    {
        this->processor[i] = proc[i];
    }
    this->processor[strlen(proc)] = '\0';


    this->clock_speed = cs;
}

void Computer::clear()
{
    if (this->manufacturer != nullptr)
    {
        delete[] this->manufacturer;
        delete[] this->processor;
        this->manufacturer = nullptr;
        this->processor = nullptr;
    }
    else
    {
        std::cout << "Nothing to delete" << std::endl;
    }
}

void Computer::print() const
{
    if (this->manufacturer == nullptr)
        return;

    std::cout << this->manufacturer << "\t";
    std::cout << this->processor << "\t";
    std::cout << this->clock_speed << std::endl;
}

//comparison func is only taking in consideration clock_speed, not the proc
bool Computer::is_greater(const Computer& other) const
{
    return this->clock_speed > other.clock_speed;
}

Computer& Computer::set(const char* new_manufacturer, const char* new_processor, const int new_clock_speed)
{
    if (this->manufacturer != nullptr && this->processor != nullptr)
        this->clear();

    this->init(new_manufacturer, new_processor, new_clock_speed);

    return *this;
}