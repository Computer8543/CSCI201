/* Program name: bag.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/24/2024
*  Purpose: Create class implentation of methods for bag class here
*/

//class implementation goes here
#include "candy.h"
#include "bag.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

bag::bag() {
    // set variables to default
    candies = NULL; // set up a new address for candies
    numCandies = 0;
}
bag::bag(const bag& otherBag)
{
    copyBag(otherBag);
}
bag::~bag()
{
    // delete candies' elements first
    for (int i = 0; i < numCandies; i++)
    {
        delete candies[i];
        candies[i] = NULL;
    }

    // then delete candies dynamic array
    delete[] candies;
    candies = NULL;


}
bool bag::duplicateCheck(int currentCount, candy newCandy) // note: need to fix that too, don't use this function yet as it won't return the correct value.
{
    // If the candy is a duplicate, return true. If it is not a duplicate, return false.
    // Also return false if the candy is the same as itself.
    for (int j = 0; j < currentCount; j++)
    {
        if (currentCount == 0)
        {
            return false;
        }
        else if ((candies[j]->getColor() == newCandy.getColor()) && (candies[j]->getFlavor() == newCandy.getFlavor()))
        {
            return true;
        }
    }
    return false;
}
std::string bag::getCandyList()
{
    // declare variable
    std::stringstream outputStream;

    for (int k = 0; k < numCandies; k++)
    {
        outputStream << "#" << (k + 1) << " " << (*candies[k]).colorTypeEnumToString((*candies[k]).intToColorType((*candies[k]).getColor())) << " " << (*candies[k]).flavorTypeEnumToString((*candies[k]).intToFlavorType((*candies[k]).getFlavor())) << std::endl;
    }

    return outputStream.str(); // return the stringstream object as a string
}
void bag::copyBag(const bag& otherBag) // note: need to fix this
{
    // set variables to be the same as otherBag
    numCandies = otherBag.numCandies;
    candies = new candy * [numCandies]; // this assigns our candies address to be different than otherBag's, while creating a new dynamically allocated array to hold the candies

    if (otherBag.candies)
    {
        // we fill up candies[i] with filler data so that it doesn't try to say that we can't access the data in candies
        for (int i = 0; i < numCandies; i++)
        {
            candies[i] = new candy(COTTON_CANDY, SCARLET_BLAZE);
        }

        // we do a deep copy of the candies in the bag by using a for loop to iterate across the candies array. We translate the int returned from getColor() and getFlavor() into the corresponding enum using intToColorType() and intToFlavorType() respectively, which we then set for candies[i].
        for (int j = 0; j < otherBag.numCandies; j++)
        {
            candies[j]->setColor(otherBag.candies[j]->intToColorType(otherBag.candies[j]->getColor()));
            candies[j]->setFlavor(otherBag.candies[j]->intToFlavorType(otherBag.candies[j]->getFlavor()));
        }
    }
}
void bag::fillBag()
{
    int numCandiesTotal = 0;
    flavorType newFlavor;
    bool candiesDuplicate = false;

    // get the number of candies ordered for the dynamic array
    howManyCandiesWillYouOrder(numCandiesTotal);

    // create an dynamic array of candy pointers using a double pointer 
    candies = new candy * [numCandiesTotal];

    // populate the dynamic array with a for loop
    for (int i = 0; i < numCandiesTotal; i++)
    {
        std::cout << "Candy #" << (i + 1) << " of " << numCandiesTotal << std::endl;
        newFlavor = flavorInputVerificationLoop();
        colorInputVerificationLoop(newFlavor, candiesDuplicate);
        if (candiesDuplicate == true)
        {
            std::cout << getCandyList();
            i--;
        }
        else
        {
            std::cout << getCandyList();
            
        }
        candiesDuplicate = false;


    }

}

