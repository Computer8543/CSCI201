/* Program name: date.h
*  Author: Kyle Ingersoll
*  Date last updated: 6/30/2024
*  Purpose: Demonstrate operator overloading in a class. This is the class prototype for the date class.
*/
#pragma once 

#include <iostream>

class date {
private:
	int day;
	int month;
	int year;
public:
	// parametized constructor
	date(int month, int day, int year) {
		// input validation for the constructor 
		// months must be between 1 and 12
		if (month < 1 || month > 12)
		{
			std::cout << "This is not a valid date. Setting values to January 1, 2000." << std::endl;
			this->month = 1;
			this->day = 1;
			this->year = 2000;
			return; // to prevent the program from going any further, we set up the program to return nothing, ending the program early
		}
		else {
			this->month = month;
		}
		
		// year numbers cannot be negative
		if (year < 0)
		{
			std::cout << "This is not a valid date. Setting values to January 1, 2000." << std::endl;
			this->month = 1;
			this->day = 1;
			this->year = 2000;
			return; // to prevent the program from going any further, we set up the program to return nothing, ending the program early
		}
		else {
			this->year = year;
		}

		// if the days goes over or under the number of days in a month, accounting for leap years in Febuary, output error message and set date to January 1st, 2000
		if ((month == 1 && (day < 1 || day > 31)) || (month == 2 && (day < 1 || (day > 28 && (year % 4 != 0 && year % 100 == 0) || year % 400 != 0)) || (day < 1 || day > 29 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))) || (month == 3 && (day < 1 || day > 31)) || (month == 4 && (day < 1 || day > 30)) || (month == 5 && (day < 1 || day > 31)) || (month == 6 && (day < 1 || day > 30)) || (month == 7 && (day < 1 || day > 31)) || (month == 8 && (day < 1 || day > 31)) || (month == 9 && (day < 1 || day > 30)) || (month == 10 && (day < 1 || day > 31)) || (month == 11 && (day < 1 || day > 30)) || (month == 12 && (day < 1 || day > 31)))
		{
			std::cout << "This is not a valid date. Setting values to January 1, 2000." << std::endl;
			this->month = 1;
			this->day = 1;
			this->year = 2000;
			return; // to prevent the program from going any further, we set up the program to return nothing, ending the program early
		}
		else {
			this->day = day;
		}

	}

};