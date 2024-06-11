/* Program name: main.cpp
* Author: Kyle Ingersoll
* Date last updated: 6/11/2024
* Purpose: Allow the user to customize one of Jack and Jill's burgers.
*/

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include <sstream> // for the stringstream for the toString() method so it can output a formatted string
#include "burger.h" // don't forget your class header

// function prototypes
void pattiesOnBurger(int pattiesNum, burger& newGormetBurger);
void proteinMenuChoice(int proteinMenuNum, proteinType& proteinMenuEnum, burger& newGormetBurger, char vegetarianCharChoice, bool& checkBurgerForVegetarianWhenChanging);
void toppingMenuChoice(int (& toppingMenuNums)[7], int& numOfToppings, toppingType (& toppingMenuEnums)[7], burger& newGormetBurger, char vegetarianCharChoice, bool& checkBurgerForVegetarianWhenChanging); // note to self: use dataType (& arrayName) instead of dataType & arrayName to avoid making an array of references
void condimentMenuChoice(int (& condimentMenuNums)[7], int& numOfCondiments, condimentType (& condimentMenuEnums)[7], burger& newGormetBurger); // note to self: add in the size of the array to the index value of the parameter arrays 
void bunMenuChoice(int bunMenuNum, bunType& bunMenuEnum, burger& newGormetBurger);
void cheeseMenuChoice(int cheeseMenuNum, cheeseType& cheeseMenuEnum, burger& newGormetBurger);

