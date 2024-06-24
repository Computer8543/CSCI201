/* Program name: candy.h
*  Author: Kyle Ingersoll
*  Date last updated: 6/20/2024
*  Purpose: Create class definition for candy class and set up colorType and flavorType enums
*/

#ifndef CANDY_H
#define CANDY_H

#include <iomanip>
#include <string>
#include <map>

//enumerations go here
enum flavorType { COTTON_CANDY = 1, WATERMELON_BURST, PAPAYA_BLISS, CITRUS_SPLASH, COLA };
enum colorType { SCARLET_BLAZE = 1, AZURE_SKY, EMERALD_MIST, GOLDENROD_GLOW, AMETHYST_HAZE };


// class definition goes here
class candy {
private:
	colorType color;
	flavorType flavor;
public:
	candy(flavorType flavor, colorType color);
	int getColor();
	int getFlavor();
	void setColor(colorType color);
	void setFlavor(flavorType flavor);
	std::string colorTypeEnumToString(colorType enumColor);
	std::string flavorTypeEnumToString(flavorType enumFlavor);
};
#endif