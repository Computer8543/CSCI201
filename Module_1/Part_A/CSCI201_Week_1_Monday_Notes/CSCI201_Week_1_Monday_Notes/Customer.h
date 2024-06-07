// #pragma once // came about in C++ 17
// prior to that needed to use include-guard

#ifndef CUSTOMER_H // have we already compiled this?
#define CUSTOMER_H

#include <iostream>
#include <string>



class Customer {
private:
	std::string name;
	std::string address;
public:
	Customer(std::string newname) {
		name = newname;
	}
	Customer(std::string newname, std::string newaddress) {
		name = newname;
		address = newaddress;
	}
	Customer() {
		std::cout << "Enter the name: ";
		std::cin >> name;
		std::cout << std::endl;
	}
	std::string getName{
		return name;
	}
};

#endif 