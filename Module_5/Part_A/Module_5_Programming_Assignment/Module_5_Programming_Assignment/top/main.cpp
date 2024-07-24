/* Program name: main.cpp
* Author: Kyle Ingersoll
* Date last updated: 7/7/2024
* Purpose: Allow the user to customize multiple of Jack and Jill's burgers.
*/

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include <sstream> // for the stringstream for the toString() method so it can output a formatted string
#include <vector>
#include <limits>
#include "burger.h" // don't forget your class header

// function prototypes
void pattiesOnBurger(int& pattiesNum);
void proteinMenuChoice(std::string& proteinMenuString, char& vegetarianCharChoice, bool& checkBurgerForVegetarianWhenChanging);
int toppingMenuChoice(std::string (& toppingMenuStrings)[7], toppingType (& toppingMenuEnums)[7], int numOfToppings, char& vegetarianCharChoice, bool& checkBurgerForVegetarianWhenChanging, const int changeBurgerMenuNum); // note to self: use dataType (& arrayName) instead of dataType & arrayName to avoid making an array of references
int condimentMenuChoice(std::string (& condimentMenuStrings)[7], int numOfCondiments, condimentType (& condimentMenuEnums)[7], const int changeBurgerMenuNum); // note to self: add in the size of the array to the index value of the parameter arrays 
void bunMenuChoice(std::string& bunMenuString);
void cheeseMenuChoice(std::string& cheeseMenuString);

