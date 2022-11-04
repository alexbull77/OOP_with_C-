#ifndef TABLE_H_
#define TABLE_H_

#include "Furniture.h";

class Table : public Furniture
{
private:
	int _height;
	int _width;
	char* _material;
public:
	Table();
	Table(const double, const char*, const char*, const int, const int, const char*);
	Table(const Table&);
	~Table();
	void print() const;
	Table& operator=(const Table&);
};

#endif;
