#pragma once

#ifndef CIRCLE_H
#define CIRCLE_H
class Circle {
private:
	double radius;
public:
	explicit Circle(double rad) {
		radius = rad;
	}
	double getRadius() {
		return radius;
	}
};
#endif 