int main() {
	// list variables
	int pattiesNum = 0;
	std::string proteinMenuString = "";
	std::string toppingMenuStrings[7] = { "", "", "", "", "", "", "",};
	toppingType toppingMenuEnums[7] = { GRILLONION, GRILLONION, GRILLONION, GRILLONION, GRILLONION, GRILLONION, GRILLONION };
	int numOfToppings = 0;
	std::string condimentMenuStrings[7] = { "", "", "", "", "", "", "", };
	condimentType condimentMenuEnums[7] = { KETCHUP, KETCHUP, KETCHUP, KETCHUP, KETCHUP, KETCHUP, KETCHUP };
	int numOfCondiments = 0;
	std::string bunMenuString = "";
	std::string cheeseMenuString = "";
	int changeBurgerMenuNum = 0;
	char vegetarianCharChoice = 'a';
	bool checkBurgerForVegetarianWhenChanging = false;
	std::vector<burger> burgersOrdered;
	char doYouWantToEnterInAnotherBurger; 
	
	
	do {

		// set number of toppings and condiments to zero for each loop to reset their value every time someone orders a new burger
		numOfToppings = 0;
		numOfCondiments = 0;

		// get initial burger part choice to populate the burger class
		pattiesOnBurger(pattiesNum);
		proteinMenuChoice(proteinMenuString, vegetarianCharChoice, checkBurgerForVegetarianWhenChanging);
		numOfToppings = toppingMenuChoice(toppingMenuStrings, toppingMenuEnums, numOfToppings, vegetarianCharChoice, checkBurgerForVegetarianWhenChanging, changeBurgerMenuNum);
		numOfCondiments = condimentMenuChoice(condimentMenuStrings, numOfCondiments, condimentMenuEnums, changeBurgerMenuNum);
		bunMenuChoice(bunMenuString);
		cheeseMenuChoice(cheeseMenuString);

		// begin burger object through constructor
		burger newGormetBurger = burger(caseInsensitiveStringToProteinTypeMap[proteinMenuString], condimentMenuEnums, numOfCondiments, toppingMenuEnums, numOfToppings, caseInsensitiveStringToBunTypeMap[bunMenuString], caseInsensitiveStringToCheeseTypeMap[cheeseMenuString], pattiesNum);


		// display user choices to user
		std::cout << newGormetBurger.tostring() << std::endl;

		// after burger is set up, future changes are checked for being vegetarian
		checkBurgerForVegetarianWhenChanging = true;

		// ask user if they want to change the burger
		do
		{

			std::cout << "Would you like to change the burger? Please choose from the menu." << std::endl;
			std::cout << "1. Change Protein" << std::endl;
			std::cout << "2. Change Number of Patties" << std::endl;
			std::cout << "3. Change Toppings" << std::endl;
			std::cout << "4. Change Cheese" << std::endl;
			std::cout << "5. Change Bun" << std::endl;
			std::cout << "6. Change Condiments" << std::endl;
			std::cout << "7. No Changes" << std::endl;
			std::cin >> changeBurgerMenuNum;
			std::cout << std::endl;

			if (!(std::cin))
			{
				std::cin.clear();
				std::cin.ignore(200, '\n');
				changeBurgerMenuNum = 0;
				std::cout << "You have entered an invalid choice. Please try again." << std::endl;
				continue;
			}
			else if (changeBurgerMenuNum < 1 || changeBurgerMenuNum > 7)
			{
				std::cout << "You have entered an invalid choice. Please try again." << std::endl;
				continue;
			}


			// take user to the corresponding functions
			switch (changeBurgerMenuNum)
			{
			case 1:
			{
				proteinMenuChoice(proteinMenuString, vegetarianCharChoice, checkBurgerForVegetarianWhenChanging);
				if (vegetarianCharChoice == 'y')
				{
					newGormetBurger.setProtein(caseInsensitiveStringToProteinTypeMap[proteinMenuString]);
				}
				continue;
			}
			case 2:
			{
				pattiesOnBurger(pattiesNum);
				newGormetBurger.setNumPatties(pattiesNum);
				continue;
			}
			case 3:
			{
				numOfToppings = 0;
				numOfToppings = toppingMenuChoice(toppingMenuStrings, toppingMenuEnums, numOfToppings, vegetarianCharChoice, checkBurgerForVegetarianWhenChanging, changeBurgerMenuNum);
				if (vegetarianCharChoice == 'y' || vegetarianCharChoice == 'a')
				{
					newGormetBurger.setToppings(toppingMenuEnums, numOfToppings);
				}
				continue;
			}
			case 4:
			{
				cheeseMenuChoice(cheeseMenuString);
				newGormetBurger.setCheese(caseInsensitiveStringToCheeseTypeMap[cheeseMenuString]);
				continue;
			}
			case 5:
			{
				bunMenuChoice(bunMenuString);
				newGormetBurger.setBun(caseInsensitiveStringToBunTypeMap[bunMenuString]);
				continue;
			}
			case 6:
			{
				numOfCondiments = 0;
				numOfCondiments = condimentMenuChoice(condimentMenuStrings, numOfCondiments, condimentMenuEnums, changeBurgerMenuNum);
				newGormetBurger.setCondiments(condimentMenuEnums, numOfCondiments);
				continue;
			}
			case 7:
			{

				// display user choices to user 
				std::cout << newGormetBurger.tostring();
				do {
					// ask user if they want to enter in another burger
					std::cout << "Do you want to enter another burger?" << std::endl;
					std::cin >> doYouWantToEnterInAnotherBurger;
					std::cout << std::endl;

				

					if (doYouWantToEnterInAnotherBurger == 'n')
					{
						return 0; // end program normally
					}
					else if (doYouWantToEnterInAnotherBurger == 'y')
					{
						burgersOrdered.push_back(newGormetBurger);
						break;
					}
					else {
						std::cout << "Please enter y or n." << std::endl;
						continue;
					}

				} while (true);


				break;
			}
			default:
			{
				break;
			}
			}
			// to break out of the infinite loop
			break;

		} while (true);
	} while (true);




	return 0;
}

