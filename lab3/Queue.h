#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include <algorithm>
#include <cmath>

using std::ostream;
using std::istream;

class Queue
{
private:
	int* m_data;
	unsigned int m_size;
	double norm() const;
public:
	Queue(unsigned int = 1);
	Queue(const int*, const unsigned int);
	Queue(const Queue&);
	~Queue();
	Queue& push(const int);
	Queue& pop();
	Queue& operator=(const Queue&);
	Queue& operator=(const int);
	Queue operator+(const Queue&) const;
	friend bool operator==(const Queue&, const Queue&);
	friend bool operator!=(const Queue&, const Queue&);
	friend bool operator<(const Queue&, const Queue&);
	friend bool operator>(const Queue&, const Queue&);
	friend ostream& operator<<(ostream&, const Queue&);
	friend istream& operator>>(istream&, Queue&);
	friend Queue& operator<<(Queue&, const int); //push
};

#endif
