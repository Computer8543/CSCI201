/* Program name: burger.h
* Author: Kyle Ingersoll
* Date last updated: 6/11/2024
* Purpose: Create a class prototype for burger, as well as list the various enums 
*/
#ifndef BURGER_H
#define BURGER_H

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include <sstream> // for the stringstream for the toString() method so it can output a formatted string

// enumerations listed here
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