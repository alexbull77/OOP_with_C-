#include "Monitor.h"

ElectronicDevice::ElectronicDevice(const std::string ps, const double min_temp, const double max_temp)
	: min_operational_temp(min_temp), max_operational_temp(max_temp)
{
	power_supply = new std::string(ps);
}

ElectronicDevice::ElectronicDevice(const ElectronicDevice& other)
	: min_operational_temp(other.min_operational_temp), max_operational_temp(other.max_operational_temp)
{
	power_supply = new std::string(*other.power_supply);
}

ElectronicDevice& ElectronicDevice::operator=(const ElectronicDevice& other)
{
	if (this != &other)
	{
		min_operational_temp = other.min_operational_temp;
		max_operational_temp = other.max_operational_temp;
		delete power_supply;
		power_supply = new std::string(*other.power_supply);
	}
	return *this;
}

void ElectronicDevice::data() const
{
	cout << "\nPower Supply: " << *power_supply;
	cout << " Watt\tMin Operational Temperature: " << min_operational_temp;
	cout << "\t\tMax Operational Temperature: " << max_operational_temp << " Celsius";
}

Television& Television::operator=(const Television& other)
{
	if (this != &other)
	{
		ElectronicDevice::operator=(other);
		resolution = other.resolution;
		refresh_rate = other.refresh_rate;
	}
	return *this;
}

void Television::data() const
{
	cout << "\t\tResolution: " << resolution;
	cout << "p\tRefresh Rate: " << refresh_rate << " Hz";
}

void Television::show() const
{
	ElectronicDevice::data();
	data();
}

DigitalDevice::DigitalDevice(const std::string ps, const double min_temp, const double max_temp, const std::string cam, const bool touch_screen)
	:ElectronicDevice(ps, min_temp, max_temp), touch_screen_availability(touch_screen)
{
	camera = new std::string(cam);
}

DigitalDevice::DigitalDevice(const DigitalDevice& other)
	: ElectronicDevice(other), touch_screen_availability(other.touch_screen_availability)
{
	camera = new std::string(*other.camera);
}

DigitalDevice& DigitalDevice::operator=(const DigitalDevice& other)
{
	if (this != &other)
	{
		ElectronicDevice::operator=(other);
		touch_screen_availability = other.touch_screen_availability;
		delete camera;
		camera = new std::string(*other.camera);
	}
	return *this;
}

void DigitalDevice::data() const
{
	cout << "\tCamera: " << *camera;
	cout << "\tTouch Screen Availability: " << (touch_screen_availability ? "Yes" : "No");
}

void DigitalDevice::show() const
{
	ElectronicDevice::data();
	data();
}


Monitor::Monitor(const std::string ps, const double min_temp, const double max_temp, const double res,
	const double refr_r, const std::string cam, const bool touch_screen,
	const bool free_sync, const bool disp_port, const std::string brand_name)

	:ElectronicDevice(ps, min_temp, max_temp), Television(ps, min_temp, max_temp, res, refr_r),
	DigitalDevice(ps, min_temp, max_temp, cam, touch_screen),
	free_sync_compatability(free_sync), diplay_port_availability(disp_port)
{
	brandname = new std::string(brand_name);
}

Monitor::Monitor(const Monitor& other)
	:ElectronicDevice(other), Television(other), DigitalDevice(other),
	free_sync_compatability(other.free_sync_compatability), diplay_port_availability(other.diplay_port_availability)
{
	brandname = new std::string(*other.brandname);
}

Monitor& Monitor::operator=(const Monitor& other)
{
	if (this != &other)
	{
		ElectronicDevice::operator=(other);
		Television::operator=(other);
		DigitalDevice::operator=(other);
		free_sync_compatability = other.free_sync_compatability;
		diplay_port_availability = other.diplay_port_availability;
		delete brandname;
		brandname = new std::string(*other.brandname);
	}
	return *this;
}

void Monitor::data() const
{
	cout << "\tFreeSync Compatability: " << (free_sync_compatability ? "Yes" : "No");
	cout << "\t\tDisplay Port: " << (diplay_port_availability ? "Available" : "Not Available");
	cout << "\t\tBrandname: " << *brandname;
}

void Monitor::show() const
{
	ElectronicDevice::data();
	Television::data();
	DigitalDevice::data();
	data();
}
