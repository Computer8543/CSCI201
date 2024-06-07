#pragma once // compile this file only once - include guard

#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

class bankaccount {
	// by default all access is "private"
	// public or private
private:
	Customer* customer;
	std::string accountNumber;
	double balance; // float 32 bits - double 64 bits
	int pin;
	string routing;

// methods can be used to give controlled access to attributes
public:
	// constructor - no return type. all it can return is a bank account 
	bankaccount(string account, double initialDeposit, int pinCode);

	// destructor - no return type
	~bankaccount();

	// accessor methods "getter methods"
	string getAccountNumber() const; // means that this method will not change anything
	double getBalance() const;
	string getRoutingNumber() const;

	string toString() const;
	}
	// setter or mutator methods
	double deposit(double amount, int pinCode);
	double withdraw(double amount, int pinCode);

	// bool resetPin(string SSN, string accountNumber, string accessCode, string newPin)

};