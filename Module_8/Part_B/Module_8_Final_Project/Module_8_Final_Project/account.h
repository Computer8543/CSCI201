/* Program name: account.h
*  Author: Kyle Ingersoll
*  Date last updated: 7/24/2024
*  Purpose: Create a ATM machine program using the concepts I learned in CSCI201. Store the class definition for the account classes.
*/
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

// todo: add PIN verification to every transaction

// abstract class that the other account classes are based on
class account {
private:
	int accountID;
	double balance;
	const double overDraftFee = 50.00; // you can only alter the overdraft fee right here
	const double minimumBalance = 10.00; // you can only alter the minimum balance right here
public:
	// constructor
	account(int accountID, double balance) throw (std::underflow_error) {
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
	~account() {}

	// getters
	int getAccountID() const {
		return accountID;
	}

	double getBalance() const {
		return balance;
	}

	double getMinimumBalance() const {
		return minimumBalance;
	}

	double getOverDraftFee() const {
		return overDraftFee;
	}

	// setters
	void setAccountID(int accountID) throw (std::underflow_error) {
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

	void setBalance(double balance) throw (std::underflow_error) {
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
	void deposit(double moneyToBeDeposited) throw (std::underflow_error) {
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

	void withdraw(double moneyToBeWithdrawn) throw (std::underflow_error) {
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

	account& transfer(double moneyToBeTransferred, account& accountBeingTransferredFrom) throw (std::underflow_error) {
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
	virtual void checkToSeeIfBalanceIsBelowTheMinimumBalance() {
		if (balance < minimumBalance) {
			std::cout << "Closing account now due to not meeting the minimum balance." << std::endl;
			account::~account();
		}
	}

	// to string pure virtual function
	virtual std::string toString() = 0;
};

class checkingAccount : public account {
public:
	checkingAccount(int accountID, double balance) : account(accountID, balance) {}
	virtual void checkToSeeIfBalanceIsBelowTheMinimumBalance() {
		double balance = getBalance();
		double minimumBalance = getMinimumBalance();
		double overDraftFee = getOverDraftFee();

		if (balance < minimumBalance) {
			std::cout << "Charging overdraft fee of $" << overDraftFee << "." << std::endl;
			setBalance((balance - overDraftFee));
		}
	}
	virtual std::string tostring() {
		std::stringstream outputStream;

		outputStream << "Account ID is " << getAccountID() << " and balance is " << getBalance() << " for the checking account." << std::endl;

		return outputStream.str();
	}
};

class savingsAccount : public account {
private: 
	const double interestRate = 0.02; // you can only alter the interest rate right here
	time_t timeAccountWasCreated;
	int yearsSinceAccountCreation = 0; // since at the time of creation, the years since account creation would be zero
public:
	savingsAccount(int accountID, double balance) : account(accountID, balance) {
		this->timeAccountWasCreated = time(NULL); // makes the time the account was created the current time at the time of account creation
	}
	virtual void checkToSeeIfBalanceIsBelowTheMinimumBalance() {
		double balance = getBalance();
		double minimumBalance = getMinimumBalance();
		double overDraftFee = getOverDraftFee();

		if (balance < minimumBalance) {
			std::cout << "Charging overdraft fee of $" << overDraftFee << "." << std::endl;
			setBalance((balance - overDraftFee));
		}
	}
	void calculateYearsSinceAccountCreation() {
		const int numberOfSecondsInAYear = 31556952;

		time_t currentTime = time(NULL); // current time when calculating this function

		// the number of seconds between the current time and the time the account was created
		time_t timeInSecondsBetweenTheCurrentTimeAndTheTimeAccountWasCreated = difftime(currentTime, timeAccountWasCreated);

		// find the years since account creation
		yearsSinceAccountCreation = (int(timeInSecondsBetweenTheCurrentTimeAndTheTimeAccountWasCreated) / numberOfSecondsInAYear);
	}
	// only run this method once a year!
	void addInterestToBalance() throw (std::underflow_error) { 
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
	virtual std::string tostring() {
		std::stringstream outputStream;

		outputStream << "Account ID is " << getAccountID() << " and balance is " << getBalance() << " for the savings account." << std::endl;

		return outputStream.str();
	}
};


