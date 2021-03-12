#pragma once
#include <iostream>
#include <math.h>
#include "angle.h"

class Triangle {
private:
	// side length
	double a_side;
	// two angles
	Angle* left_ang;
	Angle* right_ang;
public:
	Triangle(double, double, double);
	void calculateSides();
	void calculateBisectors();
	double getSquare() const;

	bool operator== (const Triangle&);
	std::ostream& operator<< (std::ostream&);
};