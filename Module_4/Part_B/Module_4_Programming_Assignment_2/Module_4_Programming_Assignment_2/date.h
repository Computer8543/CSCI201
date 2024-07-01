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

	// method to determine if the year is a leap year or not
	bool isLeapYear() {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}

	// operator overload methods
	bool operator!=(const date& otherDate) const {
		// if all the variables of this object and the otherDate object match, return false, else return true.
		if (this->day == otherDate.day && this->month == otherDate.month && this->year == otherDate.year)
		{
			return false;
		}
		else {
			return true;
		}
	}

	bool operator<(const date& otherDate) const {
		// if any of the original object values are greater than or equal to the otherDate values, return false, else, return true.
		if (this->day >= otherDate.day || this->month >= otherDate.month || this->year >= otherDate.year) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator<=(const date& otherDate) const {
		// if any of the original object values are greater than the otherDate values, return false, else, return true.
		if (this->day > otherDate.day || this->month > otherDate.month || this->year > otherDate.year) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator==(const date& otherDate) const {
		// if any of the original object values are not equal to the otherDate values, return false, else, return true.
		if (this->day != otherDate.day || this->month != otherDate.month || this->year != otherDate.year) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator>(const date& otherDate) const {
		// if any of the original object values are less than or equal to the otherDate values, return false, else, return true.
		if (this->day <= otherDate.day || this->month <= otherDate.month || this->year <= otherDate.year) {
			return false;
		}
		else {
			return true;
		}
	}
	
	bool operator>=(const date& otherDate) const {
		// if any of the original object values are less than the otherDate values, return false, else, return true.
		if (this->day < otherDate.day || this->month < otherDate.month || this->year < otherDate.year) {
			return false;
		}
		else {
			return true;
		}
	}

	date operator++() { // prefix operator 
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

	date operator++(int) { // postfix operator 
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

	date operator--() { // prefix operator
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

	date operator--(int) { // postfix operator
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

	date& operator+(int daysToAdd) {
		// this is an approximate solution, it will only be inaccurate by about a few days or so as long as you aren't adding a huge number of days.
		// you can't just add the days since they sit within months and years which you have to convert them too.

		// initialize variables
		int yearsToSubtract = 0;
		int monthsToSubtract = 0;

		if (daysToAdd % 365 == 0)
		{
			year += (daysToAdd / 365);
			return *this;

		}
		else if (daysToAdd % 366 == 0)
		{
			year += (daysToAdd / 366);
			return *this;
		}
		else if (daysToAdd % 31 == 0)
		{
			month += (daysToAdd / 31);
			return *this;
		}
		else if (daysToAdd % 30 == 0)
		{
			month += (daysToAdd / 30);
			return *this;
		}
		else if (daysToAdd % 29 == 0)
		{
			month += (daysToAdd / 29);
			return *this;
		}
		else if (daysToAdd % 28 == 0)
		{
			month += (daysToAdd / 28);
			return *this;
		}
		else if ((day + daysToAdd) < 28)
		{
			day += daysToAdd;
			return *this;
		}
		else {
			// since the daysToAdd and the private variables are ints, the quotient will also be an integer
			year += (daysToAdd / 365);
			yearsToSubtract += (daysToAdd / 365);
			daysToAdd -= (yearsToSubtract * 365);
			month += (daysToAdd / 28);
			monthsToSubtract += (daysToAdd / 28);
			daysToAdd -= (monthsToSubtract * 28);
			day += daysToAdd;
			return *this;

		}
	}

	date& operator-(int daysToSub) {
		// this is an approximate solution, it will only be inaccurate by about a few days or so as long as you aren't adding a huge number of days.
		// you can't just subtract the days since they sit within months and years which you have to convert them too.

		// initialize variables
		int yearsToSubtract = 0;
		int monthsToSubtract = 0;

		if (daysToSub % 365 == 0)
		{
			year -= (daysToSub / 365);
			return *this;

		}
		else if (daysToSub % 366 == 0)
		{
			year -= (daysToSub / 366);
			return *this;
		}
		else if (daysToSub % 31 == 0)
		{
			month -= (daysToSub / 31);
			return *this;
		}
		else if (daysToSub % 30 == 0)
		{
			month -= (daysToSub / 30);
			return *this;
		}
		else if (daysToSub % 29 == 0)
		{
			month -= (daysToSub / 29);
			return *this;
		}
		else if (daysToSub % 28 == 0)
		{
			month -= (daysToSub / 28);
			return *this;
		}
		else if ((day + daysToSub) < 28)
		{
			day -= daysToSub;
			return *this;
		}
		else {
			// since the daysToAdd and the private variables are ints, the quotient will also be an integer
			year -= (daysToSub / 365);
			yearsToSubtract += (daysToSub / 365);
			daysToSub -= (yearsToSubtract * 365);
			month -= (daysToSub / 28);
			monthsToSubtract += (daysToSub / 28);
			daysToSub -= (monthsToSubtract * 28);
			day -= daysToSub;
			return *this;

		}
	}

	// getter functions 
	int getDay() const {
		return day;
	}

	int getMonth() const {
		return month;
	}

	int getYear() const {
		return year;
	}

	// setter functions
	void setDay(int day) {
		// if the days goes over or under the number of days in a month, accounting for leap years in Febuary, output error message and set date to January 1st, 2000
		if ((month == 1 && (day < 1 || day > 31)) || (month == 2 && (day < 1 || (day > 28 && (year % 4 != 0 && year % 100 == 0) || year % 400 != 0)) || (day < 1 || day > 29 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))) || (month == 3 && (day < 1 || day > 31)) || (month == 4 && (day < 1 || day > 30)) || (month == 5 && (day < 1 || day > 31)) || (month == 6 && (day < 1 || day > 30)) || (month == 7 && (day < 1 || day > 31)) || (month == 8 && (day < 1 || day > 31)) || (month == 9 && (day < 1 || day > 30)) || (month == 10 && (day < 1 || day > 31)) || (month == 11 && (day < 1 || day > 30)) || (month == 12 && (day < 1 || day > 31)))
		{
			std::cout << "This is not a valid date. The days of the month cannot be less than 1 or more than the respective last day of the month." << std::endl;
			return; // to prevent the program from going any further, we set up the program to return nothing, ending the program early
		}
		else {
			this->day = day;
		}
	}

	void setMonth(int month) {
		// months must be between 1 and 12
		if (month < 1 || month > 12)
		{
			std::cout << "This is not a valid date. Months must be between 1 and 12" << std::endl;
			return; // to prevent the program from going any further, we set up the program to return nothing, ending the program early
		}
		else {
			this->month = month;
		}
	}

	void setYear(int year) {
		// year numbers cannot be negative
		if (year < 0)
		{
			std::cout << "This is not a valid date. Years cannot be less than 0." << std::endl;
			return; // to prevent the program from going any further, we set up the program to return nothing, ending the program early
		}
		else {
			this->year = year;
		}
	}

	// friend operation overload functions
	friend date& operator+(int daysToAdd, date& addToDate) {
		// this is an approximate solution, it will only be inaccurate by about a few days or so as long as you aren't adding a huge number of days.
		// you can't just add the days since they sit within months and years which you have to convert them too.

		// initialize variables
		int yearsToSubtract = 0;
		int monthsToSubtract = 0;

		if (daysToAdd % 365 == 0)
		{
			addToDate.year += (daysToAdd / 365);
			return addToDate;

		}
		else if (daysToAdd % 366 == 0)
		{
			addToDate.year += (daysToAdd / 366);
			return addToDate;
		}
		else if (daysToAdd % 31 == 0)
		{
			addToDate.month += (daysToAdd / 31);
			return addToDate;
		}
		else if (daysToAdd % 30 == 0)
		{
			addToDate.month += (daysToAdd / 30);
			return addToDate;
		}
		else if (daysToAdd % 29 == 0)
		{
			addToDate.month += (daysToAdd / 29);
			return addToDate;
		}
		else if (daysToAdd % 28 == 0)
		{
			addToDate.month += (daysToAdd / 28);
			return addToDate;
		}
		else if ((addToDate.day + daysToAdd) < 28)
		{
			addToDate.day += daysToAdd;
			return addToDate;
		}
		else {
			// since the daysToAdd and the private variables are ints, the quotient will also be an integer
			addToDate.year += (daysToAdd / 365);
			yearsToSubtract += (daysToAdd / 365);
			daysToAdd -= (yearsToSubtract * 365);
			addToDate.month += (daysToAdd / 28);
			monthsToSubtract += (daysToAdd / 28);
			daysToAdd -= (monthsToSubtract * 28);
			addToDate.day += daysToAdd;
			return addToDate;

		}
	}

	friend date& operator-(int daysToSub, date& subFromDate) {
		// this is an approximate solution, it will only be inaccurate by about a few days or so as long as you aren't adding a huge number of days.
		// you can't just subtract the days since they sit within months and years which you have to convert them too.

		// initialize variables
		int yearsToSubtract = 0;
		int monthsToSubtract = 0;

		if (daysToSub % 365 == 0)
		{
			subFromDate.year -= (daysToSub / 365);
			return subFromDate;

		}
		else if (daysToSub % 366 == 0)
		{
			subFromDate.year -= (daysToSub / 366);
			return subFromDate;
		}
		else if (daysToSub % 31 == 0)
		{
			subFromDate.month -= (daysToSub / 31);
			return subFromDate;
		}
		else if (daysToSub % 30 == 0)
		{
			subFromDate.month -= (daysToSub / 30);
			return subFromDate;
		}
		else if (daysToSub % 29 == 0)
		{
			subFromDate.month -= (daysToSub / 29);
			return subFromDate;
		}
		else if (daysToSub % 28 == 0)
		{
			subFromDate.month -= (daysToSub / 28);
			return subFromDate;
		}
		else if ((subFromDate.day + daysToSub) < 28)
		{
			subFromDate.day -= daysToSub;
			return subFromDate;
		}
		else {
			// since the daysToAdd and the private variables are ints, the quotient will also be an integer
			subFromDate.year -= (daysToSub / 365);
			yearsToSubtract += (daysToSub / 365);
			daysToSub -= (yearsToSubtract * 365);
			subFromDate.month -= (daysToSub / 28);
			monthsToSubtract += (daysToSub / 28);
			daysToSub -= (monthsToSubtract * 28);
			subFromDate.day -= daysToSub;
			return subFromDate;

		}
	}

	friend std::istream& operator>>(std::istream& in, date& dateToFill) {
		in >> dateToFill.month;

		// input verification
		do {
			if (!(in))
			{
				in.clear();
				in.ignore(200, '\n');
				std::cout << "This is not a valid date. Please enter in a number between 1 and 12." << std::endl;
				in >> dateToFill.month;
				continue;
			}
			else if (dateToFill.month < 1 || dateToFill.month > 12)
			{
				std::cout << "This is not a valid date. Please enter in a number between 1 and 12." << std::endl;
				in >> dateToFill.month;
				continue;
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
				in.clear();
				in.ignore(200, '\n');
				std::cout << "This is not a valid date. Please enter in a number between 1 and the respective last day of the month." << std::endl;
				in >> dateToFill.day;
				continue;
			}
			else if ((dateToFill.month == 1 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 2 && (dateToFill.day < 1 || dateToFill.day > 29)) || (dateToFill.month == 3 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 4 && (dateToFill.day < 1 || dateToFill.day > 30)) || (dateToFill.month == 5 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 6 && (dateToFill.day < 1 || dateToFill.day > 30)) || (dateToFill.month == 7 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 8 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 9 && (dateToFill.day < 1 || dateToFill.day > 30)) || (dateToFill.month == 10 && (dateToFill.day < 1 || dateToFill.day > 31)) || (dateToFill.month == 11 && (dateToFill.day < 1 || dateToFill.day > 30)) || (dateToFill.month == 12 && (dateToFill.day < 1 || dateToFill.day > 31)))
			{
				std::cout << "This is not a valid date. Please enter in a number between 1 and the respective last day of the month." << std::endl;
				in >> dateToFill.day;
				continue;
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
				in.clear();
				in.ignore(200, '\n');
				std::cout << "This is not a valid date. Please enter in a number greater than or equal to 0." << std::endl;
				in >> dateToFill.year;
				continue;
			}
			else if (dateToFill.year < 0)
			{
				std::cout << "This is not a valid date. Please enter in a number greater than or equal to 0." << std::endl;
				in >> dateToFill.year;
				continue;
			}
			else {
				break;
			}
		} while (true);

		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, date& dateToPrint) {
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
};