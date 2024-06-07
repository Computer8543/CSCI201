#include <iostream>
#include <string>
#include "BankAccount.h"

// methods can be used to give controlled access to attributes

// constructor - no return type. all it can return is a bank account 
bankaccount::bankaccount(string account, double initialDeposit, int pinCode) {
	accountNumber = account;
	balance = initialDeposit;
	routing = "045454";
	pin = pinCode;
	cout << "Creating account " << accountNumber << endl;
}

// destructor - no return type.
bankaccount::~bankaccount() {
	// if there is any cleanup that needs to be done when "deleting" an object - do it here. 
	std::cout << "Closing Account " << accountNumber << std::endl;

	if (balance > 0) {
		std::cout << "Issuing Check for $" << balance << std::endl;
	}
	else if (balance < 0) {
		std::cout << "Turning Account over to collections!!!" << std::endl;
	}
}
// accessor methods "getter methods"
string bankaccount::getAccountNumber() const {
	return accountNumber;
}
double bankaccount::getBalance() const {
	return balance;
}
string bankaccount::toString() const {
	string result "Account: " << accountNumber << "has a balance of " << to_string(balance);
}
double bankaccount::deposit(double amount, int pinCode) {
	if (amount < 0)
		throw invalid_argument("cannot deposit less than zero");
	if (pin != pinCode)
		throw invalid_argument("Invalid operation!!!")
	balance += amount;
	return balance;
}
double bankaccount::withdraw(double amount, int pinCode) {
	if (amount < 0)
		throw invalid_argument("cannot withdraw less than zero");
	if (pin != pinCode)
		throw invalid_argument("Invalid operation!!!")
	if (amount > balance)
		// amount = balance; or 
		throw invalid_argument("insufficient funds");

	balance -= amount;
	return balance;
}

string bankaccount::getRoutingNumber() const {
	return routing;
}