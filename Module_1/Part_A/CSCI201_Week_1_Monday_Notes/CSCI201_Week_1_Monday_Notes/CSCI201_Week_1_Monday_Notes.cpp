// CSCI201_Week_1_Monday_Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "BankAccount.h"
#include "Customer.h"
#include "Circle.h"
using namespace std;

struct address {
    string street;
    string city;
    string state;
    string zipcode; // leading zeros
};

// structures don't include access specifiers (protection), and they don't support inheritance, polymorphism, limited on operator overloading

struct student {
    string name;
    address home;
    int numCredits;
    float gpa;
};

void printAccount(bankaccount &thisaccount) {
    cout << "\n\tAccount" << thisaccount.getAccountNumber() << "has a balance of " << thisaccount.getBalance() << endl;
    thisaccount.deposit(3000, 1234);
}

int main()
{

    Circle myCircle(5.2);
    Circle yourCircle;

    Circle myCircles[20];

    /*
   // string name;
   // cin >> name;

    student myStudent;
    myStudent.name = "Fred";
    myStudent.numCredits = 32;
    myStudent.gpa = 3.5;

    myStudent.home.state = "IN";
    */
    string acctNum;
    double amount;
    int pin;

    cout << "Enter account number: ";
    cin >> acctNum;
    cout << "Enter initial deposit: ";
    cin >> amount;
    cout << "Enter PIN: ";
    cin >> pin;
    // constructed or instantiated an instance of an bank account 
    bankaccount myAccount("ABC1234", 300.00, pin); // constructor allows us to intitialize an object

    // use accessor methods to retrieve information 
    // cout << myAccount.getAccountNumber() << " has a balance of " << myAccount.getBalance() << endl;
    // printAccount(myAccount);
    cout << myAccount.toString() << endl;

    // mutator methods to "change" the object 
    myAccount.deposit(amount, pin);

    printAccount(myAccount);

    cout << myAccount.getAccountNumber() << " has a balance of " << myAccount.getBalance() << endl;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    myAccount.withdraw(amount, pin);

    cout << myAccount.getAccountNumber() << " has a balance of " << myAccount.getBalance() << endl;

    {
        bankaccount yourAccount("234", 50.00, 1234);

        myAccount.deposit(50, 1234);
        yourAccount.deposit(50, 1234);
    }

    cout << "Have a nice day!!!" << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
