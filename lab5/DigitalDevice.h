#ifndef DIGITAL_DEVICE_H_
#define DIGITAL_DEVICE_H_

#include "ElectronicDevice.h"
#include <string>

class DigitalDevice : virtual public ElectronicDevice
{
	std::string* camera;
	bool touch_screen_availability;

protected:
	virtual void data() const override;

public:
	DigitalDevice() = delete;
	DigitalDevice(const std::string, const double, const double, const std::string, const bool);
	DigitalDevice(const DigitalDevice&);
	DigitalDevice& operator=(const DigitalDevice&);
	virtual void show() const override;
	virtual ~DigitalDevice() override { delete camera; }
};

#endif
