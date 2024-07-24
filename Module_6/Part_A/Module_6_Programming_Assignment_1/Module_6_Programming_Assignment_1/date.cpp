/* Program name: date.h
*  Author: Kyle Ingersoll
*  Date last updated: 7/13/2024
*  Purpose: Demonstrate operator overloading in a class. This is the class definition for the date class.
*/

#include "date.h"
#include "dateExcept.h"
#include <iostream>

// parametized constructor
date::date(int month, int day, int year) {
	// input validation for the constructor 
	// months must be between 1 and 12
	if (month < 1 || month > 12)
	{
		throw invalid_month("The month is invalid.");
	}
	else {
		this->month = month;
	}

	// year numbers cannot be negative
	if (year < 0)
	{
		throw invalid_year("The year is invalid.");
	}
	else {
		this->year = year;
	}

	// if the days goes over or under the number of days in a month, accounting for leap years in Febuary, output error message and set date to January 1st, 2000
	if ((month == 1 && (day < 1 || day > 31)) || (month == 2 && (day < 1 || (day > 28 && (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)))) || (day < 1 || day > 29 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))) || (month == 3 && (day < 1 || day > 31)) || (month == 4 && (day < 1 || day > 30)) || (month == 5 && (day < 1 || day > 31)) || (month == 6 && (day < 1 || day > 30)) || (month == 7 && (day < 1 || day > 31)) || (month == 8 && (day < 1 || day > 31)) || (month == 9 && (day < 1 || day > 30)) || (month == 10 && (day < 1 || day > 31)) || (month == 11 && (day < 1 || day > 30)) || (month == 12 && (day < 1 || day > 31)))
	{
		throw invalid_day("The day is invalid.");
	}
	else {
		this->day = day;
	}

}

