#include "Queue.h"

Queue::Queue(unsigned int size)
{
    m_data = new int[size];
    std::fill(m_data, m_data + size, 0);
    m_size = size;
}

Queue::Queue(const int* data, const unsigned int size)
{
    m_data = new int[size];
    std::copy(data, data + size, m_data);
    m_size = size;
}

Queue::Queue(const Queue& other)
{
    m_size = other.m_size;
    m_data = new int[other.m_size];
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
}

Queue::~Queue()
{
    delete[] m_data;
}

Queue& Queue::push(const int num)
{
    int* tmp = new int[m_size + 1];
    std::move(m_data, m_data + m_size, tmp);
    tmp[m_size] = num;
    delete[] m_data;
    m_data = new int[m_size + 1];
    m_data = tmp;
    m_size++;
    return *this;
}

Queue& Queue::pop()
{
    if (m_size > 0)
    {
        int* tmp = new int[m_size - 1];
        std::move(m_data + 1, m_data + m_size, tmp);
        delete[] m_data;
        m_data = new int[m_size - 1];
        m_data = tmp;
        m_size--;
    }
    return *this;
}

Queue& Queue::operator=(const Queue& q)
{
    if (this != &q && *this != q)
    {
        delete[] m_data;
        m_data = new int[q.m_size];
        std::copy(q.m_data, q.m_data + q.m_size, m_data);
        m_size = q.m_size;
    }
    return *this;
}

Queue& Queue::operator=(const int size)
{
    delete[] m_data;
    m_data = new int[size];
    std::fill(m_data, m_data + size, 0);
    m_size = size;
    return *this;
}

Queue Queue::operator+(const Queue& q) const
{
    Queue sum;
    sum.m_size = m_size + q.m_size;
    sum.m_data = new int[sum.m_size];
    std::copy(m_data, m_data + m_size, sum.m_data);
    std::copy(q.m_data, q.m_data + q.m_size, sum.m_data + m_size);
    return sum;
}

bool operator==(const Queue& q1, const Queue& q2)
{
    if (q1.m_size != q2.m_size)
        return false;
    else
    {
        for (unsigned int i = 0; i < q1.m_size; i++)
        {
            if (q1.m_data[i] != q2.m_data[i])
                return false;
        }
        return true;
    }
}

bool operator!=(const Queue& q1, const Queue& q2)
{
    return !(q1 == q2);
}

//https://linuxhint.com/finding-norm-of-an-array-using-numpy/
double Queue::norm() const
{
    int norm = 0;
    for (unsigned int i = 0; i < m_size; i++)
    {
        norm += pow(m_data[i], 2);
    }
    return sqrt(norm);
}

bool operator<(const Queue& q1, const Queue& q2)
{
    return q1.norm() < q2.norm();
}

bool operator>(const Queue& q1, const Queue& q2)
{
    return q1.norm() > q2.norm();
}

ostream& operator<<(ostream& os, const Queue& q)
{
    for (unsigned int i = 0; i < q.m_size; i++)
        os << q.m_data[i] << "\t";
    return os;
}

istream& operator>>(istream& is, Queue& q)
{
    unsigned int size;
    std::cout << "Enter how many elements do you want to add: ";
    is >> size;
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << "Enter the " << (i + 1) << "-th element: ";
        int num;
        is >> num;
        q.push(num);
    }
    return is;
}

Queue& operator<<(Queue& q, const int num) //push
{
    q.push(num);
    return q;
}