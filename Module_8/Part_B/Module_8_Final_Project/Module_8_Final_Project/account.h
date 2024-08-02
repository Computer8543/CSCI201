/* Program name: account.h
*  Author: Kyle Ingersoll
*  Date last updated: 7/27/2024
*  Purpose: Create a ATM machine program using the concepts I learned in CSCI201. Store the class definition for the account classes.
*/
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

// todo: add PIN verification to every transaction
// todo: overload operators for accounts
// abstract class that the other account classes are based on
class account {
private:
	int accountID;
	double balance;
	const double overDraftFee = 50.00; // you can only alter the overdraft fee right here
	const double minimumBalance = 10.00; // you can only alter the minimum balance right here
public:
	// constructor
	account(int accountID, double balance) throw (std::underflow_error);
	// destructor placed so that it could be called
	~account();

	// getters
	int getAccountID() const;
	double getBalance() const;
	double getMinimumBalance() const;
	double getOverDraftFee() const;

	// setters
	void setAccountID(int accountID) throw (std::underflow_error);
	void setBalance(double balance) throw (std::underflow_error);

	// mutator methods
	void deposit(double moneyToBeDeposited) throw (std::underflow_error);
	void withdraw(double moneyToBeWithdrawn) throw (std::underflow_error);
	account& transfer(double moneyToBeTransferred, account& accountBeingTransferredFrom) throw (std::underflow_error);
	virtual void checkToSeeIfBalanceIsBelowTheMinimumBalance();

	// to string pure virtual function
	virtual std::string toString() = 0;
};

class checkingAccount : public account {
public:
	checkingAccount(int accountID, double balance);
	virtual void checkToSeeIfBalanceIsBelowTheMinimumBalance();
	virtual std::string toString();
};

class savingsAccount : public account {
private: 
	const double interestRate = 0.02; // you can only alter the interest rate right here
	time_t timeAccountWasCreated;
	int yearsSinceAccountCreation = 0; // since at the time of creation, the years since account creation would be zero
public:
	savingsAccount(int accountID, double balance);
	virtual void checkToSeeIfBalanceIsBelowTheMinimumBalance();
	void calculateYearsSinceAccountCreation();
	// only run this method once a year!
	void addInterestToBalance() throw (std::underflow_error);
	virtual std::string toString();
};


