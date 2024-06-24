/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/24/2024
*  Purpose: Create a program that will allow the user to create a custom candy mix
*/

#include "candy.h"
#include "bag.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// function prototypes
void intro();
void resetStream();
int howManyBagsOfCandyWillYouOrderToday();
int howManyBagsLikeTheLastOneWouldYouLike(const int numOfBagsOfCandy, const int numOfBagsOfCandyTheyHaveLeftToFill);

int main()
{
    // initialize variables
    int numBagsOfCandy = 0; // number of bags of candy
    int numOfBagsLikeTheLastOne = 0;
    int o = 0; // iterator for copy function loop
    bag* bagsPtr = NULL;

    // give introduction to the user
    intro();
    std::cout << std::endl;
    std::cout << std::endl;

    // get numBagsOfCandy from the user
    numBagsOfCandy = howManyBagsOfCandyWillYouOrderToday();

    // initalize dynamic array;
    bagsPtr = new bag[numBagsOfCandy];
    // loop through and populate each bag in the array with candy
    for (int n = 0; n < numBagsOfCandy; n++)
    {
        // show bag number
        std::cout << "Bag #" << (n + 1) << " of " << numBagsOfCandy << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        // fill bag with candy
        bagsPtr[n].fillBag(); // fill bag function is working perfectly well, it just the copy function that automatically destroys the bag after it gets out of scope;

        // ask the user how many bags like the last one you would like
        numOfBagsLikeTheLastOne = howManyBagsLikeTheLastOneWouldYouLike(numBagsOfCandy, (numBagsOfCandy - (n + 1)));

        // use copy function if the number of bags like the last one is greater than 0 and less than numBagsOfCandy minus the iterator n.
        if (numOfBagsLikeTheLastOne > 0 && numOfBagsLikeTheLastOne < (numBagsOfCandy - n))
        {
            for (int o = (n + 1); o < ((n + 1) + numOfBagsLikeTheLastOne); o++)
            {
                bagsPtr[o].copyBag(bagsPtr[n]); // note: the bag gets deleted before it even gets out of scope!
            }
            n += (o + numOfBagsLikeTheLastOne); // in order to prevent the loop from continuing on and overwriting the copied object, we need to add (o + 1) to the iterator n.
       
            
        }



    }
    
    // give user output of their order
    std::cout << "Your order:" << std::endl;
    
    for (int p = 0; p < numBagsOfCandy; p++)
    {
        std::cout << "Bag #" << (p + 1) << std::endl;
        std::cout << bagsPtr[p].getCandyList();
        std::cout << std::endl;
        std::cout << std::endl;

    }

    // delete bagsPtr, we don't need to worry about the elements since bagsPtr is only a single pointer and the bags have their own destructor that handles the candy objects

    delete[] bagsPtr;
    bagsPtr = NULL;


    std::cout << "Thank you for choosing The Cavity Factory, where tooth decay is our priority!" << std::endl;

    return 0;
}

// function definitions
void intro()
{
    std::cout << std::setfill('=') << std::setw(90) << " " << std::endl;
    std::cout << std::setfill(' ') << std::setw(60) << "Welcome to The Cavity Factory!" << std::endl;
    std::cout << std::setfill('=') << std::setw(90) << " " << std::endl;

    std::cout << "\n- We allow our beloved Candy Connoisseurs (yes, that'd be you) to build their own candy!" << std::endl;
    std::cout << "There's only one catch: To ensure that our customers explore their palate,\n"
              << "we only allow unique candy to be ordered in each bag. Don't think of it as a limitation, but as an EXPERIENCE!" << std::endl;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int howManyBagsOfCandyWillYouOrderToday() {
    int numBagsOfCandy = 0;

    std::cout << "How many bags of candy will you be ordering today?";
    std::cin >> numBagsOfCandy;
    std::cout << std::endl;

    do 
    {
        if (!(std::cin))
        {
            resetStream();
            numBagsOfCandy = 0;
            std::cout << "That's not a number." << std::endl;
            std::cout << "Invalid entry. Number must be between 1 and 10000 inclusive. Try again." << std::endl;
            std::cin >> numBagsOfCandy;
            std::cout << std::endl;
            continue;
        }
        else if (numBagsOfCandy < 1 || numBagsOfCandy > 10000)
        {
            std::cout << "Invalid entry. Number must be between 1 and 10000 inclusive. Try again." << std::endl;
            std::cin >> numBagsOfCandy;
            std::cout << std::endl;
            continue;
        }
        else 
        {
            return numBagsOfCandy;
        }

    } while (true);


}

int howManyBagsLikeTheLastOneWouldYouLike(const int numOfBagsOfCandy, const int numOfBagsOfCandyTheyHaveLeftToFill) {
    // initialize variable
    int numOfBagsLikeTheLastOne = 0;

    std::cout << "How many more bags like the last one would you like?";
    std::cin >> numOfBagsLikeTheLastOne;
    std::cout << std::endl;

    do
    {
        if (!(std::cin))
        {
            resetStream();
            numOfBagsLikeTheLastOne = 0;
            std::cout << "That's not a number." << std::endl;
            std::cout << "Invalid entry. Number must be between 0 and " << numOfBagsOfCandy << " inclusive. Try again.";
            std::cin >> numOfBagsLikeTheLastOne;
            std::cout << std::endl;
            continue;
        }
        else if (numOfBagsLikeTheLastOne < 0 || numOfBagsLikeTheLastOne > 10000)
        {
            std::cout << "Invalid entry. Number must be between 0 and " << numOfBagsOfCandy << " inclusive. Try again.";
            std::cin >> numOfBagsLikeTheLastOne;
            std::cout << std::endl;
            continue;
        }
        else if (numOfBagsLikeTheLastOne > numOfBagsOfCandyTheyHaveLeftToFill)
        {
            std::cout << "Invalid entry. Number must be between 0 and " << numOfBagsOfCandy << " inclusive. Try again.";
            std::cin >> numOfBagsLikeTheLastOne;
            std::cout << std::endl;
            continue;
        }
        else
        {
            return numOfBagsLikeTheLastOne;
        }

    } while (true);
}