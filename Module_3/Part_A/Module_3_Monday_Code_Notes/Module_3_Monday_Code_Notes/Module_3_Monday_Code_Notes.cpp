// Module_3_Monday_Code_Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

/*
void doubleTheValue(int& x) {
    x *= 2;
    std::cout << "x = " << x << std::endl;
}

void oldSchoolDoubleTheValue(int* x) {
    *x *= 2;
    std::cout << "x = " << *x << std::endl;
}
*/

int main()
{
    std::vector<std::string> shoppingList;
    char yesNo;
    std::string item;

    do {
        std::cout << "Add item: ";
        std::cin >> item;
        std::cout << std::endl;

        shoppingList.push_back(item);

        std::cout << "Another item? Y/n?";
        std::cin >> yesNo;
        std::cout << std::endl;

    } while (yesNo != 'n');

    std::cout << "Shopping list: " << std::endl;

    for (int i = 0; i < shoppingList.size(); i++)
    {
        std::cout << i << ": " << shoppingList[i] << std::endl;
        // or std::cout << i << ": " << shoppingList[i] << std::endl;
    }

    shoppingList.clear();

    while (!shoppingList.empty()) {
        shoppingList.pop_back();
    }
    /*
    int x = 0;
    int value = 5;

    int* ptr1 = NULL; // integer pointer points to a memory location containing an int

    float* ptr2 = NULL; // float pointer points to a memory location containing an float

    double* ptr3 = NULL; // double pointer points to a memory location containing an double (64 bit real number)
    /*
    int *intPtr = &x; // pointer is a variable that holds a memory address 
    int* anotherPointer = NULL;
    int * yetAnotherPointer = NULL;
        
    int* a = NULL, b, c; // a is a pointer, b and c are not pointers

    if (intPtr != NULL) {
        std::cout << "IntPtr points to " << *intPtr << std::endl;
    }
    else {
        std::cout << "IntPtr doesn't point to anything yet." << std::endl;
    }

    std::cout << "Input an integer for x" << std::endl;
    std::cin >> x;
    std::cout << "x = " << x << std::endl;
    std::cout << "x is at location " << &x << std::endl; // & - location at operator, tells us where memory address is at
    std::cout << "intPtr = " << intPtr << std::endl;
    std::cout << "intPtr points to " << *intPtr << std::endl;

    int myGrades[5];

    for (int i = 0; i < 5; i++) {
        myGrades[i] = i;
    }

    std::cout << myGrades << "is the starting address of the array" << std::endl;

    std::cout << *myGrades << " is value 0 " << std::endl;

    std::cout << *(myGrades + 1) << "is value 1" << std::endl;
    */

    /*
    doubleTheValue(value);

    std::cout << "value = " << value << std::endl;

    oldSchoolDoubleTheValue(&value);

    std::cout << "value = " << value << std::endl;
    */
    /*
    int numPlayers;
    double* scores = NULL;
    char playAgain = 'Y';
    */
    /*
    do {
        do {
            std::cout << "How many players???";
            std::cin >> numPlayers;
            std::cout << std::endl;
        } while (numPlayers <= 0 || numPlayers > 100);

        try {
            scores = new double[numPlayers]; // give me a block of memory size numPlayers
        }
        catch (std::bad_alloc& e) {
            // handle the memory error
            std::cout << e.what() << std::endl;
        }

        for (int i = 0; i < numPlayers; i++)
        {
            // play move for each player
            std::cout << "Player " << i << " plays!!!" << std::endl;

        }

        // not releasing the memory when finished with it creates an memory leak
        // delete[] scores; // releases the memory you requested
        
        // dangling pointer
        /*
        for (int i = 0; i < numPlayers; i++) {
            std::cout << "score for player " << i << " = " << scores[i] << std::endl;
        }
        */
        /*
        delete[] scores;
        scores = NULL;

        std::cout << "Play Again???";
        std::cin >> playAgain;
        std::cout << std::endl;

    } while (playAgain == 'Y');
    */
    // memory leak is when we keep asking for memory, but we don't give it back when done

    // ten thousand other things to do

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