int main() {
	// list variables
	int pattiesNum = 0;
	int proteinMenuNum = 0;
	proteinType proteinMenuEnum = BEEF;
	int toppingMenuNums[7] = { 0, 0, 0, 0, 0, 0, 0 };
	toppingType toppingMenuEnums[7] = { GRILLONION, GRILLONION, GRILLONION, GRILLONION, GRILLONION, GRILLONION, GRILLONION};
	int numOfToppings = 0;
	int condimentMenuNums[7] = { 0, 0, 0, 0, 0, 0, 0 };
	condimentType condimentMenuEnums[7] = { KETCHUP, KETCHUP, KETCHUP, KETCHUP, KETCHUP, KETCHUP, KETCHUP};
	int numOfCondiments = 0;
	int bunMenuNum = 0;
	bunType bunMenuEnum = BRIOCHE;
	int cheeseMenuNum = 0;
	cheeseType cheeseMenuEnum = CHEDDAR;
	int changeBurgerMenuNum = 0;
	char vegetarianCharChoice = 'n';
	bool checkBurgerForVegetarianWhenChanging = false;

	// begin burger object through constructor
	burger newGormetBurger = burger(proteinMenuEnum, condimentMenuEnums, numOfCondiments, toppingMenuEnums, numOfToppings, bunMenuEnum, cheeseMenuEnum, pattiesNum);

	// call functions to create menu
	pattiesOnBurger(pattiesNum, newGormetBurger);
	proteinMenuChoice(proteinMenuNum, proteinMenuEnum, newGormetBurger,vegetarianCharChoice, checkBurgerForVegetarianWhenChanging);
	toppingMenuChoice(toppingMenuNums, numOfToppings, toppingMenuEnums, newGormetBurger, vegetarianCharChoice, checkBurgerForVegetarianWhenChanging);
	condimentMenuChoice(condimentMenuNums, numOfCondiments, condimentMenuEnums, newGormetBurger);
	bunMenuChoice(bunMenuNum, bunMenuEnum, newGormetBurger);
	cheeseMenuChoice(cheeseMenuNum, cheeseMenuEnum, newGormetBurger);
	newGormetBurger.tostring();

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
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else if (changeBurgerMenuNum < 1 || changeBurgerMenuNum > 7)
		{
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else
		{
			continue;
		}

		// take user to the corresponding functions
		switch (changeBurgerMenuNum)
		{
		case 1:
		{
			proteinMenuChoice(proteinMenuNum, proteinMenuEnum, newGormetBurger, vegetarianCharChoice, checkBurgerForVegetarianWhenChanging);
			continue;
		}
		case 2:
		{
			pattiesOnBurger(pattiesNum, newGormetBurger);
			continue;
		}
		case 3:
		{
			toppingMenuChoice(toppingMenuNums, numOfToppings, toppingMenuEnums, newGormetBurger, vegetarianCharChoice, checkBurgerForVegetarianWhenChanging);
			continue;
		}
		case 4:
		{
			cheeseMenuChoice(cheeseMenuNum, cheeseMenuEnum, newGormetBurger);
			continue;
		}
		case 5:
		{
			bunMenuChoice(bunMenuNum, bunMenuEnum, newGormetBurger);
			continue;
		}
		case 6:
		{
			condimentMenuChoice(condimentMenuNums, numOfCondiments, condimentMenuEnums, newGormetBurger);
			continue;
		}
		case 7:
		{
			newGormetBurger.tostring();
			break;
		}
		default:
		{
			break;
		}
		}
	} while (true);

	

	

	return 0;
}
void pattiesOnBurger(int pattiesNum, burger& newGormetBurger) {
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
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else if (pattiesNum < 1)
		{
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else
		{
			break;
		}

	} while ((!(std::cin)) || pattiesNum < 1);

	newGormetBurger.setNumPatties(pattiesNum);

}
void proteinMenuChoice(int proteinMenuNum, proteinType& proteinMenuEnum, burger& newGormetBurger, char vegetarianCharChoice, bool& checkBurgerForVegetarianWhenChanging) {
	// input validation check of proteinMenuNum
	do
	{
		std::cout << "Please choose a protein from the list." << std::endl;
		std::cout << "1: Beef" << std::endl;
		std::cout << "2: Turkey" << std::endl;
		std::cout << "3: Chicken Breast" << std::endl;
		std::cout << "4: Portabella Mushroom" << std::endl;
		std::cout << "5: Veggie" << std::endl;
		std::cin >> proteinMenuNum;
		std::cout << std::endl;

		if (!(std::cin))
		{
			std::cin.clear();
			std::cin.ignore(200, '\n');
			proteinMenuNum = 0;
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else if (proteinMenuNum < 1 || proteinMenuNum > 5)
		{
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else
		{
			break;
		}
	} while ((!(std::cin)) || proteinMenuNum < 1 || proteinMenuNum > 5);

	// translate proteinMenuNum to corresponding proteinMenuEnum
	switch (proteinMenuNum)
	{
	case 1:
	{
		proteinMenuEnum = BEEF;
		break;
	}
	case 2:
	{
		proteinMenuEnum = TURKEY;
		break;
	}
	case 3:
	{
		proteinMenuEnum = CHICKEN;
		break;
	}
	case 4:
	{
		proteinMenuEnum = MUSH;
		break;
	}
	case 5:
	{
		proteinMenuEnum = VEGGIE;
		break;
	}
	default:
	{
		break;
	}
	}

	// check proteinMenuEnum to see if burger is vegetarian, if not warn the user.
	if ((checkBurgerForVegetarianWhenChanging == true) && (proteinMenuEnum != MUSH && proteinMenuEnum != VEGGIE))
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
				std::cout << "Please choose either y or n." << std::endl;
				continue;
			}
			else if (vegetarianCharChoice != 'y' && vegetarianCharChoice != 'n')
			{
				std::cout << "Please choose either y or n." << std::endl;
				continue;
			}
			else
			{
				break;
			}
		} while ((!(std::cin)) || (vegetarianCharChoice != 'y' && vegetarianCharChoice != 'n'));

		switch (vegetarianCharChoice)
		{
		case 'y':
		{
			newGormetBurger.setProtein(proteinMenuEnum);
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
		newGormetBurger.setProtein(proteinMenuEnum);
	}
	
	
}
void toppingMenuChoice(int(&toppingMenuNums)[7], int& numOfToppings, toppingType(&toppingMenuEnums)[7], burger& newGormetBurger, char vegetarianCharChoice, bool& checkBurgerForVegetarianWhenChanging) {
	// declare iteration variables
	int i = 0;
	int j = 0;
	int m = 0;
	// input validation for toppingMenusNums[i] integer array
	for (i; i < 7; i++)
	{
		do
		{
			std::cout << "Please choose a topping from the list. Enter -1 to stop adding toppings." << std::endl;
			std::cout << "1: Grilled Onion" << std::endl;
			std::cout << "2: Raw Onion" << std::endl;
			std::cout << "3: Tomato" << std::endl;
			std::cout << "4: Lettuce" << std::endl;
			std::cout << "5: Bacon" << std::endl;
			std::cout << "6: Grilled Mushroom" << std::endl;
			std::cout << "7: Pickle" << std::endl;
			std::cout << "8: None" << std::endl;
			std::cin >> toppingMenuNums[i];
			std::cout << std::endl;

			if (!(std::cin))
			{
				std::cin.clear();
				std::cin.ignore(200, '\n');
				toppingMenuNums[i] = 0;
				std::cout << "Please choose a number from the list." << std::endl;
				continue;
			}
			else if (toppingMenuNums[i] == -1)
			{
				break;
			}
			else if ((toppingMenuNums[i] < -1) || ((-1 < toppingMenuNums[i]) && (toppingMenuNums[i] < 1)) || (toppingMenuNums[i] > 8))
			{
				std::cout << "Please choose a number from the list." << std::endl;
				continue;
			}
			else
			{
				numOfToppings++;
				continue;
			}
		} while ((!(std::cin)) || (toppingMenuNums[i] < -1) || ((-1 < toppingMenuNums[i]) && (toppingMenuNums[i] < 1)) || (toppingMenuNums[i] > 8));
		
		if (toppingMenuNums[i] == -1) // note to self, break statements break out of one layer of a nested loop, not all of them at the same time.
		{
			break;
		}
	}

	// translate toppingMenuNums[j] to toppingMenuEnums[j]
	for (j; j < numOfToppings; j++)
	{
		switch (toppingMenuNums[j])
		{
		case 1:
		{
			toppingMenuEnums[j] = GRILLONION;
			continue;
		}
		case 2:
		{
			toppingMenuEnums[j] = RAWONION;
			continue;
		}
		case 3:
		{
			toppingMenuEnums[j] = TOMATO;
			continue;
		}
		case 4:
		{
			toppingMenuEnums[j] = LETTUCE;
			continue;
		}
		case 5:
		{
			toppingMenuEnums[j] = BACON;
			continue;
		}
		case 6:
		{
			toppingMenuEnums[j] = MUSHROOM;
			continue;
		}
		case 7:
		{
			toppingMenuEnums[j] = PICKLE;
			continue;
		}
		case 8:
		{
			toppingMenuEnums[j] = NOTOP;
			continue;
		}
		default:
		{
			break;
		}
		}
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
					std::cout << "Please choose either y or n." << std::endl;
					continue;
				}
				else if (vegetarianCharChoice != 'y' && vegetarianCharChoice != 'n')
				{
					std::cout << "Please choose either y or n." << std::endl;
					continue;
				}
				else
				{
					break;
				}
			} while ((!(std::cin)) || (vegetarianCharChoice != 'y' && vegetarianCharChoice != 'n'));

			switch (vegetarianCharChoice)
			{
			case 'y':
			{
				newGormetBurger.setToppings(toppingMenuEnums, numOfToppings);
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
			newGormetBurger.setToppings(toppingMenuEnums, numOfToppings);
			break;
		}
	}
	

}
void condimentMenuChoice(int(& condimentMenuNums)[7], int& numOfCondiments, condimentType(& condimentMenuEnums)[7], burger& newGormetBurger) {
	// declare iteration variables
	int k = 0;
	int l = 0;

	// input validation for condimentMenuNums[k]
	for (k; k < 7; k++)
	{
		do
		{
			std::cout << "Please choose a condiment from the list. Enter -1 to stop adding condiments." << std::endl;
			std::cout << "1: Ketchup" << std::endl;
			std::cout << "2: Mustard" << std::endl;
			std::cout << "3: Mayonnaise" << std::endl;
			std::cout << "4: Special Sauce" << std::endl;
			std::cout << "5: BBQ Sauce" << std::endl;
			std::cout << "6: Steak Sauce" << std::endl;
			std::cout << "7: Peppercorn Ranch" << std::endl;
			std::cout << "8: None" << std::endl;
			std::cin >> condimentMenuNums[k];
			std::cout << std::endl;

			if (!(std::cin))
			{
				std::cin.clear();
				std::cin.ignore(200, '\n');
				condimentMenuNums[k] = 0;
				std::cout << "Please choose a number from the list." << std::endl;
				continue;
			}
			else if (condimentMenuNums[k] == -1)
			{
				break;
			}
			else if ((condimentMenuNums[k] < -1) || ((- 1 < condimentMenuNums[k]) && (condimentMenuNums[k] < 1)) || (condimentMenuNums[k] > 8))
			{
				std::cout << "Please choose a number from the list." << std::endl;
				continue;
			}
			else
			{
				numOfCondiments++;
				continue;
			}

		} while ((!(std::cin)) || (condimentMenuNums[k] < -1) || ((-1 < condimentMenuNums[k]) && (condimentMenuNums[k] < 1)) || (condimentMenuNums[k] > 8));
		
		if (condimentMenuNums[k] == -1)
		{
			break;
		}
	}

	// translate condimentMenuNums[l] to condimentMenuEnums[l]
	for (l; l < numOfCondiments; l++)
	{
		switch (condimentMenuNums[l])
		{
		case 1:
		{
			condimentMenuEnums[l] = KETCHUP;
			continue;
		}
		case 2:
		{
			condimentMenuEnums[l] = MUSTARD;
			continue;
		}
		case 3:
		{
			condimentMenuEnums[l] = MAYO;
			continue;
		}
		case 4:
		{
			condimentMenuEnums[l] = SPECIAL;
			continue;
		}
		case 5:
		{
			condimentMenuEnums[l] = BBQ;
			continue;
		}
		case 6:
		{
			condimentMenuEnums[l] = STEAK;
			continue;
		}
		case 7:
		{
			condimentMenuEnums[l] = PEPPERCORN;
			continue;
		}
		case 8:
		{
			condimentMenuEnums[l] = NOCOND;
			continue;
		}
		default:
		{
			break;
		}
		}
	}

	newGormetBurger.setCondiments(condimentMenuEnums, numOfCondiments);
}
void bunMenuChoice(int bunMenuNum, bunType& bunMenuEnum, burger& newGormetBurger) {
	// input validation check of bunMenuNum
	do 
	{
		std::cout << "Please choose a bun from the list." << std::endl;
		std::cout << "1: Brioche" << std::endl;
		std::cout << "2: Wheat" << std::endl;
		std::cout << "3: Seasme" << std::endl;
		std::cout << "4: Onion" << std::endl;
		std::cout << "5: Rye Bread" << std::endl;
		std::cout << "6: None" << std::endl;
		std::cout << "7: Gluten Free" << std::endl;
		std::cin >> bunMenuNum;
		std::cout << std::endl;

		if (!(std::cin))
		{
			std::cin.clear();
			std::cin.ignore(200, '\n');
			bunMenuNum = 0;
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else if (bunMenuNum < 1 || bunMenuNum > 7)
		{
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else
		{
			break;
		}
	} while ((!(std::cin)) || bunMenuNum < 1 || bunMenuNum > 7);

	// convert bunMenuNum to bunMenuEnum

	switch (bunMenuNum)
	{
	case 1:
	{
		bunMenuEnum = BRIOCHE;
		break;
	}
	case 2:
	{
		bunMenuEnum = WHEAT;
		break;
	}
	case 3:
	{
		bunMenuEnum = SESAME;
		break;
	}
	case 4:
	{
		bunMenuEnum = ONION;
		break;
	}
	case 5:
	{
		bunMenuEnum = RYE;
		break;
	}
	case 6:
	{
		bunMenuEnum = NOBUN;
		break;
	}
	case 7:
	{
		bunMenuEnum = GLUTENFREE;
		break;
	}
	default:
	{
		break;
	}
	}

	newGormetBurger.setBun(bunMenuEnum);
}

void cheeseMenuChoice(int cheeseMenuNum, cheeseType& cheeseMenuEnum, burger& newGormetBurger) {
	// input validation check of cheeseMenuNum

	do 
	{
		std::cout << "Please choose a cheese from the list." << std::endl;
		std::cout << "1: Cheddar" << std::endl;
		std::cout << "2: American" << std::endl;
		std::cout << "3: Pepper Jack" << std::endl;
		std::cout << "4: Swiss" << std::endl;
		std::cout << "5: Colby Jack" << std::endl;
		std::cout << "6: None" << std::endl;
		std::cin >> cheeseMenuNum;
		std::cout << std::endl;

		if (!(std::cin))
		{
			std::cin.clear();
			std::cin.ignore(200, '\n');
			cheeseMenuNum = 0;
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else if (cheeseMenuNum < 1 || cheeseMenuNum > 6)
		{
			std::cout << "Please choose a number from the list." << std::endl;
			continue;
		}
		else
		{
			break;
		}
	} while ((!(std::cin)) || cheeseMenuNum < 1 || cheeseMenuNum > 6);

	// convert cheeseMenuNum to cheeseMenuEnum
	switch (cheeseMenuNum)
	{
	case 1:
	{
		cheeseMenuEnum = CHEDDAR;
		break;
	}
	case 2:
	{
		cheeseMenuEnum = AMERICAN;
		break;
	}
	case 3:
	{
		cheeseMenuEnum = PEPPERJACK;
		break;
	}
	case 4:
	{
		cheeseMenuEnum = SWISS;
		break;
	}
	case 5:
	{
		cheeseMenuEnum = COLBYJACK;
		break;
	}
	case 6:
	{
		cheeseMenuEnum = NOCHEESE;
		break;
	}
	default:
	{
		break;
	}
	}

	newGormetBurger.setCheese(cheeseMenuEnum);
}
