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
	std::cout << "Длина стороны А: " << this->a_side << "\n";
	std::cout << "Длина стороны B: " << b_side << "\n";
	std::cout << "Длина стороны C: " << c_side << "\n";
}
void Triangle::calculateBisectors() {
	double b_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(right_ang->getRad());
	double c_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(left_ang->getRad());

	double first_bisector = sqrt(this->a_side * b_side * (this->a_side + b_side - c_side) * (this->a_side + b_side + c_side)) / (this->a_side + b_side);
	double second_bisector = sqrt(b_side * c_side * (b_side + c_side - this->a_side) * (b_side + c_side + this->a_side)) / (b_side + c_side);
	double third_bisector = sqrt(this->a_side * c_side * (this->a_side + c_side - b_side) * (this->a_side + c_side + b_side)) / (this->a_side + c_side);

	std::cout << "Длина первой биссектрисы: " << first_bisector << "\n";
	std::cout << "Длина второй биссектрисы: " << second_bisector << "\n";
	std::cout << "Длина третьей биссектрисы: " << third_bisector << "\n";
}

double Triangle::getSquare() const {
	double b_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(right_ang->getRad());
	double c_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(left_ang->getRad());

	double p = (a_side + b_side + c_side) / 2;
	return sqrt(p * (p - a_side) * (p - b_side) * (p - c_side));
}
bool Triangle::operator== (const Triangle& B) {
	return (this->getSquare() == B.getSquare());
}
std::ostream& Triangle::operator<< (std::ostream& os) {
	double b_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(right_ang->getRad());
	double c_side = a_side * sin(left_ang->getRad() + right_ang->getRad()) / sin(left_ang->getRad());
	os << "A: " << a_side << "\n";
	os << "B: " << b_side << "\n";
	os << "C: " << c_side << "\n";
	return os;
}
