/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/15/2024
*  Purpose: Create an inheritance hierarchy of RPG classes.
*/

#include <iostream>
#include <string>
#include <climits> // for input validation
#include <sstream> // for tostring() function
#include <cstdlib> // for rand() function
#include <iomanip>
#include "character.h"

int main() {
	// list variables
	std::string fighterName;
	std::string rogueName;
	std::string magicianName;
	std::string clericName;

	// ask user for input
	std::cout << "What is your fighter's name:";
	std::getline(std::cin, fighterName);
	std::cout << std::endl;
	std::cout << "What is your rogue's name:";
	std::getline(std::cin, rogueName);
	std::cout << std::endl;
	std::cout << "What is your magician's name:";
	std::getline(std::cin, magicianName);
	std::cout << std::endl;
	std::cout << "What is your cleric's name:";
	std::getline(std::cin, clericName);
	std::cout << std::endl;

	// to be more accurate to the example
	std::cout << "Testing" << std::endl;

	// create characters
	fighter newFighter = fighter(fighterName);
	rogue newRogue = rogue(rogueName);
	magician newMagician = magician(magicianName);
	cleric newCleric = cleric(clericName);

	// list out starting stats of characters
	std::cout << "Fighter Starting Stats" << std::endl;
	std::cout << newFighter.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Rogue Starting Stats" << std::endl;
	std::cout << newRogue.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Magician Starting Stats" << std::endl;
	std::cout << newMagician.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Cleric Starting Stats" << std::endl;
	std::cout << newCleric.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	// the fighter strong attacks the rogue for stealing their stuff
	std::cout << newFighter.getName() << " Strong Attack " << newRogue.getName() << std::endl;

	double rogueHP = (newRogue.getHp() - newFighter.strongAttack());

	newRogue.setHp(rogueHP);

	std::cout << "Updated Rogue Stats" << std::endl;

	std::cout << newRogue.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	// the rogue steals hp from the fighter
	std::cout << newRogue.getName() << " Steal " << newFighter.getName() << std::endl;
	
	double fighterHP = (newFighter.getHp() - newRogue.steal());

	newFighter.setHp(fighterHP);

	std::cout << "Updated Rogue Stats" << std::endl;

	std::cout << newRogue.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Updated Fighter Stats" << std::endl;

	std::cout << newFighter.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	// the magician casts upon the rogue
	std::cout << newMagician.getName() << " Cast " << newRogue.getName() << std::endl;

	rogueHP = (newRogue.getHp() - newMagician.cast());

	newRogue.setHp(rogueHP);

	std::cout << "Updated Magician Stats" << std::endl;

	std::cout << newMagician.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Updated Rogue Stats" << std::endl;

	std::cout << newRogue.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	// the healer heals the fighter

	std::cout << newCleric.getName() << " Heal " << newFighter.getName() << std::endl;

	fighterHP = (newFighter.getHp() + newCleric.heal());

	newFighter.setHp(fighterHP);

	std::cout << "Updated Cleric Stats" << std::endl;

	std::cout << newCleric.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Updated Fighter Stats" << std::endl;

	std::cout << newFighter.tostring();
	std::cout << std::endl;
	std::cout << std::endl;

	return 0; 
}

