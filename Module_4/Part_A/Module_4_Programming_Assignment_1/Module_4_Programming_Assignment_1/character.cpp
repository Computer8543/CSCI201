/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/26/2024
*  Purpose: Store RPG class method definitions
*/

#include <iostream>
#include <string>
#include <climits> // for input validation
#include <sstream> // for tostring() function
#include <cstdlib> // for rand() function
#include <iomanip>
#include "character.h"

// parametized constructor 
character::character(std::string name, double hp, double mp, int strength, int dexterity, int intelligence, int speed, int endurance, int faith) {
	// input validation for parameters 
	if (name.size() < std::string::npos)
	{
		this->name = name;
	}
	else
	{
		throw std::invalid_argument("Name too large, please make it smaller.");
	}

	if (hp > 0.0)
	{
		this->hp = hp;
	}
	else
	{
		throw std::invalid_argument("HP cannot be a negative number or zero.");
	}

	if (mp >= 0.0)
	{
		this->mp = mp;
	}
	else
	{
		throw std::invalid_argument("MP cannot be a negative number.");
	}

	if (strength > 0)
	{
		this->strength = strength;
	}
	else
	{
		throw std::invalid_argument("Strength cannot be a negative number or zero.");
	}

	if (dexterity > 0)
	{
		this->dexterity = dexterity;
	}
	else
	{
		throw std::invalid_argument("Dexterity cannot be a negative number or zero.");
	}

	if (intelligence > 0)
	{
		this->intelligence = intelligence;
	}
	else
	{
		throw std::invalid_argument("Intelligence cannot be a negative number or zero.");
	}

	if (speed > 0)
	{
		this->speed = speed;
	}
	else
	{
		throw std::invalid_argument("Speed cannot be a negative number or zero.");
	}

	if (endurance > 0)
	{
		this->endurance = endurance;
	}
	else
	{
		throw std::invalid_argument("Endurance cannot be a negative number or zero.");
	}

	if (faith > 0)
	{
		this->faith = faith;
	}
	else
	{
		throw std::invalid_argument("Faith cannot be a negative number or zero.");
	}


}
// mutator method
double character::attack() {
	// since basic attack is based on the characters strength, return strength
	return strength;
}

// getter methods
double character::getHp() const {
	return hp;
}
double character::getMp() const {
	return mp;
}
int character::getDexterity() const {
	return dexterity;
}
int character::getEndurance() const {
	return endurance;
}
int character::getFaith() const {
	return faith;
}
int character::getIntelligence() const {
	return intelligence;
}
int character::getSpeed() const {
	return speed;
}
int character::getStrength() const {
	return strength;
}
std::string character::getName() const {
	return name;
}




// setter functions
void character::setDexterity(int dexterity) {
	// input validation to make sure that dexterity is not set to zero or an negative number
	if (dexterity > 0)
	{
		this->dexterity = dexterity;
	}
	else
	{
		throw std::invalid_argument("Dexterity cannot be a negative number or zero.");
	}
}

void character::setEndurance(int endurance) {
	// input validation to make sure that endurance is not set to zero or an negative number
	if (endurance > 0)
	{
		this->endurance = endurance;
	}
	else
	{
		throw std::invalid_argument("Endurance cannot be a negative number or zero.");
	}
}

void character::setFaith(int faith) {
	// input validation to make sure that faith is not set to zero or an negative number
	if (faith > 0)
	{
		this->faith = faith;
	}
	else
	{
		throw std::invalid_argument("Faith cannot be a negative number or zero.");
	}
}

void character::setHp(double hp) {
	// input validation to make sure that hp is not set to zero or an negative number
	if (hp > 0.0)
	{
		this->hp = hp;
	}
	else
	{
		throw std::invalid_argument("HP cannot be a negative number or zero.");
	}
}

void character::setIntelligence(int intelligence) {
	// input validation to make sure that intelligence is not set to zero or an negative number
	if (intelligence > 0)
	{
		this->intelligence = intelligence;
	}
	else
	{
		throw std::invalid_argument("Intelligence cannot be a negative number or zero.");
	}
}

void character::setMp(double mp) {
	// input validation to make sure that mp is not set to an negative number
	if (mp >= 0.0)
	{
		this->mp = mp;
	}
	else
	{
		throw std::invalid_argument("MP cannot be a negative number.");
	}
}

void character::setSpeed(int speed) {
	// input validation to make sure that speed is not set to zero or an negative number
	if (speed > 0)
	{
		this->speed = speed;
	}
	else
	{
		throw std::invalid_argument("Speed cannot be a negative number or zero.");
	}
}

void character::setStrength(int strength) {
	// input validation to make sure that strength is not set to zero or an negative number
	if (strength > 0)
	{
		this->strength = strength;
	}
	else
	{
		throw std::invalid_argument("Strength cannot be a negative number or zero.");
	}
}

cleric::cleric(std::string name) : character(name, 200.00, 200.00, 5, 10, 8, 16, 5, 16) {
	// input validation for parameters 
	if (name.size() < std::string::npos)
	{
		this->name = name;
	}
	else
	{
		throw std::invalid_argument("Name too large, please make it smaller.");
	}
}

double cleric::heal() {
	double ifMPMinusFaith;
	double healNumberIfMPReachesZero = 0.0;
	// heal reduces mp by amount of faith, and heals by the amount of faith
	if ((ifMPMinusFaith = mp - faith) > 0)
	{
		mp -= faith;
		return faith;
	}
	else
	{
		healNumberIfMPReachesZero = mp;
		mp = 0.0;
		return healNumberIfMPReachesZero;
	}
}

