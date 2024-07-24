/* Program name: burger.cpp
* Author: Kyle Ingersoll
* Date last updated: 6/11/2024
* Purpose: Create the class method definitions for burger
*/
#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include <sstream> // for the stringstream for the toString() method so it can output a formatted string
#include "burger.h"

// don't forget to include the class header file

// constructor
burger::burger(proteinType protein, condimentType condemints[], int numCondiments, toppingType toppings[], int numToppings, bunType bun, cheeseType cheese, int numPatties){
	this->protein = protein;
	this->condiments[0] = condemints[0]; // since you can't assign the whole array equal to each other, we go across value by value across all the indexes
	this->condiments[1] = condemints[1];
	this->condiments[2] = condemints[2];
	this->condiments[3] = condemints[3];
	this->condiments[4] = condemints[4];
	this->condiments[5] = condemints[5];
	this->condiments[6] = condemints[6];
	this->numCondiments = numCondiments;
	this->toppings[0] = toppings[0];
	this->toppings[1] = toppings[1];
	this->toppings[2] = toppings[2];
	this->toppings[3] = toppings[3];
	this->toppings[4] = toppings[4];
	this->toppings[5] = toppings[5];
	this->toppings[6] = toppings[6];
	this->numToppings = numToppings;
	this->bun = bun;
	this->cheese = cheese;
	this->numPatties = numPatties;
	this->isVeg = isVeggie();
	
}

// getters
proteinType burger::getProtein() const {
	return protein;
}
std::string burger::getCondiments() const {

	std::string condimentsString;
	int i = 0;

	for (i; i < numCondiments; i++)
	{
		switch (condiments[i])
		{
		case KETCHUP: 
		{
			if ((i < (numCondiments - 1)))  // if the index is before the last condiment, a comma and the condiment name is added to the condiments string, else just the condiment name is added.
			{
				condimentsString += "Ketchup, ";
				continue;
			}
			else
			{
				condimentsString += "Ketchup";
				continue;
			}

		}
		case MUSTARD:
		{
			if ((i < (numCondiments - 1)))
			{
				condimentsString += "Mustard, ";
				continue;
			}
			else
			{
				condimentsString += "Mustard";
				continue;
			}

		}
		case MAYO:
		{
			if ((i < (numCondiments - 1)))
			{
				condimentsString += "Mayonnaise, ";
				continue;
			}
			else
			{
				condimentsString += "Mayonnaise";
				continue;
			}
		}
		case SPECIAL:
		{
			if ((i < (numCondiments - 1)))
			{
				condimentsString += "Special Sauce, ";
				continue;
			}
			else
			{
				condimentsString += "Special Sauce";
				continue;
			}
		}
		case BBQ:
		{
			if ((i < (numCondiments - 1)))
			{
				condimentsString += "BBQ Sauce, ";
				continue;
			}
			else
			{
				condimentsString += "BBQ Sauce";
				continue;
			}
		}
		case STEAK:
		{
			if ((i < (numCondiments - 1)))
			{
				condimentsString += "Steak Sauce, ";
				continue;
			}
			else
			{
				condimentsString += "Steak Sauce";
				continue;
			}

		}
		case PEPPERCORN:
		{
			if ((i < (numCondiments - 1)))
			{
				condimentsString += "Peppercorn Ranch, ";
				continue;
			}
			else
			{
				condimentsString += "Peppercorn Ranch";
				continue;
			}
		}
		case NOCOND:
		{
			condimentsString = "None";
			break;
		}
		default:
		{
			break;
		}
		}

		
	}

	return condimentsString;
}