// method to determine if the year is a leap year or not
bool date::isLeapYear() {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

// operator overload methods
bool date::operator!=(const date& otherDate) const {
	// if all the variables of this object and the otherDate object match, return false, else return true.
	if (day == otherDate.day && month == otherDate.month && year == otherDate.year)
	{
		return false;
	}
	else {
		return true;
	}
}

bool date::operator<(const date& otherDate) const {
	// if any of the original object values are greater than or equal to the otherDate values, return false, else, return true.
	if (year < otherDate.year) {
		return true;
	}
	else if (year == otherDate.year && month < otherDate.month)
	{
		return true;
	}
	else if (year == otherDate.year && month == otherDate.month && day < otherDate.day)
	{
		return true;
	}
	else {
		return false;
	}
}

bool date::operator<=(const date& otherDate) const {
	// if any of the original object values are greater than the otherDate values, return false, else, return true.
	if (year <= otherDate.year) {
		return true;
	}
	else if (year == otherDate.year && month <= otherDate.month)
	{
		return true;
	}
	else if (year == otherDate.year && month == otherDate.month && day <= otherDate.day)
	{
		return true;
	}
	else {
		return false;
	}
}

bool date::operator==(const date& otherDate) const {
	// if any of the original object values are not equal to the otherDate values, return false, else, return true.
	if (day == otherDate.day && month == otherDate.month && year == otherDate.year) {
		return true;
	}
	else {
		return false;
	}
}

bool date::operator>(const date& otherDate) const {
	// if any of the original object values are less than or equal to the otherDate values, return false, else, return true.
	if (year > otherDate.year) {
		return true;
	}
	else if (year == otherDate.year && month > otherDate.month)
	{
		return true;
	}
	else if (year == otherDate.year && month == otherDate.month && day > otherDate.day)
	{
		return true;
	}
	else {
		return false;
	}
}

bool date::operator>=(const date& otherDate) const {
	// if any of the original object values are less than the otherDate values, return false, else, return true.
	if (year >= otherDate.year) {
		return true;
	}
	else if (year == otherDate.year && month >= otherDate.month)
	{
		return true;
	}
	else if (year == otherDate.year && month == otherDate.month && day >= otherDate.day)
	{
		return true;
	}
	else {
		return false;
	}
}

date date::operator++() { // prefix operator 
	// if it is the last day of the month, increase the month by 1 and set the day to 1, if it is the last day of the year, add 1 to the year, set the month to 1 and the day to 1, else add 1 to the day
	if ((month == 1 && day == 31) || (month == 2 && (day == 28 && (year % 4 != 0 && year % 100 == 0) || year % 400 != 0) || day == 29 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) || (month == 3 && day == 31) || (month == 4 && (day == 30)) || (month == 5 && (day == 31)) || (month == 6 && (day == 30)) || (month == 7 && (day == 31)) || (month == 8 && (day == 31)) || (month == 9 && (day == 30)) || (month == 10 && (day == 31)) || (month == 11 && (day == 30)))
	{
		this->month += 1;
		this->day = 1;
		return *this;
	}
	else if (month == 12 && day == 31)
	{
		this->year += 1;
		this->month = 1;
		this->day = 1;
		return *this;

	}
	else
	{
		this->day += 1;
		return *this;
	}
}

date date::operator++(int) { // postfix operator 
	// if it is the last day of the month, increase the month by 1 and set the day to 1, if it is the last day of the year, add 1 to the year, set the month to 1 and the day to 1, else add 1 to the day
	if ((month == 1 && day == 31) || (month == 2 && (day == 28 && (year % 4 != 0 && year % 100 == 0) || year % 400 != 0) || day == 29 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) || (month == 3 && day == 31) || (month == 4 && (day == 30)) || (month == 5 && (day == 31)) || (month == 6 && (day == 30)) || (month == 7 && (day == 31)) || (month == 8 && (day == 31)) || (month == 9 && (day == 30)) || (month == 10 && (day == 31)) || (month == 11 && (day == 30)))
	{
		this->month += 1;
		this->day = 1;
		return *this;
	}
	else if (month == 12 && day == 31)
	{
		this->year += 1;
		this->month = 1;
		this->day = 1;
		return *this;

	}
	else
	{
		this->day += 1;
		return *this;
	}
}

date date::operator--() { // prefix operator
	// if it is the first day of the month other than January 1st, reduce month by 1 and set it to the last day of the month, if it is January 1st, reduce the year by 1 and set it to December 31st, else reduce the day by 1
	if ((month == 2 || month == 3 || month == 4 || month == 5 || month == 6 || month == 7 || month == 8 || month == 9 || month == 10 || month == 11 || month == 12) && day == 1)
	{
		this->month -= 1;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			this->day = 31;
			return *this;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			this->day = 30;
			return *this;
		}
		else if (month == 2 && ((year % 4 != 0 && year % 100 == 0) || year % 400 != 0))
		{
			this->day = 28;
			return *this;
		}
		else if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			this->day = 29;
			return *this;
		}
		else {
			return *this;
		}
	}
	else if (month == 1 && day == 1)
	{
		this->year -= 1;
		this->month = 12;
		this->day = 31;
		return *this;
	}
	else {
		this->day -= 1;
		return *this;
	}

}

date date::operator--(int) { // postfix operator
	// if it is the first day of the month other than January 1st, reduce month by 1 and set it to the last day of the month, if it is January 1st, reduce the year by 1 and set it to December 31st, else reduce the day by 1
	if ((month == 2 || month == 3 || month == 4 || month == 5 || month == 6 || month == 7 || month == 8 || month == 9 || month == 10 || month == 11 || month == 12) && day == 1)
	{
		this->month -= 1;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			this->day = 31;
			return *this;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			this->day = 30;
			return *this;
		}
		else if (month == 2 && ((year % 4 != 0 && year % 100 == 0) || year % 400 != 0))
		{
			this->day = 28;
			return *this;
		}
		else if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			this->day = 29;
			return *this;
		}
		else {
			return *this;
		}
	}
	else if (month == 1 && day == 1)
	{
		this->year -= 1;
		this->month = 12;
		this->day = 31;
		return *this;
	}
	else {
		this->day -= 1;
		return *this;
	}

}

date& date::operator+(int daysToAdd) {
	// this is an approximate solution, it will only be inaccurate by about a few days or so as long as you aren't adding a huge number of days.
	// you can't just add the days since they sit within months and years which you have to convert them too.

	for (int i = 0; i < daysToAdd; i++)
	{
		operator++(0);
	}
	return *this;
}

date& date::operator-(int daysToSub) {
	// this is an approximate solution, it will only be inaccurate by about a few days or so as long as you aren't adding a huge number of days.
	// you can't just subtract the days since they sit within months and years which you have to convert them too.

	for (int i = 0; i < daysToSub; i++)
	{
		operator--(0);
	}
	return *this;
}

// getter functions 
int date::getDay() const {
	return day;
}

