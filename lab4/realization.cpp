#include "Table.h";
#include "Chair.h";

Furniture::Furniture()
	:_price(0)
{
	_style = new char[5];
	strcpy(_style, "None");
	_usage = new char[5];
	strcpy(_usage, "None");
}

Furniture::Furniture(const double price, const char* style, const char* usage)
	:_price(price)
{
	_style = new char[strlen(style) + 1];
	strcpy(_style, style);
	_usage = new char[strlen(usage) + 1];
	strcpy(_usage, usage);
}

Furniture::Furniture(const Furniture& other)
	:_price(other._price)
{
	_style = new char[strlen(other._style) + 1];
	strcpy(_style, other._style);
	_usage = new char[strlen(other._usage) + 1];
	strcpy(_usage, other._usage);
}

Furniture::~Furniture()
{
	delete[] _style;
	delete[] _usage;
}

void Furniture::print() const
{
	std::cout << "\nPrice = " << _price << " USD\t\tStyle = ";
	for (int i = 0; i < strlen(_style); i++)
		std::cout << _style[i];
	std::cout << "\t\tUsage = ";
	for (int i = 0; i < strlen(_usage); i++)
		std::cout << _usage[i];
}

Furniture& Furniture::operator=(const Furniture& other)
{
	if (this != &other)
	{
		_price = other._price;
		delete[] _style;
		_style = new char(strlen(other._style) + 1);
		strcpy(_style, other._style);
		delete[] _usage;
		_usage = new char(strlen(other._usage) + 1);
		strcpy(_usage, other._usage);
	}
	return *this;
}

void Furniture::apply_discount_in_percent(const float discount)
{
	_price = _price * (discount / 100);
}

Chair::Chair() :Furniture(), _height(0), _has_backrest(false) {}

Chair::Chair(const double price, const char* style, const char* usage, const int height, bool has_back_rest)
	:Furniture(price, style, usage), _height(height), _has_backrest(has_back_rest) {}

Chair::Chair(const Chair& other)
	:Furniture(other), _height(other._height), _has_backrest(other._has_backrest) {}

void Chair::print() const
{
	Furniture::print();
	std::cout << "\t\tHeight = " << _height << "\t" << (_has_backrest ? "Has backrest" : "Doesn't have backrest");
}

Chair& Chair::operator=(const Chair& other)
{
	if (this != &other)
	{
		Furniture::operator=(other);
		_height = other._height;
		_has_backrest = other._has_backrest;
	}
	return *this;
}

Table::Table() : Furniture(), _height(0), _width(0)
{
	_material = new char[5];
	strcpy(_material, "None");
}

Table::Table(const double price, const char* style, const char* usage, const int height, const int width, const char* material)
	:Furniture(price, style, usage), _height(height), _width(width)
{
	_material = new char[strlen(material) + 1];
	strcpy(_material, material);
}

Table::Table(const Table& other)
	:Furniture(other), _height(other._height), _width(other._width)
{
	_material = new char[strlen(other._material) + 1];
	strcpy(_material, other._material);
}

Table::~Table()
{
	delete[] _material;
}

void Table::print() const
{
	Furniture::print();
	std::cout << "\t\tHeight = " << _height << " cm\t\tWidth = " << _width << " cm" << "\t\tMaterial = ";
	for (int i = 0; i < strlen(_material);i++)
		std::cout << _material[i];
}

Table& Table::operator=(const Table& other)
{
	if (this != &other)
	{
		Furniture::operator=(other);
		_height = other._height;
		_width = other._width;
		delete[] _material;
		_material = new char(strlen(other._material) + 1);
		strcpy(_material, other._material);
	}
	return *this;
}