std::string burger::getToppings() const {
	std::string toppingsString;
	int i = 0;
	for (i; i < numToppings; i++)
	{
		switch (toppings[i])
		{
		case GRILLONION:
		{
			if ((i < (numToppings - 1)))
			{
				toppingsString += "Grilled Onion, ";
				continue;
			}
			else
			{
				toppingsString += "Grilled Onion";
				continue;
			}
		}
		case RAWONION:
		{
			if ((i < (numToppings - 1)))
			{
				toppingsString += "Raw Onion, ";
				continue;
			}
			else
			{
				toppingsString += "Raw Onion";
				continue;
			}
		}
		case TOMATO:
		{
			if ((i < (numToppings - 1)))
			{
				toppingsString += "Tomato, ";
				continue;
			}
			else
			{
				toppingsString += "Tomato";
				continue;
			}
		}
		case LETTUCE:
		{
			if ((i < (numToppings - 1)))
			{
				toppingsString += "Lettuce, ";
				continue;
			}
			else
			{
				toppingsString += "Lettuce";
				continue;
			}
		}
		case BACON:
		{
			if ((i < (numToppings - 1)))
			{
				toppingsString += "Bacon, ";
				continue;
			}
			else
			{
				toppingsString += "Bacon";
				continue;
			}
		}
		case MUSHROOM:
		{
			if ((i < (numToppings - 1)))
			{
				toppingsString += "Grilled Mushroom, ";
				continue;
			}
			else
			{
				toppingsString += "Grilled Mushroom";
				continue;
			}
		}
		case PICKLE:
		{
			if ((i < (numToppings - 1)))
			{
				toppingsString += "Pickle, ";
				continue;
			}
			else
			{
				toppingsString += "Pickle";
				continue;
			}
		}
		case NOTOP:
		{
			toppingsString = "None";
			break;
		}
		default:
		{
			break;
		}
		}
	}

	return toppingsString;
}
bunType burger::getBun() const {
	return bun;
}
cheeseType burger::getCheese() const {
	return cheese;
}
bool burger::isVeggie() const { // how am I supposed to keep it const when this needs to change isVeg to either true or false and isVeg is a private function?
	// if protein is mush or veggie, and none of the toppings are bacon, then isVeg is true, else it is false
	if ((protein == MUSH || protein == VEGGIE) && (toppings[0] != BACON && toppings[1] != BACON && toppings[2] != BACON && toppings[3] != BACON && toppings[4] != BACON) && toppings[5] != BACON && toppings[6] != BACON)
	{
		isVeg = true;
	}
	else
	{
		isVeg = false;
	}
	return isVeg;
}
int burger::getNumPatties() const {
	return numPatties;
}
double burger::getPrice() const {
	double price = 0.0;

	// switch to find the price of the protein times the number of patties
	switch (protein)
	{
	case BEEF:
	{
		price += (3.5 * numPatties);
		break;
	}
	case TURKEY:
	{
		price += (4 * numPatties);
		break;
	}
	case CHICKEN:
	{
		price += (4 * numPatties);
		break;
	}
	case MUSH:
	{
		price += (4.5 * numPatties);
		break;
	}
	case VEGGIE:
	{
		price += (4.5 * numPatties);
		break;
	}
	default:
	{
		break;
	}
	}

	price += (0.50 * numToppings); // add to price $0.50 times number of toppings
	price += (0.25 * numCondiments); // add to price $0.25 times number of condiments
	
	if (cheese != NOCHEESE) // if there is cheese in the burger, add $0.10 to price
	{
		price += 0.10;
	}

	return price;

}

// setters

