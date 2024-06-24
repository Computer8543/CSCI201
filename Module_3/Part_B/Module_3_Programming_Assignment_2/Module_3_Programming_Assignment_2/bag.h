/* Program name: candy.h
*  Author: Kyle Ingersoll
*  Date last updated: 6/24/2024
*  Purpose: Create class definition for bag class 
*/

#ifndef BAG_H
#define BAG_H

#include "candy.h"
#include <string>

// class definition goes here
class bag {
private:
	candy** candies;
	int numCandies;
public:
    bag();
    bag(const bag& otherBag);
    ~bag();
    bool duplicateCheck(int currentCount, candy newCandy);
    std::string getCandyList();
    void copyBag(const bag& otherBag);
    void fillBag();
    void howManyCandiesWillYouOrder(int& numCandiesTotal);
    void flavorMenu();
    flavorType flavorInputVerificationLoop();
    void colorMenu(flavorType newFlavor);
    void colorInputVerificationLoop(flavorType newFlavor, bool& candiesDuplicate);
};

#endif