std::string cleric::tostring() {
	
	// declare variable
	std::stringstream outputStream;

	// output stats to the user
	outputStream << name << " the Cleric stats:" << std::endl;
	outputStream << "HP: " << std::setprecision(2) << std::fixed << hp << std::endl;
	outputStream << "MP: " << std::setprecision(2) << std::fixed << mp << std::endl;
	outputStream << "Strength: " << std::setprecision(0) << std::fixed << strength << std::endl;
	outputStream << "Dexterity: " << dexterity << std::endl;
	outputStream << "Intelligence: " << intelligence << std::endl;
	outputStream << "Speed: " << speed << std::endl;
	outputStream << "Endurance: " << endurance << std::endl;
	outputStream << "Faith: " << faith << std::endl;

	return outputStream.str(); // return outputStream as a string

	
}

fighter::fighter(std::string name) : character(name, 300.00, 0.00, 16, 10, 5, 8, 15, 5) {
	// input validation for parameters 
	if (name.size() < std::string::npos)
	{
		this->name = name;
	}
	else
	{
		throw std::invalid_argument("Name too large, please make it smaller.");
	}
}

double fighter::strongAttack() {
	return (strength + endurance);
}

std::string fighter::tostring() {

	// declare variable
	std::stringstream outputStream;

	// output stats to the user
	outputStream << name << " the Fighter stats:" << std::endl;
	outputStream << "HP: " << std::setprecision(2) << std::fixed << hp << std::endl;
	outputStream << "MP: " << std::setprecision(2) << std::fixed << mp << std::endl;
	outputStream << "Strength: " << std::setprecision(0) << std::fixed << strength << std::endl;
	outputStream << "Dexterity: " << dexterity << std::endl;
	outputStream << "Intelligence: " << intelligence << std::endl;
	outputStream << "Speed: " << speed << std::endl;
	outputStream << "Endurance: " << endurance << std::endl;
	outputStream << "Faith: " << faith << std::endl;

	return outputStream.str(); // return outputStream as a string


}

magician::magician(std::string name) : character(name, 250.00, 200.00, 5, 10, 16, 16, 5, 8) {
	// input validation for parameters 
	if (name.size() < std::string::npos)
	{
		this->name = name;
	}
	else
	{
		throw std::invalid_argument("Name too large, please make it smaller.");
	}
}

double magician::cast() {
	double ifMPMinusIntelligencePlusSpeed = 0.0;
	double damageNumberIfMPReachesZero = 0.0;

	// cast reduces mp by intelligence + speed, and deals intelligence + speed damage
	if ((ifMPMinusIntelligencePlusSpeed = mp - (intelligence + speed)) > 0)
	{
		mp -= (intelligence + speed);
		return (intelligence + speed);
	}
	else
	{
		damageNumberIfMPReachesZero = mp;
		mp = 0.0;
		return damageNumberIfMPReachesZero;
	}
}

std::string magician::tostring() {

	// declare variable
	std::stringstream outputStream;

	// output stats to the user
	outputStream << name << " the Magician stats:" << std::endl;
	outputStream << "HP: " << std::setprecision(2) << std::fixed << hp << std::endl;
	outputStream << "MP: " << std::setprecision(2) << std::fixed << mp << std::endl;
	outputStream << "Strength: " << std::setprecision(0) << std::fixed << strength << std::endl;
	outputStream << "Dexterity: " << dexterity << std::endl;
	outputStream << "Intelligence: " << intelligence << std::endl;
	outputStream << "Speed: " << speed << std::endl;
	outputStream << "Endurance: " << endurance << std::endl;
	outputStream << "Faith: " << faith << std::endl;

	return outputStream.str(); // return outputStream as a string


}

rogue::rogue(std::string name) : character(name, 200.00, 0.00, 10, 16, 16, 15, 8, 5) {
	// input validation for parameters 
	if (name.size() < std::string::npos)
	{
		this->name = name;
	}
	else
	{
		throw std::invalid_argument("Name too large, please make it smaller.");
	}
}

double rogue::steal() {
	double steal = 0.0;
	double randomNumber = 0.0;
	double randomPercent = 0.0;
	double stealNumberIfHPReachesMax = 0.0;
	double ifStealPlusHP = 0.0;
	// we find a random number between 50 and 10
	randomNumber = std::rand() % 40 + 10;

	//we turn that random number into a percent
	randomPercent = randomNumber / 100.0;

	// then we add dexterity, speed, and intelligence together twice, and multiply the second one by the random percent before adding the two values to get steal.
	steal = ((dexterity + speed + intelligence) + (randomPercent * (dexterity + speed + intelligence)));

	// steal fills up hp to max
	if ((ifStealPlusHP = hp + steal) <= 200.00)
	{
		hp += steal;
		return steal;
	}
	else {
		stealNumberIfHPReachesMax = 200.00 - hp;
		hp = 200.00;
		return (stealNumberIfHPReachesMax);
	}


}

std::string rogue::tostring() {

	// declare variable
	std::stringstream outputStream;

	// output stats to the user
	outputStream << name << " the Rogue stats:" << std::endl;
	outputStream << "HP: " << std::setprecision(2) << std::fixed << hp << std::endl;
	outputStream << "MP: " << std::setprecision(2) << std::fixed << mp << std::endl;
	outputStream << "Strength: " << std::setprecision(0) << std::fixed << strength << std::endl;
	outputStream << "Dexterity: " << dexterity << std::endl;
	outputStream << "Intelligence: " << intelligence << std::endl;
	outputStream << "Speed: " << speed << std::endl;
	outputStream << "Endurance: " << endurance << std::endl;
	outputStream << "Faith: " << faith << std::endl;

	return outputStream.str(); // return outputStream as a string


}