void bag::howManyCandiesWillYouOrder(int& numCandiesTotal) {

    // input verification loop to ensure that numberOfCandiesOrdered is between 1 and 25
    std::cout << "How many candies will you be ordering today? (range: 1-25)";
    std::cin >> numCandiesTotal;
    std::cout << std::endl;

    do {
        if ((!(std::cin)))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            numCandiesTotal = 0;
            std::cout << "That's not a number." << std::endl;
            std::cout << "Invalid entry. Number must be between 1 and 25 inclusive. Try again." << std::endl;
            std::cin >> numCandiesTotal;
            std::cout << std::endl;
            continue;
        }
        else if (numCandiesTotal < 1 || numCandiesTotal > 25)
        {
            std::cout << "Invalid entry. Number must be between 1 and 25 inclusive. Try again." << std::endl;
            std::cin >> numCandiesTotal;
            std::cout << std::endl;
            continue;
        }
        else {
            break;
        }
    } while (true);

}

void bag::flavorMenu() {
    std::cout << "Choose a flavor you would like:" << std::endl;
    std::cout << "[1] Cotton Candy" << std::endl;
    std::cout << "[2] Watermelon Burst" << std::endl;
    std::cout << "[3] Papaya Bliss" << std::endl;
    std::cout << "[4] Citrus Splash" << std::endl;
    std::cout << "[5] Cola" << std::endl;
}

flavorType bag::flavorInputVerificationLoop() {
    int flavorMenuChoice = 0;

    // get user choice to flavor menu
    flavorMenu();
    std::cin >> flavorMenuChoice;
    std::cout << std::endl;

    do {
        if ((!(std::cin)))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            flavorMenuChoice = 0;
            std::cout << "That's not a number." << std::endl;
            std::cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again." << std::endl;
            std::cin >> flavorMenuChoice;
            std::cout << std::endl;
            continue;
        }
        else if (flavorMenuChoice < 1 || flavorMenuChoice > 5)
        {
            std::cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again." << std::endl;
            std::cin >> flavorMenuChoice;
            std::cout << std::endl;
            continue;
        }
        else {
            switch (flavorMenuChoice)
            {
            case 1:
            {
                std::cout << (*candies[numCandies]).flavorTypeEnumToString(COTTON_CANDY) << "? Great choice." << std::endl;
                return COTTON_CANDY;
            }
            case 2:
            {
                std::cout << (*candies[numCandies]).flavorTypeEnumToString(WATERMELON_BURST) << "? Great choice." << std::endl;
                return WATERMELON_BURST;
            }
            case 3:
            {
                std::cout << (*candies[numCandies]).flavorTypeEnumToString(PAPAYA_BLISS) << "? Great choice." << std::endl;
                return PAPAYA_BLISS;
            }
            case 4:
            {
                std::cout << (*candies[numCandies]).flavorTypeEnumToString(CITRUS_SPLASH) << "? Great choice." << std::endl;
                return CITRUS_SPLASH;
            }
            case 5:
            {
                std::cout << (*candies[numCandies]).flavorTypeEnumToString(COLA) << "? Great choice." << std::endl;
                return COLA;
            }
            default:
            {
                throw std::invalid_argument("What is entered is not an integer between 1 and 5");
            }
            }
        }
    } while (true);

}

void bag::colorMenu(flavorType newFlavor) {
    std::cout << "Choose a color for your " << (*candies[numCandies]).flavorTypeEnumToString(newFlavor) << " candy:" << std::endl;
    std::cout << "[1] Scarlet Blaze" << std::endl;
    std::cout << "[2] Azure Sky" << std::endl;
    std::cout << "[3] Emerald Mist" << std::endl;
    std::cout << "[4] Goldenrod Glow" << std::endl;
    std::cout << "[5] Amethyst Haze" << std::endl;
}

