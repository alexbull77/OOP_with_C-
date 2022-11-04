#ifndef ELECTRONIC_DEVICE_H_
#define ELECTRONIC_DEVICE_H_

#include <iostream>
using std::cout;

class ElectronicDevice
{
	std::string* power_supply;
	double min_operational_temp;
	double max_operational_temp;

protected:
	virtual void data() const;
public:
	ElectronicDevice() = delete;
	ElectronicDevice(const std::string, const double, const double);
	ElectronicDevice(const ElectronicDevice&);
	ElectronicDevice& operator=(const ElectronicDevice&);
	virtual ~ElectronicDevice() { delete power_supply; }
	virtual void show() const { data(); }
};

#endif