#include <iostream>
#include <algorithm>
#include "Stack.h"

Stack::Stack()
{
	m_size = 1;
	m_capacity = 2;
	m_data = new int[m_capacity];
	m_data[0] = 0;
}

Stack::Stack(const int data, const unsigned int size)
{
	m_size = size;
	m_capacity = size * 2;
	m_data = new int[m_capacity];
	for (unsigned int i = 0; i < size; i++)
		m_data[i] = data;
}
Stack::Stack(const Stack& other)
{
	this->m_data = new int[other.m_capacity];
	this->m_capacity = other.m_capacity;
	this->m_size = other.m_size;
	std::copy(other.m_data, other.m_data + m_size, this->m_data);
}

Stack::~Stack()
{
	if (m_data != nullptr)
	{
		delete[] m_data;
		m_data = nullptr;
	}
	else
		std::cout << "Nothing to Delete" << std::endl;
}

void Stack::Print() const
{
	if (!this->isEmpty())
	{
		for (unsigned int i = 0; i < m_size; i++)
		{
			std::cout << this->m_data[i] << "\t";
		}
		std::cout << "Capacity: " << this->m_capacity << "\t" << "Size: " << this->m_size << std::endl;
		std::cout << std::endl;
	}
	else
		std::cout << "Stack is Empty!" << std::endl;
}

void Stack::Push(const int value)
{
	if (this->isFull())
	{
		m_capacity = m_capacity * 2;
		Stack tmp = *this;
		//before allocating new memory we need to delete the old data to not leek memory
		this->~Stack();
		//can use delete[] m_data?
		this->m_data = new int[tmp.m_capacity];
		std::copy(tmp.m_data, tmp.m_data + tmp.m_size, m_data);

	}

	m_data[m_size] = value;
	m_size++;
}

bool Stack::isFull() const
{
	return m_capacity == m_size;
}

bool Stack::isEmpty() const
{
	return m_size <= 0;
}

int Stack::Pop()
{
	m_size--;
	return m_data[m_size];
}