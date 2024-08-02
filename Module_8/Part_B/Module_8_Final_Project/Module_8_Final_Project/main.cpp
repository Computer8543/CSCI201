/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 7/27/2024
*  Purpose: Create a ATM machine program using the concepts I learned in CSCI201.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "user.h"
#include "account.h"

// global constants
const int PINLength = 6;
const std::string checkingAccountIndicator = "ca";
const std::string savingsAccountIndicator = "sa";

// function prototypes
bool initialLogin(int& userID, int& PIN) throw (std::ios_base::failure, std::invalid_argument);
void askForPINBeforeTransaction(const int& PIN);
void populateUserMap(const int& userID, std::map<int, account*>& userAccounts)  throw (std::ios_base::failure, std::invalid_argument);
void outputUserMenu();
void checkBalance(std::map<int, account*>& userAccounts, const int& PIN);
void depositFunds(std::map<int, account*>& userAccounts, const int& PIN);
void withdrawFunds(std::map<int, account*>& userAccounts, const int& PIN);
void transferFunds(std::map<int, account*>& userAccounts, const int& PIN);
void createNewAccount(std::map<int, account*>& userAccounts, const int& PIN, const int& userID) throw (std::ios_base::failure, std::invalid_argument);

int main()
{
	// initalize variables
	bool initialLoginSuccessful = false;
	int userID = 0;
	int PIN = 0; // if this were an actual ATM machine, you wouldn't be storing the PIN on the machine at all, but we will here due to this not actually being an ATM machine and for convenience 
	int i = 0;
	std::map<int, account*> userAccounts;
	int userChoice;

	// You get three tries to log into your account
	while (initialLoginSuccessful == false && i < 3) {
		initialLoginSuccessful = initialLogin(userID, PIN);
	}
	
	// if you fail all three times, the ATM program will shut down
	if (i >= 3) {
		std::cerr << "You have gone over the allowed number of times you can login. The program will close now." << std::endl;
		return 1; // 1 is the error code for going over too many times
	}

	// todo: create user class here, make function to populate user map
	populateUserMap(userID, userAccounts);

	// output options for user to choose from
	while (true)
	{
		outputUserMenu();
		std::cin >> userChoice;

		switch (userChoice) {
		case 1:
		{
			// check balance here
			checkBalance(userAccounts, PIN);
			break;
		}
		case 2:
		{
			// deposit funds here
			depositFunds(userAccounts, PIN);
			break;
		}
		case 3:
		{
			// withdraw funds here
			withdrawFunds(userAccounts, PIN);
			break;
		}
		case 4:
		{
			// transfer funds here
			transferFunds(userAccounts, PIN);
			break;
		}
		case 5:
		{
			// create new account here
			createNewAccount(userAccounts, PIN, userID);
			break;
		}
		case 6:
		{
			// quit program here
			std::cout << "Quiting program." << std::endl;
			return 0;
		}
		default:
		{
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid value inputted. Please enter a number from 1 to 6 as a number." << std::endl;
			continue;
		}
		}
	}
	

	

	
	return 0;
}
// function definitions
bool initialLogin(int& userID, int& PIN) throw (std::ios_base::failure, std::invalid_argument) {
	// initialize variables
	std::vector<int> userIDsFromUsersFile;
	std::vector<int> PINsFromUsersFile;
	int userIDsToPopulateVector;
	int PINsToPopulateVector;
	int j = 0; 
	std::ifstream readFile;
	
	// get user IDs and PINs from file
	try {
		// open users.txt
		readFile.open("users.txt", std::ios_base::in);

		if (readFile.is_open())
		{
			// get user IDs and PINs from that file and use them to populate two parallel vectors
			while (!(readFile.eof())) {
				readFile >> userIDsToPopulateVector;
				readFile >> PINsToPopulateVector;
				userIDsFromUsersFile.push_back(userIDsToPopulateVector);
				PINsFromUsersFile.push_back(PINsToPopulateVector);
				j++;
			}

			// close file after we are done populating the vectors
			readFile.close();
		}
		else {
			throw std::ios_base::failure("users.txt did not open correctly.");
		}
		

		 
	}
	catch (std::ios_base::failure& e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	// prompt user to enter in user ID
	std::cout << "Enter user ID: ";
	std::cin >> userID;

	// input verification loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "User ID must be a positive number. Please reenter your user ID.";
			std::cin >> userID;
			continue;
		}
		else if (userID < 0) {
			std::cerr << "User ID cannot be less than 0. Please reenter your user ID.";
			std::cin >> userID;
			continue;
		}
		else {
			break;
		}
	}

	// prompt user to enter in PIN
	std::cout << "Enter PIN: ";
	std::cin >> PIN;

	// input verification loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "PIN must be a positive number. Please reenter your PIN.";
			std::cin >> PIN;
			continue;
		}
		else if (PIN < 0) {
			std::cerr << "PIN cannot be less than 0. Please reenter your PIN.";
			std::cin >> PIN;
			continue;
		}
		else if (std::to_string(PIN).length() != PINLength) {
			std::cerr << "PIN must be " << PINLength << " digits long. Please reenter your PIN.";
			std::cin >> PIN;
			continue;
		}
		else {
			break;
		}
	}

	// check parallel vectors for linked user ID and PIN
	for (int i = 0; i < (j + 1); i++) {
		if (userIDsFromUsersFile[i] == userID && PINsFromUsersFile[i] == PIN) {
			std::cout << "Welcome User " << userID << " to our ATM Program!" << std::endl;
			return true;
		}
	}

	// when the user fails login
	std::cerr << "Login unsuccessful. Please try again." << std::endl;
	return false;

}
void askForPINBeforeTransaction(const int& PIN) {
	int userEntryForPIN;
	// prompt user to enter in PIN
	std::cout << "Enter PIN: ";
	std::cin >> userEntryForPIN;

	// input verification loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "PIN must be a positive number. Please reenter your PIN.";
			std::cin >> userEntryForPIN;
			continue;
		}
		else if (PIN < 0) {
			std::cerr << "PIN cannot be less than 0. Please reenter your PIN.";
			std::cin >> userEntryForPIN;
			continue;
		}
		else if (std::to_string(userEntryForPIN).length() != PINLength) {
			std::cerr << "PIN must be " << PINLength << " digits long. Please reenter your PIN.";
			std::cin >> userEntryForPIN;
			continue;
		}
		else if (userEntryForPIN != PIN) {
			std::cerr << "Entry doesn't match PIN, please renter it again.";
			std::cin >> userEntryForPIN;
			continue;
		}
		else {
			break;
		}
	}
}
void populateUserMap(const int& userID, std::map<int, account*>& userAccounts)  throw (std::ios_base::failure, std::invalid_argument) {
	// initalize variables
	std::ifstream readFile;
	std::vector<std::string> checkingAndSavingsAccounts;
	std::string checkingOrSavingsAccount;
	std::vector<int> accountIDs;
	std::vector<double> balances;
	int accountID;
	double balance;
	int j = 0;

	// get account IDs and balances from file
	try {
		// open the text file with the corresponding user ID
		readFile.open(std::to_string(userID) + ".txt", std::ios_base::in);

		if (readFile.is_open())
		{
			// get account identifiers from that file and use them to populate three parallel vectors
			while (!(readFile.eof())) {
				readFile >> checkingOrSavingsAccount;
				readFile >> accountID;
				readFile >> balance;
				checkingAndSavingsAccounts.push_back(checkingOrSavingsAccount);
				accountIDs.push_back(accountID);
				balances.push_back(balance);
				j++;
			}

			// close file after we are done populating the vectors
			readFile.close();
		}
		else {
			throw std::ios_base::failure(std::to_string(userID) + ".txt did not open correctly.");
		}
		
		// populate map with account information
		for (int i = 0; i < j; i++) {
			if (checkingAndSavingsAccounts[i] == savingsAccountIndicator) {
				account* userSavingsAccount = new savingsAccount(accountIDs[i], balances[i]);
				userAccounts.insert({ accountID, userSavingsAccount });
				continue;
			}
			else if (checkingAndSavingsAccounts[i] == checkingAccountIndicator) {
				account* userCheckingAccount = new savingsAccount(accountIDs[i], balances[i]);
				userAccounts.insert({ accountID, userCheckingAccount });
				continue;
			}
			else {
				throw std::invalid_argument("Invalid account indicator. The account isn't a savings or a checking account.");
			}
		}
		
	}
	catch (std::ios_base::failure& e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
}
void outputUserMenu() {
	std::cout << "User Options: " << std::endl;
	std::cout << '\t' << "1. Check Balance" << std::endl;
	std::cout << '\t' << "2. Deposit funds" << std::endl;
	std::cout << '\t' << "3. Withdraw funds" << std::endl;
	std::cout << '\t' << "4. Transfer funds" << std::endl;
	std::cout << '\t' << "5. Create new account" << std::endl;
	std::cout << '\t' << "6. Quit Program" << std::endl;
}
void checkBalance(std::map<int, account*>& userAccounts, const int& PIN) {
	// initialize variables
	int accountID;
	std::map<int, account*>::iterator it;
	bool accountIDFound = false;

	// ask for PIN before transaction;
	askForPINBeforeTransaction(PIN);
	
	// prompt user to enter in their account ID
	std::cout << "Enter in your account ID: ";
	std::cin >> accountID;

	// do some basic input verification in an infinite loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter your account ID as a number." << std::endl;
			std::cin >> accountID;
			accountIDFound = false;
			continue;
		}
		else if (accountID < 0) {
			std::cerr << "Account ID cannot be less than 0. Please enter in your account ID." << std::endl;
			std::cin >> accountID;
			accountIDFound = false;
			continue;
		}
		else {
			// make sure that account ID is set to false when it comes in
			accountIDFound = false;

			// when a value that isn't obviously invalid comes in, check the map to see if it matches one of the accountIDs in it, then if it does use the toString method to show the account balance.
			for (it = userAccounts.begin(); it != userAccounts.end(); it++) {
				if (accountID == it->first) {
					std::cout << "Correct Account ID entered." << std::endl;
					it->second->toString();
					accountIDFound = true;
					break;
				}
			}

			// if the account ID isn't found, we prompt the user to reenter their account ID in, if it is found, we break out of the loop
			if (accountIDFound == false)
			{
				std::cerr << "You did not input a correct account ID. Please try again." << std::endl;
				std::cin >> accountID;
				// just to make sure accountIDFound stays false
				accountIDFound = false;
				continue;
			}
			else {
				break;
			}
			
		}
	}
}
void depositFunds(std::map<int, account*>& userAccounts, const int& PIN) {
	// initialize variables
	int accountID;
	std::map<int, account*>::iterator it;
	bool accountIDFound = false;
	double depositIntoAccount;

	// ask for PIN before transaction;
	askForPINBeforeTransaction(PIN);

	// prompt user to enter in their account ID
	std::cout << "Enter in your account ID for the account you want to deposit into: ";
	std::cin >> accountID;

	// do some basic input verification in an infinite loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter your account ID as a number." << std::endl;
			std::cin >> accountID;
			accountIDFound = false;
			continue;
		}
		else if (accountID < 0) {
			std::cerr << "Account ID cannot be less than 0. Please enter in your account ID." << std::endl;
			std::cin >> accountID;
			accountIDFound = false;
			continue;
		}
		else {
			// make sure that account ID is set to false when it comes in
			accountIDFound = false;

			// when a value that isn't obviously invalid comes in, check the map to see if it matches one of the accountIDs in it, then if it does use the toString method to show the account balance.
			for (it = userAccounts.begin(); it != userAccounts.end(); it++) {
				if (accountID == it->first) {
					std::cout << "Correct Account ID entered." << std::endl;
					accountIDFound = true;
					break;
				}
			}

			// if the account ID isn't found, we prompt the user to reenter their account ID in, if it is found, we break out of the loop
			if (accountIDFound == false)
			{
				std::cerr << "You did not input a correct account ID. Please try again." << std::endl;
				std::cin >> accountID;
				// just to make sure accountIDFound stays false
				accountIDFound = false;
				continue;
			}
			else {
				break;
			}
		}
	}

	// Prompt user to see how much they want to deposit
	std::cout << "How many dollars do you want to deposit into your account?" << std::endl;
	std::cin >> depositIntoAccount;

	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter the deposit as a number." << std::endl;
			std::cin >> depositIntoAccount;
			continue;
		}
		else if (depositIntoAccount < 0) {
			std::cerr << "Deposit cannot be less than 0. Please enter in your deposit." << std::endl;
			std::cin >> depositIntoAccount;
			continue;
		}
		else {
			// find the accountID in the map, then add the deposit to the balance in the account.
			for (it = userAccounts.begin(); it != userAccounts.end(); it++) {
				if (accountID == it->first) {
					it->second->setBalance((it->second->getBalance() + depositIntoAccount));
					break;
				}
			}
			break;
		}
	}

}

