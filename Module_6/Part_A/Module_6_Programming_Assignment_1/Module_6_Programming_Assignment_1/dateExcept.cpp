/* Program name: dateExcept.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 7/13/2024
*  Purpose: Demonstrate operator overloading in a class. This is the class definition for the dateException classses.
*/

#include <iostream>
#include <string>
#include "dateExcept.h"

invalid_day::invalid_day(std::string) : std::invalid_argument("The day is invalid.") {
	
}

invalid_month::invalid_month(std::string) : std::invalid_argument("The month is invalid.") {
	
}

invalid_year::invalid_year(std::string) : std::invalid_argument("The year is invalid.") {
	
}