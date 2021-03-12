#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class Angle {
private:
	double degrees;
public:
	Angle(double);
	// return angle in degrees
	double getDeg();
	// set angle in degrees
	void setDeg(double);
	// return angle in radians
	double getRad();
};