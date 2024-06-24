/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/20/2024
*  Purpose: Create a program that will allow the user to create a custom candy mix
*/

#include "candy.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// function prototypes
void intro();
void resetStream();
int howManyCandiesWillYouOrder();
void flavorMenu();
flavorType flavorInputVerificationLoop(candy**& candies, const int& numberOfCandiesObjects);
void colorMenu(flavorType newFlavor, candy**& candies, const int& numberOfCandiesObjects);
void colorInputVerificationLoop(flavorType newFlavor, candy**& candies, const int numberOfCandiesOrdered, int& numberOfCandiesObjects, bool& candiesDuplicate);
void yourOrder(candy**& candies, int& numberOfCandiesObjects);
colorType intToColorType(int enumNum);
flavorType intToFlavorType(int enumNum);

int main()
{
    candy** candies = NULL; // use two asterisks when making an array of pointers, furthermore, you cannot use a pointer of one data type to point to a pointer of another data type
    int numberOfCandiesOrdered = 0; // total candies ordered
    int numberOfCandiesObjects = 0; // how many candy objects exist
    flavorType newFlavor;
    bool candiesDuplicate = false;

    // give introduction to the user
    intro();
    std::cout << std::endl;
    std::cout << std::endl;

    // get the number of candies ordered for the dynamic array
    numberOfCandiesOrdered = howManyCandiesWillYouOrder();

    // create an dynamic array of candy pointers using a double pointer 
    candies = new candy*[numberOfCandiesOrdered];

    // populate the dynamic array with a for loop
    for (int i = 0; i < numberOfCandiesOrdered; i++)
    {
        std::cout << "Candy #" << (i + 1) << " of " << numberOfCandiesOrdered << std::endl;
        newFlavor = flavorInputVerificationLoop(candies, numberOfCandiesObjects);
        colorInputVerificationLoop(newFlavor, candies, numberOfCandiesOrdered, numberOfCandiesObjects, candiesDuplicate);
        if (candiesDuplicate == true)
        {
            yourOrder(candies, numberOfCandiesObjects);
            i--;
        }
        else 
        {
            yourOrder(candies, numberOfCandiesObjects);
        }
        candiesDuplicate = false;
        

    }

    // free the memory used by candies, then set candies to NULL to avoid a dangling pointer
    for (int m = 0; m < numberOfCandiesOrdered; m++)
    {
        delete candies[m]; // only use [] when deleting the array. Delete the individual elements first, then the array.
        candies[m] = NULL;
        numberOfCandiesObjects--;
    }
    delete[] candies;
    candies = NULL;

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
              << "we only allow unique candy to be ordered. Don't think of it as a limitation, but as an EXPERIENCE!" << std::endl;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int howManyCandiesWillYouOrder() {
    // initialize variable
    int numberOfCandiesOrdered = 0;

    // input verification loop to ensure that numberOfCandiesOrdered is between 1 and 25
    std::cout << "How many candies will you be ordering today? (range: 1-25)";
    std::cin >> numberOfCandiesOrdered;
    std::cout << std::endl;

    do {
        if ((!(std::cin)))
        {
            resetStream();
            numberOfCandiesOrdered = 0;
            std::cout << "That's not a number." << std::endl;
            std::cout << "Invalid entry. Number must be between 1 and 25 inclusive. Try again." << std::endl;
            std::cin >> numberOfCandiesOrdered;
            std::cout << std::endl;
            continue;
        }
        else if (numberOfCandiesOrdered < 1 || numberOfCandiesOrdered > 25)
        {
            std::cout << "Invalid entry. Number must be between 1 and 25 inclusive. Try again." << std::endl;
            std::cin >> numberOfCandiesOrdered;
            std::cout << std::endl;
            continue;
        }
        else {
            return numberOfCandiesOrdered;
        }
    } while (true);
    
}

void flavorMenu() {
    std::cout << "Choose a flavor you would like:" << std::endl;
    std::cout << "[1] Cotton Candy" << std::endl;
    std::cout << "[2] Watermelon Burst" << std::endl;
    std::cout << "[3] Papaya Bliss" << std::endl;
    std::cout << "[4] Citrus Splash" << std::endl;
    std::cout << "[5] Cola" << std::endl;
}

flavorType flavorInputVerificationLoop(candy**& candies, const int& numberOfCandiesObjects) {
    int flavorMenuChoice = 0;
    
    // get user choice to flavor menu
    flavorMenu();
    std::cin >> flavorMenuChoice;
    std::cout << std::endl;

    do {
        if ((!(std::cin)))
        {
            resetStream();
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
                std::cout << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(COTTON_CANDY) << "? Great choice." << std::endl;
                return COTTON_CANDY;
            }
            case 2:
            {
                std::cout << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(WATERMELON_BURST) << "? Great choice." << std::endl;
                return WATERMELON_BURST;
            }
            case 3:
            {
                std::cout << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(PAPAYA_BLISS) << "? Great choice." << std::endl;
                return PAPAYA_BLISS;
            }
            case 4:
            {
                std::cout << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(CITRUS_SPLASH) << "? Great choice." << std::endl;
                return CITRUS_SPLASH;
            }
            case 5:
            {
                std::cout << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(COLA) << "? Great choice." << std::endl;
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

void colorMenu(flavorType newFlavor, candy**& candies, const int& numberOfCandiesObjects) {
    std::cout << "Choose a color for your " << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(newFlavor) << " candy:" << std::endl;
    std::cout << "[1] Scarlet Blaze" << std::endl;
    std::cout << "[2] Azure Sky" << std::endl;
    std::cout << "[3] Emerald Mist" << std::endl;
    std::cout << "[4] Goldenrod Glow" << std::endl;
    std::cout << "[5] Amethyst Haze" << std::endl;
}

void colorInputVerificationLoop(flavorType newFlavor, candy**& candies, const int numberOfCandiesOrdered, int& numberOfCandiesObjects, bool& candiesDuplicate) {
    // initialize variables
    int colorMenuChoice = 0;
    

    // get user choice to color menu
    colorMenu(newFlavor, candies, numberOfCandiesObjects);
    std::cin >> colorMenuChoice;
    std::cout << std::endl;

    do {
        if ((!(std::cin)))
        {
            resetStream();
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
                std::cout << (*candies[numberOfCandiesObjects]).colorTypeEnumToString(SCARLET_BLAZE) << " " << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;
                
                if (numberOfCandiesObjects > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numberOfCandiesObjects; j++)
                    {
                        if ((SCARLET_BLAZE == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
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
                        candies[numberOfCandiesObjects] = new candy(newFlavor, SCARLET_BLAZE); // we need to use new to dynamically allocate the candy object to the memory
                        numberOfCandiesObjects++;
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
                    candies[numberOfCandiesObjects] = new candy(newFlavor, SCARLET_BLAZE);
                    numberOfCandiesObjects++;
                    break;
                }
                break;
            }
            case 2:
            {
                std::cout << (*candies[numberOfCandiesObjects]).colorTypeEnumToString(AZURE_SKY) << " " << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;
                if (numberOfCandiesObjects > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numberOfCandiesObjects; j++)
                    {
                        if ((AZURE_SKY == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
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
                        candies[numberOfCandiesObjects] = new candy(newFlavor, AZURE_SKY);
                        numberOfCandiesObjects++;
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
                    candies[numberOfCandiesObjects] = new candy(newFlavor, AZURE_SKY);
                    numberOfCandiesObjects++;
                    break;
                }
                break;
                
            }
            case 3:
            {
                std::cout << (*candies[numberOfCandiesObjects]).colorTypeEnumToString(EMERALD_MIST) << " " << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;
                if (numberOfCandiesObjects > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numberOfCandiesObjects; j++)
                    {
                        if ((EMERALD_MIST == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
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
                        candies[numberOfCandiesObjects] = new candy(newFlavor, EMERALD_MIST);
                        numberOfCandiesObjects++;
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
                    candies[numberOfCandiesObjects] = new candy(newFlavor, EMERALD_MIST);
                    numberOfCandiesObjects++;
                    break;
                }
                break;
                
            }
            case 4:
            {
                std::cout << (*candies[numberOfCandiesObjects]).colorTypeEnumToString(GOLDENROD_GLOW) << " " << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;
                
                if (numberOfCandiesObjects > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numberOfCandiesObjects; j++)
                    {
                        if ((GOLDENROD_GLOW == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
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
                        candies[numberOfCandiesObjects] = new candy(newFlavor, GOLDENROD_GLOW);
                        numberOfCandiesObjects++;
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
                    candies[numberOfCandiesObjects] = new candy(newFlavor, GOLDENROD_GLOW);
                    numberOfCandiesObjects++;
                    break;
                }
                break;
                
            }
            case 5:
            {
                std::cout << (*candies[numberOfCandiesObjects]).colorTypeEnumToString(AMETHYST_HAZE) << " " << (*candies[numberOfCandiesObjects]).flavorTypeEnumToString(newFlavor) << " it is!" << std::endl;
                
                if (numberOfCandiesObjects > 0)
                {
                    // check to prevent duplicates of candy orders
                    for (int j = 0; j < numberOfCandiesObjects; j++)
                    {
                        if ((AMETHYST_HAZE == candies[j]->getColor()) && (newFlavor == candies[j]->getFlavor()))
                        {
                            std::cout << "But wait, this is not unique, try again." << std::endl;
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
                        candies[numberOfCandiesObjects] = new candy(newFlavor, AMETHYST_HAZE);
                        numberOfCandiesObjects++;
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
                    candies[numberOfCandiesObjects] = new candy(newFlavor, AMETHYST_HAZE);
                    numberOfCandiesObjects++;
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

void yourOrder(candy**& candies, int& numberOfCandiesObjects)
{
    // displays user order back to them
    std::cout << "Your order:" << std::endl;

    for (int k = 0; k < numberOfCandiesObjects; k++)
    {
        std::cout << "#" << (k + 1) << " " << (*candies[k]).colorTypeEnumToString(intToColorType((*candies[k]).getColor())) << " " << (*candies[k]).flavorTypeEnumToString(intToFlavorType((*candies[k]).getFlavor())) << std::endl; // fix this problem
    }
}

colorType intToColorType(int enumNum) {
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
flavorType intToFlavorType(int enumNum) {
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