void withdrawFunds(std::map<int, account*>& userAccounts, const int& PIN) {
	// initialize variables
	int accountID;
	std::map<int, account*>::iterator it;
	bool accountIDFound = false;
	double withdrawFromAccount;

	// ask for PIN before transaction;
	askForPINBeforeTransaction(PIN);

	// prompt user to enter in their account ID
	std::cout << "Enter in your account ID for the account you want to withdraw from: ";
	std::cin >> accountID;

	// do some basic input verification in an infinite loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter your account ID as a number." << std::endl;
			std::cin >> accountID;
			accountIDFound = false;
			continue;
		}
		else if (accountID < 0) {
			std::cerr << "Account ID cannot be less than 0. Please enter in your account ID." << std::endl;
			std::cin >> accountID;
			accountIDFound = false;
			continue;
		}
		else {
			// make sure that account ID is set to false when it comes in
			accountIDFound = false;

			// when a value that isn't obviously invalid comes in, check the map to see if it matches one of the accountIDs in it, then if it does use the toString method to show the account balance.
			for (it = userAccounts.begin(); it != userAccounts.end(); it++) {
				if (accountID == it->first) {
					std::cout << "Correct Account ID entered." << std::endl;
					accountIDFound = true;
					break;
				}
			}

			// if the account ID isn't found, we prompt the user to reenter their account ID in, if it is found, we break out of the loop
			if (accountIDFound == false)
			{
				std::cerr << "You did not input a correct account ID. Please try again." << std::endl;
				std::cin >> accountID;
				// just to make sure accountIDFound stays false
				accountIDFound = false;
				continue;
			}
			else {
				break;
			}
		}
	}

	// Prompt user to see how much they want to withdraw
	std::cout << "How many dollars do you want to withdraw from your account?" << std::endl;
	std::cin >> withdrawFromAccount;

	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter the withdrawal as a number." << std::endl;
			std::cin >> withdrawFromAccount;
			continue;
		}
		else if (withdrawFromAccount < 0) {
			std::cerr << "Withdrawal cannot be less than 0. Please enter in your withdrawal." << std::endl;
			std::cin >> withdrawFromAccount;
			continue;
		}
		else {
			// find the accountID in the map, then subtract the withdrawal from the balance in the account.
			for (it = userAccounts.begin(); it != userAccounts.end(); it++) {
				if (accountID == it->first) {
					it->second->setBalance((it->second->getBalance() - withdrawFromAccount));
					break;
				}
			}
			break;
		}
	}
}
void transferFunds(std::map<int, account*>& userAccounts, const int& PIN) {
	// initialize variables
	int accountIDTransferFrom;
	int accountIDTransferTo;
	std::map<int, account*>::iterator it;
	bool accountIDFound = false;
	double transferFromAccount;

	// ask for PIN before transaction;
	askForPINBeforeTransaction(PIN);

	// prompt user to enter in their account ID
	std::cout << "Enter in your account ID for the account you want to transfer from: ";
	std::cin >> accountIDTransferFrom;

	// do some basic input verification in an infinite loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter your account ID as a number." << std::endl;
			std::cin >> accountIDTransferFrom;
			accountIDFound = false;
			continue;
		}
		else if (accountIDTransferFrom < 0) {
			std::cerr << "Account ID cannot be less than 0. Please enter in your account ID." << std::endl;
			std::cin >> accountIDTransferFrom;
			accountIDFound = false;
			continue;
		}
		else {
			// make sure that account ID is set to false when it comes in
			accountIDFound = false;

			// when a value that isn't obviously invalid comes in, check the map to see if it matches one of the accountIDs in it, then if it does use the toString method to show the account balance.
			for (it = userAccounts.begin(); it != userAccounts.end(); it++) {
				if (accountIDTransferFrom == it->first) {
					std::cout << "Correct Account ID entered." << std::endl;
					accountIDFound = true;
					break;
				}
			}

			// if the account ID isn't found, we prompt the user to reenter their account ID in, if it is found, we break out of the loop
			if (accountIDFound == false)
			{
				std::cerr << "You did not input a correct account ID. Please try again." << std::endl;
				std::cin >> accountIDTransferFrom;
				// just to make sure accountIDFound stays false
				accountIDFound = false;
				continue;
			}
			else {
				break;
			}
		}
	}

	// prompt user to enter in their account ID
	std::cout << "Enter in your account ID for the account you want to transfer to: ";
	std::cin >> accountIDTransferTo;

	// do some basic input verification in an infinite loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter your account ID as a number." << std::endl;
			std::cin >> accountIDTransferTo;
			accountIDFound = false;
			continue;
		}
		else if (accountIDTransferFrom < 0) {
			std::cerr << "Account ID cannot be less than 0. Please enter in your account ID." << std::endl;
			std::cin >> accountIDTransferTo;
			accountIDFound = false;
			continue;
		}
		else {
			// make sure that account ID is set to false when it comes in
			accountIDFound = false;

			// when a value that isn't obviously invalid comes in, check the map to see if it matches one of the accountIDs in it, then if it does use the toString method to show the account balance.
			for (it = userAccounts.begin(); it != userAccounts.end(); it++) {
				if (accountIDTransferTo == it->first) {
					std::cout << "Correct Account ID entered." << std::endl;
					accountIDFound = true;
					break;
				}
			}

			// if the account ID isn't found, we prompt the user to reenter their account ID in, if it is found, we break out of the loop
			if (accountIDFound == false)
			{
				std::cerr << "You did not input a correct account ID. Please try again." << std::endl;
				std::cin >> accountIDTransferTo;
				// just to make sure accountIDFound stays false
				accountIDFound = false;
				continue;
			}
			else {
				break;
			}
		}
	}

	// Prompt user to see how much they want to withdraw
	std::cout << "How many dollars do you want to transfer from your account to another account?" << std::endl;
	std::cin >> transferFromAccount;

	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter the transfer as a number." << std::endl;
			std::cin >> transferFromAccount;
			continue;
		}
		else if (transferFromAccount < 0) {
			std::cerr << "Transfer cannot be less than 0. Please enter in your transfer." << std::endl;
			std::cin >> transferFromAccount;
			continue;
		}
		else {
			// find the accountID belonging to the transferred from account in the map, then subtract the transfer from the balance in the account.
			for (it = userAccounts.begin(); it != userAccounts.end(); it++) {
				if (accountIDTransferFrom == it->first) {
					it->second->setBalance((it->second->getBalance() - transferFromAccount));
					break;
				}
			}

			// find the accountID belonging to the transferred to account in the map, then add the withdrawal to the balance in the account.
			for (it = userAccounts.begin(); it != userAccounts.end(); it++) {
				if (accountIDTransferTo == it->first) {
					it->second->setBalance((it->second->getBalance() + transferFromAccount));
					break;
				}
			}
			break;
		}
	}
}
void createNewAccount(std::map<int, account*>& userAccounts, const int& PIN, const int& userID) throw (std::ios_base::failure, std::invalid_argument) {
	// initialize variables
	std::ofstream writeFile;
	int savingsOrCheckingAccount;
	int accountID;
	double balance;

	// ask for PIN before transaction;
	askForPINBeforeTransaction(PIN);

	// prompt user to ask if they want to create a savings account or a checking account
	std::cout << "Do you want to create a savings account or a checking account?" << std::endl;
	std::cout << '\t' << "1. Savings Account" << std::endl;
	std::cout << '\t' << "2. Checking Account" << std::endl;
	std::cin >> savingsOrCheckingAccount;

	// input verification infinite loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input. User choice must be either a 1 or a 2." << std::endl;
			std::cin >> savingsOrCheckingAccount;
			continue;
		}
		else if (savingsOrCheckingAccount < 1 || savingsOrCheckingAccount > 2) {
			std::cerr << "Invalid input. User choice must be either a 1 or a 2." << std::endl;
			std::cin >> savingsOrCheckingAccount;
			continue;
		}
		else {
			break;
		}
	}

	// prompt user to enter in the account ID for the new account
	std::cout << "Enter in your account ID for the account you want to create: ";
	std::cin >> accountID;

	// do some basic input verification in an infinite loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter your account ID as a number." << std::endl;
			std::cin >> accountID;
			continue;
		}
		else if (accountID < 0) {
			std::cerr << "Account ID cannot be less than 0. Please enter in your account ID." << std::endl;
			std::cin >> accountID;
			continue;
		}
		else {
			break;
		}
	}

	// prompt user to enter in the balance for the new account
	std::cout << "Enter in the balance for the account you want to create: ";
	std::cin >> balance;

	// do some basic input verification in an infinite loop
	while (true) {
		if (!(std::cin)) {
			std::cin.clear();
			std::cin.ignore(200, '\n');
			std::cerr << "Invalid input, please enter your balance as a number." << std::endl;
			std::cin >> balance;
			continue;
		}
		else if (balance < 0) {
			std::cerr << "Balance cannot be less than 0. Please enter in your balance." << std::endl;
			std::cin >> balance;
			continue;
		}
		else {
			break;
		}
	}

	// switch structure to handle user choice and to create the account type they chose 
	switch (savingsOrCheckingAccount) {
	case 1:
	{
		// create user savings account
		account* userSavingsAccount = new savingsAccount(accountID, balance);
		userAccounts.insert({accountID, userSavingsAccount});

		try {
			// open the file
			writeFile.open(std::to_string(userID) + ".txt", std::ios::app);

			// if file is open write information to file and then close file, else throw an exception
			if (writeFile.is_open()) {
				writeFile << savingsAccountIndicator << " " << accountID << " " << balance << std::endl;
				writeFile.close();

			}
			else {
				throw std::ios_base::failure(std::to_string(userID) + ".txt did not open correctly.");
			}
		}
		catch (std::ios_base::failure& e) {
			std::cerr << e.what() << std::endl;
		}
		catch (std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
		break;
	}
	case 2:
	{
		account* userCheckingAccount = new checkingAccount(accountID, balance);
		userAccounts.insert({ accountID, userCheckingAccount });

		try {
			// open the file
			writeFile.open(std::to_string(userID) + ".txt", std::ios::app);

			// if file is open write information to file and then close file, else throw an exception
			if (writeFile.is_open()) {
				writeFile << checkingAccountIndicator << " " << accountID << " " << balance << std::endl;
				writeFile.close();
			}
			else {
				throw std::ios_base::failure(std::to_string(userID) + ".txt did not open correctly.");
			}
		}
		catch (std::ios_base::failure& e) {
			std::cerr << e.what() << std::endl;
		}
		catch (std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
		break;
	}
	default:
	{
		std::cin.clear();
		std::cin.ignore(200, '\n');
		std::cerr << "Invalid input. User choice must be either a 1 or a 2." << std::endl;
		break;
	}
	}
}