void bag::colorInputVerificationLoop(flavorType newFlavor, bool& candiesDuplicate) {
    // initialize variables
    int colorMenuChoice = 0;


    // get user choice to color menu
    colorMenu(newFlavor);
    std::cin >> colorMenuChoice;
    std::cout << std::endl;

    do {
        if ((!(std::cin)))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            colorMenuChoice = 0;
            std::cout << "That's not a number." << std::endl;
            std::cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again." << std::endl;
            std::cin >> colorMenuChoice;
            std::cout << std::endl;
            continue;
        }
        else if (colorMenuChoice < 1 || colorMenuChoice > 5)
        {
            std::cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again." << std::endl;
            std::cin >> colorMenuChoice;
            std::cout << std::endl;
            continue;
        }
        else {
            // we need to check to see if the candies array has duplicate orders (same flavor and same color)
            switch (colorMenuChoice)
            {
            case 1:
            {
                std::cout << (*candies[numCandies]).colorTypeEnumToString(SCARLET_BLAZE) << " " << (*candies[numCandies]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;

                if (numCandies > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numCandies; j++)
                    {
                        if ((SCARLET_BLAZE == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
                            std::cout << "Your order:" << std::endl;
                            candiesDuplicate = true;
                            break;
                        }
                        else
                        {
                            continue;
                        }

                    }
                    if (candiesDuplicate == false)
                    {
                        std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                        std::cout << "Your order:" << std::endl;
                        candies[numCandies] = new candy(newFlavor, SCARLET_BLAZE); // we need to use new to dynamically allocate the candy object to the memory
                        numCandies++;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                    std::cout << "Your order:" << std::endl;
                    candies[numCandies] = new candy(newFlavor, SCARLET_BLAZE);
                    numCandies++;
                    break;
                }
                break;
            }
            case 2:
            {
                std::cout << (*candies[numCandies]).colorTypeEnumToString(AZURE_SKY) << " " << (*candies[numCandies]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;
                if (numCandies > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numCandies; j++)
                    {
                        if ((AZURE_SKY == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
                            std::cout << "Your order:" << std::endl;
                            candiesDuplicate = true;
                            break;
                        }
                        else
                        {

                            continue;
                        }
                    }
                    if (candiesDuplicate == false)
                    {
                        std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                        std::cout << "Your order:" << std::endl;
                        candies[numCandies] = new candy(newFlavor, AZURE_SKY);
                        numCandies++;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                    std::cout << "Your order:" << std::endl;
                    candies[numCandies] = new candy(newFlavor, AZURE_SKY);
                    numCandies++;
                    break;
                }
                break;

            }
            case 3:
            {
                std::cout << (*candies[numCandies]).colorTypeEnumToString(EMERALD_MIST) << " " << (*candies[numCandies]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;
                if (numCandies > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numCandies; j++)
                    {
                        if ((EMERALD_MIST == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
                            std::cout << "Your order:" << std::endl;
                            candiesDuplicate = true;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (candiesDuplicate == false)
                    {
                        std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                        std::cout << "Your order:" << std::endl;
                        candies[numCandies] = new candy(newFlavor, EMERALD_MIST);
                        numCandies++;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                    std::cout << "Your order:" << std::endl;
                    candies[numCandies] = new candy(newFlavor, EMERALD_MIST);
                    numCandies++;
                    break;
                }
                break;

            }
            case 4:
            {
                std::cout << (*candies[numCandies]).colorTypeEnumToString(GOLDENROD_GLOW) << " " << (*candies[numCandies]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;

                if (numCandies > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numCandies; j++)
                    {
                        if ((GOLDENROD_GLOW == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
                            std::cout << "Your order:" << std::endl;
                            candiesDuplicate = true;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (candiesDuplicate == false)
                    {
                        std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                        std::cout << "Your order:" << std::endl;
                        candies[numCandies] = new candy(newFlavor, GOLDENROD_GLOW);
                        numCandies++;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                    std::cout << "Your order:" << std::endl;
                    candies[numCandies] = new candy(newFlavor, GOLDENROD_GLOW);
                    numCandies++;
                    break;
                }
                break;

            }
            case 5:
            {
                std::cout << (*candies[numCandies]).colorTypeEnumToString(AMETHYST_HAZE) << " " << (*candies[numCandies]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;

                if (numCandies > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numCandies; j++)
                    {
                        if ((AMETHYST_HAZE == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
                            std::cout << "Your order:" << std::endl;
                            candiesDuplicate = true;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (candiesDuplicate == false)
                    {
                        std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                        std::cout << "Your order:" << std::endl;
                        candies[numCandies] = new candy(newFlavor, AMETHYST_HAZE);
                        numCandies++;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    std::cout << "Marvelous! Your candy was added to the order." << std::endl;
                    std::cout << "Your order:" << std::endl;
                    candies[numCandies] = new candy(newFlavor, AMETHYST_HAZE);
                    numCandies++;
                    break;
                }
                break;

            }
            default:
            {
                throw std::invalid_argument("What is entered is not an integer between 1 and 5");
            }
            }
            break;
        }
    } while (true);
}
