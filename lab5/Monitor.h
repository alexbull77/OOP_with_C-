#ifndef MONITOR_H_
#define MONITOR_H_

#include "Television.h";
#include "DigitalDevice.h";

class Monitor : public Television, public DigitalDevice
{
	std::string* brandname;
	bool free_sync_compatability;
	bool diplay_port_availability;

protected:
	void data() const override;

public:
	Monitor() = delete;
	Monitor(const std::string, const double, const double, const double,
		const double, const std::string, const bool,
		const bool, const bool, const std::string);
	Monitor(const Monitor&);
	Monitor& operator=(const Monitor&);
	void show() const override;
	~Monitor() override { delete brandname; }
};

#endif