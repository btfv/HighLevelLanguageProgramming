#include "angle.h"

Angle::Angle(double degrees) {
	this->degrees = degrees;
}
// return angle in degrees
double Angle::getDeg() {
	return this->degrees;
}
// set angle in degrees
void Angle::setDeg(double degrees) {
	this->degrees = degrees;
}
// return angle in radians
double Angle::getRad() {
	return this->degrees * M_PI / 180;
}