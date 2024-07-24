#pragma once

#include <iostream>
#include <string>

class GeometricObject {
private:
	std::string name;
public:
	GeometricObject(std::string name);
	~GeometricObject();
	std::string getName();
	void setName(std::string name);
	virtual double getArea() const = 0; // pure virtual function - means it has no implementation
	// Cannot create an object with a pure virtual function
	virtual std::string tostring() const;
	bool operator>(const GeometricObject& other);
	bool operator<(const GeometricObject& other);
};
class Polygon : public GeometricObject {
private:
	int numSides;
public:
	Polygon(int sides, std::string name) : GeometricObject("Polygon");
	int getNumSides();
};

class Circle : public GeometricObject {
private:
	double radius;
public:
	Circle(double radius) : GeometricObject("Circle");
	~Circle();
	double getArea() const;
	void operator+=(double increase);
	Circle& operator++(); // prefix version
	Circle& operator++(int); // postfix version
};

class Rectangle : public GeometricObject {
	friend void operator*=(Rectangle& lhs, double scale); // DON'T DO THIS!!! Potential secure programming issue.
private:
	double length;
	double width;
public:
	Rectangle(double length, double width) : GeometricObject("Rectangle");
	~Rectangle();
	double getArea() const;
};

class Square : public Rectangle {
private:
	double side;
public:
	Square(double side) : Rectangle(side, side);
	~Square();
	double getArea() const;
};
class Triangle : public GeometricObject {
private:
	double base;
	double height;
public:
	Triangle(double base, double height) : GeometricObject("Triangle");
	~Triangle();
	double getArea() const;
};