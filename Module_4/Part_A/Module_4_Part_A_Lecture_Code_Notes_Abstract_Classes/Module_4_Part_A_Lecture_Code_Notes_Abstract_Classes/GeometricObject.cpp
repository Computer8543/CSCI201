
#include <iostream>
#include <string>
#include "GeometricObject.h"


GeometricObject::GeometricObject(std::string name) {
	this->name = name;
	std::cout << "Creating Geometric Object" << std::endl;
}
GeometricObject::~GeometricObject() {
	std::cout << "Deleting Geometric Object" << std::endl;
}
std::string GeometricObject::getName() {
	return name;
}
void GeometricObject::setName(std::string name) {
	this->name = name;
}
bool GeometricObject::operator>(const GeometricObject& other) {
	return this->getArea() > other.getArea();
}
bool GeometricObject::operator<(const GeometricObject& other) {
	return this->getArea() < other.getArea();
}
std::string GeometricObject::tostring() const {
	return "Geometric Object";
}
Circle& Circle::operator++() // prefix version
{
	this->radius += 1.0;
	return *this;
}
Circle& Circle::operator++(int) { // postfix version
	this->radius += 1.0;
	return *this;
}


Polygon::Polygon(int sides, std::string name) : GeometricObject("Polygon")
{
	numSides = sides;
	std::cout << "Creating Polygon" << std::endl;
}
int Polygon::getNumSides() {
	return numSides;
}



Circle::Circle(double radius) : GeometricObject("Circle") {
	this->radius = radius;
	std::cout << "Creating Circle" << std::endl;
}
Circle::~Circle() {
	std::cout << "Destroying Circle" << std::endl;
}
double Circle::getArea() const {
	return (3.1415927 * radius * radius);
}
void Circle::operator+=(double increase) {
	radius += increase;
}


Rectangle::Rectangle(double length, double width) : GeometricObject("Rectangle") {
	this->length = length;
	this->width = width;

	std::cout << "Creating Rectangle" << std::endl;
}
Rectangle::~Rectangle() {
	std::cout << "Destroying Rectangle" << std::endl;
}
double Rectangle::getArea() const {
	return (length * width);
}



Square::Square(double side) : Rectangle(side, side) {
	this->side = side;

	std::cout << "Creating Square" << std::endl;
}
Square::~Square() {
	std::cout << "Destroying Square" << std::endl;
}
double Square::getArea() const {
	return (side * side);
}


Triangle::Triangle(double base, double height) : GeometricObject("Triangle") {
	this->base = base;
	this->height = height;

	std::cout << "Creating Triangle" << std::endl;
}
Triangle::~Triangle() {
	std::cout << "Destroying Triangle" << std::endl;
}
double Triangle::getArea() const {
	return (0.5 * height * base);
}
