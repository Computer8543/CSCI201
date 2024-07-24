/* Program name: burger.h
* Author: Kyle Ingersoll
* Date last updated: 7/7/2024
* Purpose: Create a class prototype for burger, as well as list the various enums 
*/
#ifndef BURGER_H
#define BURGER_H

#include <iostream>
#include <string>
#include <string.h>
#include <climits>
#include <iomanip>
#include <sstream> // for the stringstream for the toString() method so it can output a formatted string
#include <algorithm>
#include <map>

// don't forget to include the class header file
struct comparator {
	bool operator()(const std::string& lhs, const std::string& rhs) const {
        std::string str1(lhs.length(), ' ');
        std::string str2(rhs.length(), ' ');
        std::transform(lhs.begin(), lhs.end(), str1.begin(), tolower);
        std::transform(rhs.begin(), rhs.end(), str2.begin(), tolower);
        return str1 < str2;
	}
};

// enum declaration
enum bunType {
	BRIOCHE, WHEAT, SESAME, ONION, RYE, NOBUN, GLUTENFREE
};

enum cheeseType {
	CHEDDAR, AMERICAN, PEPPERJACK, SWISS, COLBYJACK, NOCHEESE
};

enum condimentType {
	KETCHUP, MUSTARD, MAYO, SPECIAL, BBQ, STEAK, PEPPERCORN, NOCOND
};
enum proteinType {
	BEEF, TURKEY, CHICKEN, MUSH, VEGGIE
};
enum toppingType {
	GRILLONION, RAWONION, TOMATO, LETTUCE, BACON, MUSHROOM, PICKLE, NOTOP
};

// static maps for enumerations listed here
static std::map<bunType, std::string> bunTypeToStringMap{
	{bunType::BRIOCHE, "Brioche"}, {WHEAT, "Wheat"}, {SESAME, "Sesame"}, {ONION, "Onion"},
	{RYE, "Rye Bread"}, {NOBUN, "None"}, {GLUTENFREE, "Gluten Free"}
};
static std::map<std::string, bunType, comparator> caseInsensitiveStringToBunTypeMap{
	{"Brioche", BRIOCHE}, {"Wheat", WHEAT}, {"Sesame", SESAME}, {"Onion", ONION},
	{"Rye Bread", RYE}, {"None", NOBUN}, {"Gluten Free", GLUTENFREE}
};
static std::map<cheeseType, std::string> cheeseTypeToStringMap{
	{CHEDDAR, "Cheddar"}, {AMERICAN, "American"}, {PEPPERJACK, "Pepper Jack"},
	{SWISS, "Swiss"}, {COLBYJACK, "Colby Jack"}, {NOCHEESE, "None"}
};
static std::map<std::string, cheeseType, comparator> caseInsensitiveStringToCheeseTypeMap{
	{"Cheddar", CHEDDAR}, {"American", AMERICAN}, {"Pepper Jack", PEPPERJACK},
	{"Swiss", SWISS}, {"Colby Jack", COLBYJACK}, {"None", NOCHEESE}
};
static std::map<condimentType, std::string> condimentTypeToStringMap{
	{KETCHUP, "Ketchup"}, {MUSTARD, "Mustard"}, {MAYO, "Mayonnaise"}, {SPECIAL, "Special Sauce"},
	{BBQ, "BBQ Sauce"}, {STEAK, "Steak Sauce"}, {PEPPERCORN, "Peppercorn Ranch"}, {NOCOND, "None"}
};
static std::map<std::string, condimentType, comparator> caseInsensitiveStringToCondimentTypeMap{
	{"Ketchup", KETCHUP}, {"Mustard", MUSTARD }, {"Mayonnaise", MAYO}, {"Special Sauce", SPECIAL},
	{"BBQ Sauce", BBQ}, {"Steak Sauce", STEAK}, {"Peppercorn Ranch", PEPPERCORN}, {"None", NOCOND}
};
static std::map<proteinType, std::string> proteinTypeToStringMap{
	{BEEF, "Beef"}, {TURKEY, "Turkey"}, {CHICKEN, "Chicken Breast"},
	{MUSH, "Portabella Mushroom"}, {VEGGIE, "Veggie"}
};
static std::map<std::string, proteinType, comparator> caseInsensitiveStringToProteinTypeMap{
	{"Beef", BEEF}, {"Turkey", TURKEY}, {"Chicken Breast", CHICKEN},
	{"Portabella Mushroom", MUSH}, {"Veggie", VEGGIE}
};
static std::map<toppingType, std::string> toppingTypeToStringMap{
	{GRILLONION, "Grilled Onion"}, {RAWONION, "Raw Onion"}, {TOMATO, "Tomato"},
	{LETTUCE, "Lettuce"}, {BACON, "Bacon"}, {MUSHROOM, "Grilled Mushroom"},
	{PICKLE, "Pickle"}, {NOTOP, "None"}
};
static std::map<std::string, toppingType, comparator> caseInsensitiveStringToToppingTypeMap{
	{"Grilled Onion", GRILLONION}, {"Raw Onion", RAWONION}, {"Tomato", TOMATO},
	{"Lettuce", LETTUCE}, {"Bacon", BACON}, {"Grilled Mushroom", MUSHROOM},
	{"Pickle", PICKLE}, {"None", NOTOP}
};

//Your class goes here
class burger {
private:
    proteinType protein;
    condimentType condiments[7];
    toppingType toppings[7];
    bunType bun;
    cheeseType cheese;
    int numPatties;
    mutable bool isVeg; // in order to alter only isVeg in isVeggie, isVeggie being a const function, we make isVeg mutable
    int numCondiments;
    int numToppings;


public:
    // constructor
	burger(proteinType protein, condimentType condemints[], int numCondiments, toppingType toppings[], int numToppings, bunType bun, cheeseType cheese, int numPatties);

    // getters
    proteinType getProtein() const;
    std::string getCondiments() const;
    std::string getToppings() const;
    bunType getBun() const;
    cheeseType getCheese() const;
    bool isVeggie() const;
    int getNumPatties() const;
    double getPrice() const;

    // setters

    void setProtein(proteinType protein);
    void setCondiments(condimentType condiments[], int numCondiments);
    void setToppings(toppingType toppings[], int numToppings);
    void setBun(bunType bun);
    void setCheese(cheeseType cheese);
    void setNumPatties(int numPatties);

    // other functions

    std::string tostring();

};


#endif