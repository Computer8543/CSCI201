// Module_2_Part_B_Code_Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Employee.h"

int main()
{
    // Circle myCircle(3.0);
    // std::cout << myCircle.getRadius() << std::endl;

    Employee James("James", "054-34-5432", "C02345");
    James.work();
    std::cout << James.name << std::endl;

    // KAR 6/12/24 - Corrected Spelling and Employee Number
    // Secretary Terry("Terense", "054-66-5432", "C02845", 54);
    Secretary Terry("Terence", "054-66-5432", "C02875", 54);
    Terry.work();
    std::cout << Terry.name << std::endl;

    LegalSecretary Susan("Susan", "194-34-5482", "C026345", 54);
    Susan.work();
    std::cout << Susan.name << std::endl;

    Programmer Katie("Katie", "164-24-5762", "C04435", "C++");
    Katie.work();
    std::cout << Katie.name << std::endl;
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
