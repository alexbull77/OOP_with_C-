#ifndef TELEVISION_H_
#define TELEVISION_H_
#include "ElectronicDevice.h"

class Television : virtual public ElectronicDevice
{
	double resolution;
	double refresh_rate;

protected:
	virtual void data() const override;

public:
	Television() = delete;
	Television(const std::string ps, const double min_temp, const double max_temp, const double res, const double refr_r)
		: ElectronicDevice(ps, min_temp, max_temp), resolution(res), refresh_rate(refr_r) {}
	Television(const Television& other)
		:ElectronicDevice(other), resolution(other.resolution), refresh_rate(other.refresh_rate) {}
	Television& operator=(const Television&);
	virtual void show() const override;	
	~Television() override {} 
};

#endif
