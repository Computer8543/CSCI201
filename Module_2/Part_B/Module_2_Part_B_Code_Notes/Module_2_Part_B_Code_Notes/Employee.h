#pragma once

#include <iostream>
#include <string>

class Employee {
public:
	std::string name;
protected:
	std::string employeeNumber;
	std::string ssn;
public:
	Employee(std::string name, std::string ssn, std::string employeeNumber) {
		this->name = name;
		this->ssn = ssn;
		this->employeeNumber = employeeNumber;
		std::cout << "Creating Employee " << name << std::endl;
	}
	~Employee() {
		std::cout << "Terminating Employee " << name << std::endl;
	}
	std::string getName() {
		return name;
	}
	std::string getSSN() {
		return ssn;
	}
	std::string getEmployeeNumber() {
		return employeeNumber;
	}
	void work() {
		std::cout << "Hi Ho!!! Hi Ho!!! It's off to work we go!!!" << std::endl;
	}
};

class Secretary : public Employee {
private:
	int wordsPerMinute;
public:
	Secretary(std::string name, std::string ssn, std::string employeeNumber, int wpm) : Employee(name, ssn, employeeNumber) {
		wordsPerMinute = wpm;
		std::cout << "promoting " << name << " to secretary" << std::endl;
	}
	~Secretary() {
		std::cout << "Demoting " << name << " to Employee!!!" << std::endl;

	}
	void type() {
		std::cout << "Type Type Type" << std::endl;
	}
	void work() {
		std::cout << "Type Type Gossip Gossip Gossip!!!" << std::endl;
	}
};

class LegalSecretary : public Secretary {
public:
	LegalSecretary(std::string name, std::string ssn, std::string employeeNumber, int wpm) : Secretary(name, ssn, employeeNumber, wpm) {
		std::cout << "promoting " << name << " to legal secretary" << std::endl;
	}
	~LegalSecretary() {
		std::cout << "Demoting " << name << " to Secretary!!!" << std::endl;

	}
	void fileBriefs() {
		std::cout << "Filing Filing Filing Briefs at the courthouse and online" << std::endl;
	}
	void takeDictation() {
		std::cout << "Taking Dictation!!!" << std::endl;
	}
	void work() { // polymorphism
		std::cout << "Take Dictation, Type and File Briefs and Motions!!!" << std::endl;
	}
	/*void attack(Employee& other) {
		// based on experience and type of other character - calculate the damage
		std::cout << "Attack with mean comments!!!" << std::endl;
		// other.inflictDamage(points)

	}
	*/
};

class Programmer : public Employee {
protected:
	std::string programingLanguages;
public:
	Programmer(std::string name, std::string ssn, std::string employeeNumber, std::string programmingLanguages) : Employee(name, ssn, employeeNumber) {
		this->programingLanguages = programmingLanguages;
		std::cout << "Promoting " << name << " to Programmer!!! " << std::endl;
	}
	~Programmer() {
		std::cout << "Demoting " << name << " to Employee!!!" << std::endl;
	}
	void develop() {
		std::cout << "Agile!!! Web!! Prototyping!!! WaterFall!! " << std::endl;
	}
	void hack() {
		std::cout << "Hack Hack Hack!!!" << std::endl;
	}
	void work() {
		std::cout << "Code Code Code Test Test Debug Debug Debug Test Debug ARghhh!!!!" << std::endl;
	}
};