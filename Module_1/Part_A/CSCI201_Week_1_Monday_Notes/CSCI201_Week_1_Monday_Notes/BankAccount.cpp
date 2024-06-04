#include <iostream>
#include <string>
#include "BankAccount.h"

// methods can be used to give controlled access to attributes

// constructor - no return type. all it can return is a bank account 
bankaccount::bankaccount(string account, double initialDeposit, int pin) {
	accountNumber = account;
	balance = initialDeposit;
	routing = "045454";

}
// accessor methods "getter methods"
string bankaccount::getAccountNumber() {
	return accountNumber;
}
double bankaccount::getBalance() {
	return balance;
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

string bankaccount::getRoutingNumber() {
	return routing;
}