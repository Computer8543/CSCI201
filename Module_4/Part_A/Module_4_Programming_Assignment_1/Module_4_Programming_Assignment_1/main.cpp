/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/26/2024
*  Purpose: Make a virtual tostring() method for each class, make a dynamic array of characters using a double pointer, 
*           and then populate the array with character information. Then loop through the array to display all the characters information.
*			After that, delete the dynamic array and it's members and set them all to NULL to avoid memory leaks and dangling pointers.
*/

#include <iostream>
#include <string>
#include <climits> // for input validation
#include <limits> // for numeric_limits
#include <sstream> // for tostring() function
#include <cstdlib> // for rand() function
#include <iomanip>
#include "character.h"

int main() {
	// initialize variables
	int numOfCharactersYouWantToCreate = 0;
	int characterClassNumYouWant = 0;
	std::string characterName;
	character** characters = NULL;

	// ask user how many characters they want to create
	std::cout << "How many characters do you want to create?";
	std::cin >> numOfCharactersYouWantToCreate;
	std::cout << std::endl;

	// input verification for what the user entered for the number of characters they wanted to create
	do {
		if (!(std::cin))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			numOfCharactersYouWantToCreate = 0;
			std::cout << "What was entered was not an number. Please input a number between 1 and 100." << std::endl;
			std::cin >> numOfCharactersYouWantToCreate;
			std::cout << std::endl;
			continue;
		}
		else if (numOfCharactersYouWantToCreate < 1 || numOfCharactersYouWantToCreate > 100)
		{
			std::cout << "Please input a number between 1 and 100." << std::endl;
			std::cin >> numOfCharactersYouWantToCreate;
			std::cout << std::endl;
			continue;
		}
		else
		{
			break;
		}
	} while (true);

	// set up dynamic array of characters
	characters = new character * [numOfCharactersYouWantToCreate];

	// loop through and populate characters dynamic array
	for (int i = 0; i < numOfCharactersYouWantToCreate; i++)
	{
		// get character name from user
		std::cout << "What is the name for character #" << (i + 1) << "?";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(std::cin, characterName);
		std::cout << std::endl;

		std::cout << "What character class do you want " << characterName << " to be?" << std::endl;
		std::cout << "1. Fighter Class" << std::endl;
		std::cout << "2. Rogue Class" << std::endl;
		std::cout << "3. Magician Class" << std::endl;
		std::cout << "4. Cleric Class" << std::endl;
		std::cin >> characterClassNumYouWant;
		std::cout << std::endl;

		// input verification for what the user entered for characterClassNumYouWant
		do {
			if (!(std::cin))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				characterClassNumYouWant = 0;
				std::cout << "That is not a valid choice. Please choose the class by number from the list." << std::endl;
				std::cin >> characterClassNumYouWant;
				std::cout << std::endl;
				continue;
			}
			else if (characterClassNumYouWant < 1 || characterClassNumYouWant > 4)
			{
				std::cout << "That is not a valid choice. Please choose the class by number from the list." << std::endl;
				std::cin >> characterClassNumYouWant;
				std::cout << std::endl;
				continue;
			}
			else
			{
				break;
			}
		} while (true);
		
		// switch structure to convert characterClassNumYouWant into an actual character class and add that to the dynamic array
		switch (characterClassNumYouWant)
		{
		case 1:
		{
			characters[i] = new fighter(characterName);
			break;
		}
		case 2:
		{
			characters[i] = new rogue(characterName);
			break;
		}
		case 3:
		{
			characters[i] = new magician(characterName);
			break;
		}
		case 4:
		{
			characters[i] = new cleric(characterName);
			break;
		}
		default:
		{
			std::cout << "That is not a valid choice. Please choose the class by number from the list." << std::endl;
			break;
		}
		}
	}

	// show off created characters name, class, and stats to the user
	std::cout << "Your Party:" << std::endl;
	
	for (int j = 0; j < numOfCharactersYouWantToCreate; j++)
	{
		std::cout << characters[j]->tostring();
		std::cout << std::endl;
		std::cout << std::endl;
	}

	// delete elements of dynamic array to avoid memory leaks and set them to NULL to avoid dangling pointers
	for (int k = 0; k < numOfCharactersYouWantToCreate; k++)
	{
		delete characters[k];
		characters[k] = NULL;
	}

	// delete dynamic array itself to avoid memory leaks and set it to NULL to avoid dangling pointers
	delete[] characters;
	characters = NULL;

	return 0; 
}

