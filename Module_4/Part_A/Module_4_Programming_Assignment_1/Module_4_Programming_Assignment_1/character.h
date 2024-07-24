/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/26/2024
*  Purpose: Store RPG class attributes and method prototypes
*/

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <climits> // for input validation
#include <sstream> // for tostring() function
#include <cstdlib> // for rand() function
#include <iomanip>

// classes go here
class character {
protected:
	double hp;
	double mp;
	int dexterity;
	int endurance;
	int faith;
	int intelligence;
	int speed;
	int strength;
	std::string name;
public:
	// parametized constructor 
	character(std::string name, double hp, double mp, int strength, int dexterity, int intelligence, int speed, int endurance, int faith);
	// mutator method
	double attack();

	// getter methods
	double getHp() const;
	double getMp() const;
	int getDexterity() const;
	int getEndurance() const;
	int getFaith() const;
	int getIntelligence() const;
	int getSpeed() const;
	int getStrength() const;
	std::string getName() const;
	

	// puts all the stats into a string
	virtual std::string tostring() = 0;

	// setter functions
	void setDexterity(int dexterity);

	void setEndurance(int endurance);

	void setFaith(int faith);

	void setHp(double hp);

	void setIntelligence(int intelligence);

	void setMp(double mp);

	void setSpeed(int speed);

	void setStrength(int strength);
};

class cleric : public character {
public:
	cleric(std::string name);

	double heal();

	virtual std::string tostring();
};

class fighter : public character {
public:
	fighter(std::string name);

	double strongAttack();

	virtual std::string tostring();
};

class magician : public character {
public:
	magician(std::string name);

	double cast();

	virtual std::string tostring();
};

class rogue : public character {
public:
	rogue(std::string name);

	double steal();

	virtual std::string tostring();
};
#endif