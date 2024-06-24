/* Program name: candy.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/21/2024
*  Purpose: Create class implentation of methods for candy class here
*/

#include "candy.h"
#include <iostream>
#include <string>
#include <map>

// enum to string mapping goes here
std::map < flavorType, std::string> flavorString{
	{COTTON_CANDY, "Cotton Candy"},
	{WATERMELON_BURST, "Watermelon Burst"},
	{PAPAYA_BLISS, "Papaya Bliss"},
	{CITRUS_SPLASH, "Citrus Splash"},
	{COLA, "Cola"}
};

std::map < colorType, std::string> colorString{
	{SCARLET_BLAZE, "Scarlet Blaze"},
	{AZURE_SKY, "Azure Sky"},
	{EMERALD_MIST, "Emerald Mist"},
	{GOLDENROD_GLOW, "Goldenrod Glow"},
	{AMETHYST_HAZE, "Amethyst Haze"}
};

// class implementation goes here
candy::candy(flavorType flavor, colorType color) {
	// check both flavor and candy to see if they match enum, if they don't, throw an invalid_argument
	if (flavor < COTTON_CANDY || flavor > COLA) {
		throw std::invalid_argument("Invalid entry. Number must be between 1 and 5 inclusive. Try again.");
	}
	else {
		this->flavor = flavor;
	}
	if (color < SCARLET_BLAZE || color > AMETHYST_HAZE)
	{
		throw std::invalid_argument("Invalid entry. Number must be between 1 and 5 inclusive. Try again.");
	}
	else
	{
		this->color = color;
	}
}
int candy::getColor() {
	// matching color to it's corresponding menu number
	switch (color)
	{
	case SCARLET_BLAZE:
	{
		return 1;
	}
	case AZURE_SKY:
	{
		return 2;
	}
	case EMERALD_MIST:
	{
		return 3;
	}
	case GOLDENROD_GLOW:
	{
		return 4;
	}
	case AMETHYST_HAZE:
	{
		return 5;
	}
	default:
	{
		return -1;
	}

	}
}
int candy::getFlavor() {
	// matching flavor to it's corresponding menu number
	switch (flavor)
	{
	case COTTON_CANDY:
	{
		return 1;
	}
	case WATERMELON_BURST:
	{
		return 2;
	}
	case PAPAYA_BLISS:
	{
		return 3;
	}
	case CITRUS_SPLASH:
	{
		return 4;
	}
	case COLA:
	{
		return 5;
	}
	default:
	{
		return -1;
	}
	}
}
void candy::setColor(colorType color) {
	if (color < SCARLET_BLAZE || color > AMETHYST_HAZE)
	{
		throw std::invalid_argument("Invalid entry. Number must be between 1 and 5 inclusive. Try again.");
	}
	else
	{
		this->color = color;
	}
}
void candy::setFlavor(flavorType flavor) {
	if (flavor < COTTON_CANDY || flavor > COLA) {
		throw std::invalid_argument("Invalid entry. Number must be between 1 and 5 inclusive. Try again.");
	}
	else {
		this->flavor = flavor;
	}
}
std::string candy::colorTypeEnumToString(colorType enumColor) {
	return colorString[enumColor];
}

std::string candy::flavorTypeEnumToString(flavorType enumFlavor) {
	return flavorString[enumFlavor];
}
colorType candy::intToColorType(int enumNum) {
	switch (enumNum)
	{
	case 1:
	{
		return SCARLET_BLAZE;
	}
	case 2:
	{
		return AZURE_SKY;
	}
	case 3:
	{
		return EMERALD_MIST;
	}
	case 4:
	{
		return GOLDENROD_GLOW;
	}
	case 5:
	{
		return AMETHYST_HAZE;
	}
	default:
	{
		throw std::invalid_argument("The input was not a number between 1 to 5");
	}
	}
}
flavorType candy::intToFlavorType(int enumNum) {
	switch (enumNum)
	{
	case 1:
	{
		return COTTON_CANDY;
	}
	case 2:
	{
		return WATERMELON_BURST;
	}
	case 3:
	{
		return PAPAYA_BLISS;
	}
	case 4:
	{
		return CITRUS_SPLASH;
	}
	case 5:
	{
		return COLA;
	}
	default:
	{
		throw std::invalid_argument("The input was not a number between 1 to 5");
	}
	}
}

