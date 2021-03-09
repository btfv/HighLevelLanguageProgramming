#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class Angle {
private:
	double degrees;
public:
	Angle(double degrees) {
		this->degrees = degrees;
	}
	// return angle in degrees
	double getDeg() {
		return this->degrees;
	}
	// set angle in degrees
	void setDeg(double degrees) {
		this->degrees = degrees;
	}
	// return angle in radians
	double getRad() {
		return this->degrees * M_PI / 180;
	}
};