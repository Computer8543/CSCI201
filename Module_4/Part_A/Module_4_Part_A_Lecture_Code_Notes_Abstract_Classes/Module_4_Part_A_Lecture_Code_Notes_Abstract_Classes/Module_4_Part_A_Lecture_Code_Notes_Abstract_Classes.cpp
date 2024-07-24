// Module_4_Part_A_Lecture_Code_Notes_Abstract_Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "GeometricObject.h"

// lhs = left hand side
// rhs = right hand side
bool operator<=(const Rectangle& lhs, const Rectangle& rhs) {
	return (lhs.getArea() <= rhs.getArea());
}

void operator*=(Rectangle& lhs, double scale) {
	lhs.length *= scale;
	lhs.width *= scale;
}

std::ostream& operator<<(std::ostream& os, const GeometricObject& object) {
	os << object.tostring();
	return os;
}

std::istream& operator>>(std::istream& is, GeometricObject& object) {
	std::string name;

	std::cout << "Enter name for object:";
	getline(is, name);
	object.setName(name);
	std::cout << std::endl;

	return is;
}
int main() {
	Circle myCircle(3.0);
	double size;

	std::cout << "Area = " << myCircle.getArea() << std::endl;

	std::cout << "How much larger would you like your circle?";
	std::cin >> size;
	myCircle += size;
	std::cout << std::endl;

	Rectangle myRectangle(3.0, 4.0);

	std::cout << "Area = " << myRectangle.getArea() << std::endl;


	Square mySquare(3.0);

	std::cout << "Area = " << myRectangle.getArea() << std::endl;

	Triangle myTriangle(3.0, 1.5);

	std::cout << "Area = " << myTriangle.getArea() << std::endl;

	if (mySquare > myCircle)
	{
		std::cout << "MySquare is greater than myCircle" << std::endl;
	}

	if (mySquare.operator<(myCircle))
	{
		std::cout << "MySquare is less than myCircle" << std::endl;
	}
	if (mySquare <= myRectangle) {
		std::cout << "Square is smaller!!!" << std::endl;
	}

	std::cin >> myRectangle;

	std::cout << myRectangle << std::endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
