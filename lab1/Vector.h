#ifndef VECTOR_H_
#define VECTOR_H_

class Vector
{
private:

	unsigned int size{ 0 };
	double* data{ nullptr };

public:

	void init(const double* const array, const unsigned int size);
	void print() const;
	void clear();
	void set_size(const unsigned int new_size);
	double& at(int index) const;
	double positive_sum() const;
	unsigned int get_size() const;
};


#endif