int date::getMonth() const {
	return month;
}

int date::getYear() const {
	return year;
}

// setter functions
void date::setDay(int day) {
	// if the days goes over or under the number of days in a month, accounting for leap years in Febuary, output error message and set date to January 1st, 2000
	if ((month == 1 && (day < 1 || day > 31)) || (month == 2 && (day < 1 || (day > 28 && (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)))) || (day < 1 || day > 29 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))) || (month == 3 && (day < 1 || day > 31)) || (month == 4 && (day < 1 || day > 30)) || (month == 5 && (day < 1 || day > 31)) || (month == 6 && (day < 1 || day > 30)) || (month == 7 && (day < 1 || day > 31)) || (month == 8 && (day < 1 || day > 31)) || (month == 9 && (day < 1 || day > 30)) || (month == 10 && (day < 1 || day > 31)) || (month == 11 && (day < 1 || day > 30)) || (month == 12 && (day < 1 || day > 31)))
	{
		throw invalid_day("The day is invalid.");
	}
	else {
		this->day = day;
	}
}

void date::setMonth(int month) {
	// months must be between 1 and 12
	if (month < 1 || month > 12)
	{
		throw invalid_month("The month is invalid.");
	}
	else {
		this->month = month;
	}
}

void date::setYear(int year) {
	// year numbers cannot be negative
	if (year < 0)
	{
		throw invalid_year("The year is invalid.");
	}
	else {
		this->year = year;
	}
}

// friend operation overload functions
date& operator+(int daysToAdd, date& addToDate) {
	// this is an approximate solution, it will only be inaccurate by about a few days or so as long as you aren't adding a huge number of days.
	// you can't just add the days since they sit within months and years which you have to convert them too.

	for (int i = 0; i < daysToAdd; i++)
	{
		addToDate.operator++(0);
	}
	return addToDate;
}

date& operator-(int daysToSub, date& subFromDate) {
	// this is an approximate solution, it will only be inaccurate by about a few days or so as long as you aren't adding a huge number of days.
	// you can't just subtract the days since they sit within months and years which you have to convert them too.


	for (int i = 0; i < daysToSub; i++)
	{
		subFromDate.operator--(0);
	}
	return subFromDate;
}

std::istream& operator>>(std::istream& in, date& dateToFill) {
	in >> dateToFill.month;

	// input verification
	do {
		if (!(in))
		{
			throw invalid_month("The month is invalid.");
		}
		else if (dateToFill.month < 1 || dateToFill.month > 12)
		{
			throw invalid_month("The month is invalid.");
		}
		else {
			break;
		}

	} while (true);
	in >> dateToFill.day;

	// input verification
	do {
		if (!(in))
		{
			throw invalid_day("The day is invalid.");
		}
		else if ((dateToFill.month == 1 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 2 && (dateToFill.day < 1 || dateToFill.day > 29)) || (dateToFill.month == 3 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 4 && (dateToFill.day < 1 || dateToFill.day > 30)) || (dateToFill.month == 5 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 6 && (dateToFill.day < 1 || dateToFill.day > 30)) || (dateToFill.month == 7 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 8 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 9 && (dateToFill.day < 1 || dateToFill.day > 30)) || (dateToFill.month == 10 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 11 && (dateToFill.day < 1 || dateToFill.day > 30)) || (dateToFill.month == 12 && (dateToFill.day < 1 || dateToFill.day > 31)))
		{
			throw invalid_day("The day is invalid.");
		}
		else {
			break;
		}

	} while (true);

	in >> dateToFill.year;

	// input verification
	do {
		if (!(in))
		{
			throw invalid_year("The year is invalid.");
			continue;
		}
		else if (dateToFill.year < 0)
		{
			throw invalid_year("The year is invalid.");
			continue;
		}
		else {
			break;
		}
	} while (true);

	return in;
}

std::ostream& operator<<(std::ostream& out, date& dateToPrint) {
	out << dateToPrint.year << "-";

	// make sure month prints double digits
	if (dateToPrint.month < 10)
	{
		out << "0" << dateToPrint.month << "-";
	}
	else {
		out << dateToPrint.month << "-";
	}

	// make sure day prints double digits
	if (dateToPrint.day < 10)
	{
		out << "0" << dateToPrint.day;
	}
	else {
		out << dateToPrint.day;
	}

	return out;
}