void burger::setProtein(proteinType protein) {
	if (protein == BEEF || protein == TURKEY || protein == CHICKEN || protein == MUSH || protein == VEGGIE)
	{
		this->protein = protein;
	}
	
}
void burger::setCondiments(condimentType condiments[], int numCondiments) {
	int i = 0;

	for (i; i < numCondiments; i++)
	{
		if (condiments[i] == KETCHUP || condiments[i] == MUSTARD || condiments[i] == MAYO || condiments[i] == SPECIAL || condiments[i] == BBQ || condiments[i] == STEAK || condiments[i] == PEPPERCORN || condiments[i] == NOCOND)
		{
			this->condiments[i] = condiments[i];
		}
	}

	this->numCondiments = numCondiments;
}
void burger::setToppings(toppingType toppings[], int numToppings)
{
	int i = 0;
	for (i; i < numToppings; i++)
	{
		if (toppings[i] == GRILLONION || toppings[i] == RAWONION || toppings[i] == TOMATO || toppings[i] == LETTUCE || toppings[i] == BACON || toppings[i] == MUSHROOM || toppings[i] == PICKLE || toppings[i] == NOTOP)
		{
			this->toppings[i] = toppings[i];
		}
	}

	this->numToppings = numToppings;
}
void burger::setBun(bunType bun)
{
	if (bun == BRIOCHE || bun == WHEAT || bun == SESAME || bun == ONION || bun == RYE || bun == NOBUN || bun == GLUTENFREE)
	{
		this->bun = bun;
	}
}
void burger::setCheese(cheeseType cheese)
{
	if (cheese == CHEDDAR || cheese == AMERICAN || cheese == PEPPERJACK || cheese == SWISS || cheese == COLBYJACK || cheese == NOCHEESE)
	{
		this->cheese = cheese;
	}
}
void burger::setNumPatties(int numPatties) {
	if (numPatties > 0)
	{
		this->numPatties = numPatties;
	}
}

// other functions

std::string burger::tostring() {

	// define variables
	std::stringstream outputStream; // needed to output the formatted text as a single string so it can be returned
	bool vegetarianBurger;

	outputStream << "Protein: ";

	switch (protein)
	{
	case BEEF:
	{
		outputStream << "Beef" << std::endl;
		break;
	}
	case TURKEY:
	{
		outputStream << "Turkey" << std::endl;
		break;
	}
	case CHICKEN:
	{
		outputStream << "Chicken Breast" << std::endl;
		break;
	}
	case MUSH:
	{
		outputStream << "Portabella Mushroom" << std::endl;
		break;
	}
	case VEGGIE:
	{
		outputStream << "Veggie" << std::endl;
		break;
	}
	default:
	{
		break;
	}
	}

	outputStream << "Number of patties: " << numPatties << std::endl;

	outputStream << "Bun Type: ";

	switch (bun)
	{
	case BRIOCHE:
	{
		outputStream << "Brioche" << std::endl;
		break;
	}
	case WHEAT:
	{
		outputStream << "Wheat" << std::endl;
		break;
	}
	case SESAME:
	{
		outputStream << "Sesame" << std::endl;
		break;
	}
	case ONION:
	{
		outputStream << "Onion" << std::endl;
		break;
	}
	case RYE:
	{
		outputStream << "Rye Bread" << std::endl;
		break;
	}
	case NOBUN:
	{
		outputStream << "None" << std::endl;
		break;
	}
	case GLUTENFREE:
	{
		outputStream << "Gluten Free" << std::endl;
		break;
	}
	default:
	{
		break;
	}
	}

	outputStream << "Cheese: ";

	switch (cheese)
	{
	case CHEDDAR:
	{
		outputStream << "Cheddar" << std::endl;
		break;
	}
	case AMERICAN:
	{
		outputStream << "American" << std::endl;
		break;
	}
	case PEPPERJACK:
	{
		outputStream << "Pepper Jack" << std::endl;
		break;
	}
	case SWISS:
	{
		outputStream << "Swiss" << std::endl;
		break;
	}
	case COLBYJACK:
	{
		outputStream << "Colby Jack" << std::endl;
		break;
	}
	case NOCHEESE:
	{
		outputStream << "None" << std::endl;
		break;
	}
	default:
	{
		break;
	}
	}

	outputStream << "Condiments: " << getCondiments() << std::endl;
	
	outputStream << "Toppings: " << getToppings() << std::endl;

	vegetarianBurger = isVeggie();

	if (vegetarianBurger == true)
	{
		outputStream << "This is a vegetarian burger." << std::endl;
	}
	
	return outputStream.str(); // We return the stringstream as an string object
}
