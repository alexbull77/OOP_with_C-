#ifndef CHAIR_H_
#define CHAIR_H_

#include "Furniture.h";

class Chair : public Furniture
{
private:
	int _height;
	bool _has_backrest;
public:
	Chair();
	Chair(const double, const char*, const char*, const int, bool);
	Chair(const Chair&);
	void print() const;
	Chair& operator=(const Chair&);
};

#endif
