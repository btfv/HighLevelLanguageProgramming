#include "triangle.h"
#include "angle.h"

Triangle::Triangle(double side_length, double left_angle, double right_angle) {
	this->a_side = side_length;
	this->left_ang = new Angle(left_angle);
	this->right_ang = new Angle(right_angle);
}
void Triangle::calculateSides() {
	double b_side = a_side * sin(left_ang->getRad()) / sin(left_ang->getRad() + right_ang->getRad());
	double c_side = a_side * sin(right_ang->getRad()) / sin(left_ang->getRad() + right_ang->getRad());
	std::cout << "A side length: " << this->a_side << "\n";
	std::cout << "B side length: " << b_side << "\n";
	std::cout << "C side length: " << c_side << "\n";
}
void Triangle::calculateBisectors() {
	double b_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(right_ang->getRad());
	double c_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(left_ang->getRad());

	double first_bisector = sqrt(this->a_side * b_side * (this->a_side + b_side - c_side) * (this->a_side + b_side + c_side)) / (this->a_side + b_side);
	double second_bisector = sqrt(b_side * c_side * (b_side + c_side - this->a_side) * (b_side + c_side + this->a_side)) / (b_side + c_side);
	double third_bisector = sqrt(this->a_side * c_side * (this->a_side + c_side - b_side) * (this->a_side + c_side + b_side)) / (this->a_side + c_side);

	std::cout << "First bisector length: " << first_bisector << "\n";
	std::cout << "Second bisector length: " << second_bisector << "\n";
	std::cout << "Third bisector length: " << third_bisector << "\n";
}

double Triangle::getSquare() const {
	double b_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(right_ang->getRad());
	double c_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(left_ang->getRad());

	double p = (a_side + b_side + c_side) / 2;
	return sqrt(p * (p - a_side) * (p - b_side) * (p - c_side));
}
bool Triangle::operator== (const Triangle& B) {
	std::cout << "DDQWEQWWEQW";
	return (this->getSquare() == B.getSquare());
}
