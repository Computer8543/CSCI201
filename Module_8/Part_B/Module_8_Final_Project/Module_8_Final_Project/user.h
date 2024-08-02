/* Program name: user.h
*  Author: Kyle Ingersoll
*  Date last updated: 7/27/2024
*  Purpose: Create a ATM machine program using the concepts I learned in CSCI201. Store the class definition for the user class.
*/
#pragma once


#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include "account.h"


class user {
private:
	int userID; // read data from users.txt
	int PIN; // read data from users.txt
	std::map<int, account*> userAccounts; // read data from file 2 
public:
	// constructor
	user(int userID, int PIN, std::map<int, account*> userAccounts) throw (std::underflow_error, std::invalid_argument);
	// destructor needed because of the account pointers in the userAccounts map
	~user();
	
	// getter methods
	int getUserID() const;
	int getPIN() const;
	std::map<int, account*> getUserAccounts() const;

	// setter method
	void setUserAccounts(std::map<int, account*> userAccounts) throw (std::invalid_argument);

};
