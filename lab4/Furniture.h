#ifndef FURNITURE_H_
#define FURNITURE_H_

#include <iostream>
#include <string>

class Furniture
{
private:
	double _price;
	char* _style;
	char* _usage;
public:
	Furniture();
	Furniture(const double, const char*, const char*);
	Furniture(const Furniture&);
	virtual ~Furniture();
	virtual void print() const;
	Furniture& operator=(const Furniture&);
	void apply_discount_in_percent(const float);
};

#endif FURNITURE_H_