void pattiesOnBurger(int& pattiesNum) {
	// input validation check of pattiesNum
	do
	{
		std::cout << "How many patties do you want on your burger?";
		std::cin >> pattiesNum;
		std::cout << std::endl;

		if (!(std::cin))
		{
			std::cin.clear();
			std::cin.ignore(200, '\n');
			pattiesNum = 0;
			std::cout << "You entered an invalid amount of patties. Please try again." << std::endl;
			continue;
		}
		else if (pattiesNum < 1)
		{
			std::cout << "You entered an invalid amount of patties. Please try again." << std::endl;
			continue;
		}
		else
		{
			break;
		}

	} while (true);


}
void proteinMenuChoice(std::string& proteinMenuString, char& vegetarianCharChoice, bool& checkBurgerForVegetarianWhenChanging) {
	bool firstTimeThroughTheLoop = true;

	// input validation check of proteinMenuNum
	do
	{
		std::cout << "Please enter a protein." << std::endl;

		// to prevent getline() not reading the line if it is the first time
		if (firstTimeThroughTheLoop == true)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		getline(std::cin, proteinMenuString);

		if (caseInsensitiveStringToProteinTypeMap.count(proteinMenuString) == 0)
		{

			std::cout << "You have chosen an invalid protein type. Available protein types are:" << std::endl;
			std::cout << "Beef, Turkey, Chicken Breast, Portabella Mushroom, Veggie" << std::endl;
			firstTimeThroughTheLoop = false;
			continue;
		}
		else
		{
			break;
		}
	} while (true);

	

	// check proteinMenuEnum to see if burger is vegetarian, if not warn the user.
	if ((checkBurgerForVegetarianWhenChanging == true) && (caseInsensitiveStringToProteinTypeMap[proteinMenuString] != MUSH && caseInsensitiveStringToProteinTypeMap[proteinMenuString] != VEGGIE))
	{
		do
		{
			std::cout << "Warning you are changing the burger from vegetarian to meat based. Do you want to continue?";
			std::cin >> vegetarianCharChoice;
			std::cout << std::endl;

			if (!(std::cin))
			{
				std::cin.clear();
				std::cin.ignore(200, '\n');
				vegetarianCharChoice = 'a';
				std::cout << "Error: Please enter Y or N to confirm a change to a non-vegetarian burger.";
				std::cin >> vegetarianCharChoice;
				std::cout << std::endl;
				continue;
			}
			else if (vegetarianCharChoice != 'y' && vegetarianCharChoice != 'n')
			{
				std::cout << "Error: Please enter Y or N to confirm a change to a non-vegetarian burger.";
				std::cin >> vegetarianCharChoice;
				std::cout << std::endl;
				continue;
			}
			else
			{
				break;
			}
		} while (true);

		switch (vegetarianCharChoice)
		{
		case 'y':
		{
			break;
		}
		case 'n':
		{
			break;
		}
		default:
		{
			break;
		}
		}
	}
	else
	{
		return; // end program normally
	}
	
	
}
int toppingMenuChoice(std::string(&toppingMenuStrings)[7], toppingType(&toppingMenuEnums)[7], int numOfToppings, char& vegetarianCharChoice, bool& checkBurgerForVegetarianWhenChanging, const int changeBurgerMenuNum) { // note to self: use dataType (& arrayName) instead of dataType & arrayName to avoid making an array of references
	// declare iteration variables
	int i = 0;
	int j = 0;
	int m = 0;
	
	// prevent infinite loop of blank space entered and error messages occuring
	if (changeBurgerMenuNum == 3)
	{
		std::cin.clear();
		std::cin.ignore(200, '\n');
	}
	

	// input validation for toppingMenusNums[i] integer array
	for (i; i < 7; i++)
	{
		do
		{
			std::cout << "Please enter a topping. Enter -1 to move to the next step" << std::endl;
			getline(std::cin, toppingMenuStrings[i]);
			do {
				if (toppingMenuStrings[i] == "-1")
				{
					break;
				}
				else if ((caseInsensitiveStringToToppingTypeMap.count(toppingMenuStrings[i]) == 0))
				{
					std::cout << "You did not choose a valid topping. Enter one of the following toppings:" << std::endl;
					std::cout << "Grilled Onion, Raw Onion, Tomato, Lettuce, Bacon, Grilled Mushroom, Pickle, None" << std::endl;
					getline(std::cin, toppingMenuStrings[i]);
					continue;
				}
				else
				{
					numOfToppings++;
					break;
				}
			} while (true);

			if (toppingMenuStrings[i] == "-1" || numOfToppings > 0)
			{
				break;
			}
		} while (true);
		
		if (toppingMenuStrings[i] == "-1") // note to self, break statements break out of one layer of a nested loop, not all of them at the same time.
		{
			break;
		}
	}

	// translate toppingMenuStrings[j] to toppingMenuEnums[j] using a case insensitive map
	for (j; j < numOfToppings; j++)
	{
		toppingMenuEnums[j] = caseInsensitiveStringToToppingTypeMap[toppingMenuStrings[j]];
	}

	// check toppingMenuEnums to see if burger is vegetarian, if not warn the user.
	for (m; m < numOfToppings; m++)
	{
		if ((checkBurgerForVegetarianWhenChanging == true) && (toppingMenuEnums[m] == BACON))
		{
			do
			{
				std::cout << "Warning you are changing the burger from vegetarian to meat based. Do you want to continue?";
				std::cin >> vegetarianCharChoice;
				std::cout << std::endl;

				if (!(std::cin))
				{
					std::cin.clear();
					std::cin.ignore(200, '\n');
					vegetarianCharChoice = 'a';
					std::cout << "Error: Please enter Y or N to confirm a change to a non-vegetarian burger." << std::endl;
					continue;
				}
				else if (vegetarianCharChoice != 'y' && vegetarianCharChoice != 'n')
				{
					std::cout << "Error: Please enter Y or N to confirm a change to a non-vegetarian burger." << std::endl;
					continue;
				}
				else
				{
					break;
				}
			} while (true);

			switch (vegetarianCharChoice)
			{
			case 'y':
			{
				break;
			}
			case 'n':
			{
				break;
			}
			default:
			{
				break;
			}
			}
		}
		else
		{
			break;
		}
	}

	return numOfToppings;

}
int condimentMenuChoice(std::string(& condimentMenuStrings)[7], int numOfCondiments, condimentType(& condimentMenuEnums)[7], const int changeBurgerMenuNum) {
	// declare iteration variables
	int k = 0;
	int l = 0;

	// prevent infinite loop of blank space entered and error messages occuring
	if (changeBurgerMenuNum == 6)
	{
		std::cin.clear();
		std::cin.ignore(200, '\n');
	}

	// input validation for condimentMenuStrings[k]
	for (k; k < 7; k++)
	{
		do
		{
			std::cout << "Please enter a Condiment. Enter -1 to move to the next step" << std::endl;
			getline(std::cin, condimentMenuStrings[k]);

			do {
				if (condimentMenuStrings[k] == "-1")
				{
					break;
				}
				else if ((caseInsensitiveStringToCondimentTypeMap.count(condimentMenuStrings[k]) == 0))
				{
					std::cout << "You did not choose a valid condiment. Enter one of the following condiments:" << std::endl;
					std::cout << "Ketchup, Mustard, Mayonnaise, Special Sauce, BBQ Sauce, Steak Sauce, Peppercorn Ranch, None" << std::endl;
					getline(std::cin, condimentMenuStrings[k]);
					continue;
				}
				else
				{
					numOfCondiments++;
					break;
				}
			} while (true);

			if (condimentMenuStrings[k] == "-1" || numOfCondiments > 0)
			{
				break;
			}
		} while (true);
		
		if (condimentMenuStrings[k] == "-1") 
		{
			break;
		}
	}

	// translate condimentMenuStrings[l] to condimentMenuEnums[l] using a case insenstive map
	for (l; l < numOfCondiments; l++)
	{
		condimentMenuEnums[l] = caseInsensitiveStringToCondimentTypeMap[condimentMenuStrings[l]];
	}

	return numOfCondiments;
}
void bunMenuChoice(std::string& bunMenuString) {

	// input validation check of bunMenuNum
	do 
	{
		std::cout << "Please enter a bun." << std::endl;
		getline(std::cin, bunMenuString);

		if ((caseInsensitiveStringToBunTypeMap.count(bunMenuString) == 0))
		{
			std::cout << "You have chosen an invalid bun type. Available bun types are: " << std::endl;
			std::cout << "Brioche, Wheat, Sesame, Onion, Rye Bread, None, Gluten Free" << std::endl;
			continue;
		}
		else
		{
			break;
		}
	} while (true);

}

void cheeseMenuChoice(std::string& cheeseMenuString) {

	// input validation check of cheeseMenuNum

	do 
	{
		std::cout << "Please enter a cheese." << std::endl;
		getline(std::cin, cheeseMenuString);

		if ((caseInsensitiveStringToCheeseTypeMap.count(cheeseMenuString) == 0))
		{
			std::cout << "You have chosen an invalid cheese type. Available cheese types are: " << std::endl;
			std::cout << "Cheddar, American, Pepper Jack, Swiss, Colby Jack, None" << std::endl;
			continue;
		}
		else
		{
			break;
		}
	} while (true);

}
