#pragma once // compile this file only once - include guard

#include <iostream>
#include <string>

using namespace std;

class bankaccount {
	// by default all access is "private"
	// public or private
private:
	std::string accountNumber;
	double balance; // float 32 bits - double 64 bits
	int pin;
	string routing;

// methods can be used to give controlled access to attributes
public:
	// constructor - no return type. all it can return is a bank account 
	bankaccount(string account, double initialDeposit, int pinCode);

	// accessor methods "getter methods"
	string getAccountNumber();
	double getBalance();
	string getRoutingNumber();

	// setter or mutator methods
	double deposit(double amount, int pinCode);
	double withdraw(double amount, int pinCode);

	// bool resetPin(string SSN, string accountNumber, string accessCode, string newPin)

};