#ifndef STACK_H_
#define STACK_H_

class Stack
{
private:

	unsigned int m_capacity;
	unsigned int m_size;
	int* m_data;

public:
	Stack();
	Stack(const int, const unsigned int);
	Stack(const Stack&);
	~Stack();
	void Print() const;
	void Push(const int);
	bool isFull() const;
	bool isEmpty() const;
	int Pop();
};

#endif