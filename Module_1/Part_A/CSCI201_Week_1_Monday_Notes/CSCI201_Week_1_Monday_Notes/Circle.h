#pragma once
#include <stdexcept>
#include <iostream>
class Circle {
private:
	double radius;
public:
	Circle(double rad);
	Circle(int rad);
	// default constructor 
	Circle();  // unit circle
	// destructor method
	~Circle();
	// accessor methods
	double getArea() const;
	double getRadius() const;
	// mutator method
	void setRadius(double rad);
};