#pragma once

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

enum Make {Ford, Chevy, Dodge, Kia};

map<Make, std::string> makeString{ {Ford, "Ford"}, {Chevy, "Chevy"}, {Dodge, "Dodge"}, {Kia, "Kia"} };

std::string makes[] = { "Ford", "Chevy" };

class Automobile {
	friend void printCarSpecs(const Automobile& thisAutomobile);
private:
	Make make;
	std::string model;
	std::string color;
	std::string vin;
	int year;
	double milage;
	double mpg; // miles per level
	double fuelLevel; // amount in gallons
	double fuelCapacity; // amount in gallons
	bool roofOpen; // does the roof open or not
	bool windowsTinted; // are the windows tinted or not
	static int carCount; // belongs to the CLASS, not the object 
public:
	// constructor
	Automobile(Make make, std::string model, std::string color, std::string vin, int year, bool roofOpen, bool windowsTinted);
	
	// destructor 
	~Automobile();

	// accessor methods
	Make getMake() const;
	std::string getModel() const;
	std::string getColor() const;
	std::string getVin() const;
	double getMPG() const;
	int getYear() const;
	bool getRoofOpen() const;
	bool getWindowsTinted() const;
	static int getCarCount() const;

	// mutator methods
	double drive(double distance);
	void paint(std::string color);
	double refuel(double amount);
	void openOrCloseRoof(bool roof);
	void replaceWindows(bool windows);
	
	std::string toString();
};