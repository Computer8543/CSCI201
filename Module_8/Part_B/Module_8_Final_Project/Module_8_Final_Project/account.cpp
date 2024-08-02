/* Program name: account.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 7/27/2024
*  Purpose: Create a ATM machine program using the concepts I learned in CSCI201. Store the class methods for the account classes.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "account.h"

// constructor
account::account(int accountID, double balance) throw (std::underflow_error) {
	try {
		if (accountID < 0) {
			throw std::underflow_error("The account ID cannot be less than 0.");
		}
		else {
			this->accountID = accountID;
		}
		if (balance < minimumBalance) {
			throw std::underflow_error("Balance cannot be less than the minimum balance.");
		}
		else {
			this->balance = balance;
		}

	}
	catch (std::underflow_error& e) {
		std::cerr << e.what() << std::endl;
	}
}
// destructor placed so that it could be called
account::~account() {}

// getters
int account::getAccountID() const {
	return accountID;
}

double account::getBalance() const {
	return balance;
}

double account::getMinimumBalance() const {
	return minimumBalance;
}

double account::getOverDraftFee() const {
	return overDraftFee;
}

// setters
void account::setAccountID(int accountID) throw (std::underflow_error) {
	try {
		if (accountID < 0) {
			throw std::underflow_error("The account ID cannot be less than 0.");
		}
		else {
			this->accountID = accountID;
		}
	}
	catch (std::underflow_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

void account::setBalance(double balance) throw (std::underflow_error) {
	try {
		if (balance < minimumBalance) {
			throw std::underflow_error("Balance cannot be less than the minimum balance.");
		}
		else {
			this->balance = balance;
		}
	}
	catch (std::underflow_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

// mutator methods
void account::deposit(double moneyToBeDeposited) throw (std::underflow_error) {
	try {
		if (balance < 0 || moneyToBeDeposited < 0)
		{
			throw std::underflow_error("Neither the balance or the money to be deposited can be less than 0.");
		}
		else {
			balance += moneyToBeDeposited;
		}
	}
	catch (std::underflow_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

void account::withdraw(double moneyToBeWithdrawn) throw (std::underflow_error) {
	try {
		if (balance < 0 || moneyToBeWithdrawn < 0)
		{
			throw std::underflow_error("Neither the balance or the money to be withdrawn can be less than 0.");
		}
		else if (moneyToBeWithdrawn > balance) {
			throw std::underflow_error("You cannot withdraw more money than you have in the account.");
		}
		else {
			balance -= moneyToBeWithdrawn;
		}
	}
	catch (std::underflow_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

account& account::transfer(double moneyToBeTransferred, account& accountBeingTransferredFrom) throw (std::underflow_error) {
	try {
		if (balance < 0 || moneyToBeTransferred < 0)
		{
			throw std::underflow_error("Neither the balance or the money to be transferred can be less than 0.");
		}
		else if (moneyToBeTransferred > accountBeingTransferredFrom.getBalance()) {
			throw std::underflow_error("You cannot transfer more money than you have in the account where the money is being transferred from.");
		}
		else {
			// subtract the transfer from the account being transfered from, and add the transfer to the account being transferred to.
			double accountBeingTransferredFromBalance = accountBeingTransferredFrom.getBalance();
			accountBeingTransferredFromBalance -= moneyToBeTransferred;
			accountBeingTransferredFrom.setBalance(accountBeingTransferredFromBalance);
			balance += moneyToBeTransferred;

			// return the whole altered object
			return *this;
		}
	}
	catch (std::underflow_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

// mutator function
void account::checkToSeeIfBalanceIsBelowTheMinimumBalance() {
	if (balance < minimumBalance) {
		std::cout << "Closing account now due to not meeting the minimum balance." << std::endl;
		account::~account();
	}
}

checkingAccount::checkingAccount(int accountID, double balance) : account(accountID, balance) {}
void checkingAccount::checkToSeeIfBalanceIsBelowTheMinimumBalance() {
	double balance = getBalance();
	double minimumBalance = getMinimumBalance();
	double overDraftFee = getOverDraftFee();

	if (balance < minimumBalance) {
		std::cout << "Charging overdraft fee of $" << overDraftFee << "." << std::endl;
		setBalance((balance - overDraftFee));
	}
}
std::string checkingAccount::toString() {
	std::stringstream outputStream;

	outputStream << "Account ID is " << getAccountID() << " and balance is " << getBalance() << " for the checking account." << std::endl;

	return outputStream.str();
}

savingsAccount::savingsAccount(int accountID, double balance) : account(accountID, balance) {
	this->timeAccountWasCreated = time(NULL); // makes the time the account was created the current time at the time of account creation
}
void savingsAccount::checkToSeeIfBalanceIsBelowTheMinimumBalance() {
	double balance = getBalance();
	double minimumBalance = getMinimumBalance();
	double overDraftFee = getOverDraftFee();

	if (balance < minimumBalance) {
		std::cout << "Charging overdraft fee of $" << overDraftFee << "." << std::endl;
		setBalance((balance - overDraftFee));
	}
}
void savingsAccount::calculateYearsSinceAccountCreation() {
	const int numberOfSecondsInAYear = 31556952;

	time_t currentTime = time(NULL); // current time when calculating this function

	// the number of seconds between the current time and the time the account was created
	time_t timeInSecondsBetweenTheCurrentTimeAndTheTimeAccountWasCreated = difftime(currentTime, timeAccountWasCreated);

	// find the years since account creation
	yearsSinceAccountCreation = (int(timeInSecondsBetweenTheCurrentTimeAndTheTimeAccountWasCreated) / numberOfSecondsInAYear);
}
// only run this method once a year!
void savingsAccount::addInterestToBalance() throw (std::underflow_error) {
	double balance = getBalance();
	try {
		if (yearsSinceAccountCreation > 0)
		{
			balance += (balance * interestRate);

		}
		else {
			throw std::underflow_error("An account must exist for one year before getting interest added to it.");
		}
	}
	catch (std::underflow_error& e) {
		std::cerr << e.what() << std::endl;
	}


}
std::string savingsAccount::toString() {
	std::stringstream outputStream;

	outputStream << "Account ID is " << getAccountID() << " and balance is " << getBalance() << " for the savings account." << std::endl;

	return outputStream.str();
}