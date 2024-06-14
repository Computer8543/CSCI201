
#include <iostream>
#include <string>
#include <stdexcept>
#include "Automobile.h"

int Automobile::carCount = 0; // must initialize static members

// constructor
Automobile::Automobile(Make make, std::string model, std::string color, std::string vin, int year, bool roofOpen, bool windowsTinted) {
	if (model == "")
	{
		throw std::invalid_argument("Must Specify Model!!!");
	}

	this->make = make;
	this->model = model;
	this->color = color;
	this->vin = vin;
	this->year = year;
	this->roofOpen = roofOpen;
	this->windowsTinted = windowsTinted;

	milage = 0.0;
	mpg = 30.0;
	fuelCapacity = 10.0;
	fuelLevel = 10.0;

	carCount += 1;

	std::cout << "Creating " << color << year << " " << make << " " << model << " ";

	if (roofOpen == true)
		std::cout << " with open roof ";
	else
		std::cout << " with closed roof ";
	 
	if (windowsTinted == true)
		std::cout << " and has tinted windows. " << std::endl;
	else
		std::cout << " and does not have tinted windows. " << std::endl;

}
// destructor 
Automobile::~Automobile() {
	std::cout << "Printing certificate of destruction for " << vin << std::endl;
	carCount -= 1;
}
// accessor methods
Make Automobile::getMake() const {
	return make;
}
std::string Automobile::getModel() const {
	return model;
}
std::string Automobile::getColor() const {
	return color;
}
std::string Automobile::getVin() const {
	return vin;
}
int Automobile::getYear() const {
	return year;
}
bool Automobile::getRoofOpen() const {
	return roofOpen;
}
bool Automobile::getWindowsTinted() const {
	return windowsTinted;
}
static int Automobile::getCarCount() const { // belongs to the class 
	return carCount;
}

// mutator methods
double Automobile::drive(double distance) {
	if (distance <= 0) {
		throw std::invalid_argument("can't drive a negative distance");
	}
	else if (distance > (fuelLevel * mpg)) {
		distance = fuelLevel * mpg;
	}
	milage += distance;
	fuelLevel -= distance / mpg;

	return distance; // return distance driven
}
void Automobile::paint(std::string color) {
	this->color = color; // note usage of "this->" to avoid ambiguity

}
double Automobile::refuel(double amount) {
	if (amount < 0) {
		throw std::invalid_argument("Can't syphon fuel!!!");
	}
	else if (amount > (fuelCapacity - fuelLevel)) {
		amount = (fuelCapacity - fuelLevel);
	}
	fuelLevel += amount;
	return amount;
}
void Automobile::openOrCloseRoof(bool roof) {
	roofOpen = roof;
}
void Automobile::replaceWindows(bool windows) {
	windowsTinted = windows;
}
std::string Automobile::toString(){
	std::string result = color + std::to_string(year) + " " + make + " " + model + " vin " + vin + " with " +
		std::to_string(fuelLevel) + " gallons and " + std::to_string(milage) + " miles ";

	if (roofOpen == true)
		result += " with open roof ";
	else
		result += " with closed roof ";

	if (windowsTinted == true)
		result += " and has tinted windows. ";
	else
		result += " and does not have tinted windows. ";


	return result;
}