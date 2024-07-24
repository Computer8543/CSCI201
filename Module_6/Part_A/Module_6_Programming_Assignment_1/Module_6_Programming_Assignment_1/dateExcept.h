/* Program name: dateExcept.h
*  Author: Kyle Ingersoll
*  Date last updated: 7/13/2024
*  Purpose: Demonstrate operator overloading in a class. This is the class prototype for the dateException classses.
*/
#pragma once

#include <iostream>
#include <string>

class invalid_day : public std::invalid_argument {
public:
	invalid_day(std::string);
};

class invalid_month : public std::invalid_argument {
public:
	invalid_month(std::string);
};

class invalid_year : public std::invalid_argument {
public:
	invalid_year(std::string);
};