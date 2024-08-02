/* Program name: user.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 7/27/2024
*  Purpose: Create a ATM machine program using the concepts I learned in CSCI201. Store the class methods for the user class.
*/

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include "account.h"
#include "user.h"

// constructor
user::user(int userID, int PIN, std::map<int, account*> userAccounts) throw (std::underflow_error, std::invalid_argument) {
	// do a little bit of input verification and exception handling
	try {
		if (userID < 0) {
			throw std::underflow_error("User ID cannot be a negative number.");
		}
		else {
			this->userID = userID;
		}
		if (userID < 0) {
			throw std::underflow_error("PIN cannot be a negative number.");
		}
		else {
			this->PIN = PIN;
		}
		if (userAccounts.empty() == true) {
			throw std::invalid_argument("Cannot create a user without any accounts.");
		}
		else {
			this->userAccounts = userAccounts;
		}
	}
	catch (std::underflow_error& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}

}
// destructor needed because of the account pointers in the userAccounts map
user::~user() {
	// initialize iterator
	std::map<int, account*>::iterator it;

	// delete account pointers to free up heap memory
	for (it = userAccounts.begin(); it != userAccounts.end(); it++)
	{
		delete it->second;
		it->second = NULL;
	}
}

// getter methods
int user::getUserID() const {
	return userID;
}

int user::getPIN() const {
	return PIN;
}

std::map<int, account*> user::getUserAccounts() const {
	return userAccounts;
}

// setter method
void user::setUserAccounts(std::map<int, account*> userAccounts) throw (std::invalid_argument) {
	try {
		if (userAccounts.empty() == true) {
			throw std::invalid_argument("Cannot create a user without any accounts.");
		}
		else {
			this->userAccounts = userAccounts;
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
}