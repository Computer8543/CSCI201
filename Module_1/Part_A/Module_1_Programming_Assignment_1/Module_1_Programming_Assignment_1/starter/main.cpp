/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/7/2024
*  Purpose: Allow the user to enter information and order a notebook.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept> // for invalid argument exception
#include <sstream> // for the stringstream for the toString() method so it can output a formatted string
#include <cmath> // for finding the positive difference between 0 and a negative number.
#include "notebook.h"

// to handle input failure
void notANumberInputFailure()
{
    // clears buffer, cuts out escape character, and informs the user of their error
    std::cin.clear();
    std::cin.ignore(200, '\n');
    std::cout << "You entered something that is not a number!" << std::endl;
    std::cout << "Please enter a number greater than 0." << std::endl;
    return;
}
void negativeNumberInputFailure()
{
    // clears buffer, cuts out escape character, and informs the user of their error
    std::cin.clear();
    std::cin.ignore(200, '\n');
    std::cout << "Please enter a number greater than 0." << std::endl;
    return;
}

int main()
{
    // main program goes here
    
    // variables declared here, I didn't use the names of the private variables so that I could avoid errors
    double w; // width
    double h; // height
    int p; // pages
    std::string pt; // paperType
    std::string f; // format
    std::string pc; // paperColor
    std::string ct; // coverType
    std::string cd; // coverDesign

    // sequence structure block encouraging user to input attribute information
    std::cout << "Enter the name of the cover color or design: ";
    std::getline(std::cin, cd);
    std::cout << std::endl;
    std::cout << "Enter the cover type: ";
    std::getline(std::cin, ct);
    std::cout << std::endl;
    std::cout << "Enter the paper color: ";
    std::getline(std::cin, pc);
    std::cout << std::endl;
    std::cout << "Enter the notebook format: ";
    std::getline(std::cin, f);
    std::cout << std::endl;
    std::cout << "Enter the type of paper: ";
    std::getline(std::cin, pt);
    std::cout << std::endl;

    // do while loops to check for input error for the number variables
    do
    {
        std::cout << "Enter the number of pages: ";
        std::cin >> p;
        std::cout << std::endl;

        if (!(std::cin))
        {
            notANumberInputFailure();
            continue;
        } 
        else if (p <= 0)
        {
            negativeNumberInputFailure();
            continue;
        }
            
        else
            break;
            
    } while (!(std::cin) or p <= 0);

    do
    {
        std::cout << "Enter the notebook height: ";
        std::cin >> h;
        std::cout << std::endl;

        if (!(std::cin))
        {
            notANumberInputFailure();
            continue;
        }
        else if (h <= 0)
        {
            negativeNumberInputFailure();
            continue;
        }
        else
            break;
    } while (!(std::cin) or h <= 0);
    
    do
    {
        std::cout << "Enter the notebook width: ";
        std::cin >> w;
        std::cout << std::endl;

        if (!(std::cin))
        {
            notANumberInputFailure();
            continue;
        }
        else if (w <= 0)
        {
            negativeNumberInputFailure();
            continue;
        }
        else
            break;
    } while (!(std::cin) or w <= 0);
    

    // build notebook object with constructor method
    notebook userNotebook = notebook(w, h, p, pt, f, pc, ct, cd);

    // display created notebook using toString function
    std::cout << userNotebook.toString();

    // exit the program normally
    return 0;
}

