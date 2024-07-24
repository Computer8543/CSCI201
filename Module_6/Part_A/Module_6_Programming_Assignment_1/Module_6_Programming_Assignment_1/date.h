/* Program name: date.h
*  Author: Kyle Ingersoll
*  Date last updated: 7/13/2024
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
	date(int month, int day, int year);

	// method to determine if the year is a leap year or not
	bool isLeapYear();

	// operator overload methods
	bool operator!=(const date& otherDate) const;
	bool operator<(const date& otherDate) const;
	bool operator<=(const date& otherDate) const;
	bool operator==(const date& otherDate) const;
	bool operator>(const date& otherDate) const;
	bool operator>=(const date& otherDate) const;
	date operator++(); // prefix operator
	date operator++(int); // postfix operator 
	date operator--(); // prefix operator
	date operator--(int);  // postfix operator
	date& operator+(int daysToAdd);
	date& operator-(int daysToSub);

	// getter functions 
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	// setter functions
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	// friend operation overload functions
	friend date& operator+(int daysToAdd, date& addToDate);
	friend date& operator-(int daysToSub, date& subFromDate);
	friend std::istream& operator>>(std::istream& in, date& dateToFill);
	friend std::ostream& operator<<(std::ostream& out, date& dateToPrint);
};