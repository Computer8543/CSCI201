#include <stdexcept>
#include <iostream>

Circle::Circle(double rad) {
	if (radius <= 0.0) {
		throw std::invalid_argument("radius cannot be less than or equal to 0!!!")
	}
	radius = rad;
}
Circle::Circle(int rad) {
	radius = rad;
}
// default constructor 
Circle::Circle() {
	radius = 1.0;
}
// destructor method
Circle::~Circle() {
	std::cout << "Destroying Circle";
}
// accessor methods
double Circle::getArea() const {
	return 3.1415 * radius * radius;

}
double Circle::getRadius() const {
	return radius;
}
// mutator method
void Circle::setRadius(double rad) {
	radius = rad;
}
