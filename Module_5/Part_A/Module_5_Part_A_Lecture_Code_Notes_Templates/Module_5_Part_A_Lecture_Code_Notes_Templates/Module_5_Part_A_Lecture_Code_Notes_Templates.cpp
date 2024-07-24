// Module_5_Part_A_Lecture_Code_Notes_Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include "Array.h"

template<class TBD>
TBD maximum(TBD a, TBD b, TBD c) {
    TBD max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    return max;
}

int main()
{
    std::vector<std::string> shoppingList;
    std::vector<double> quizGrades;
    std::queue<std::string> students;
    std::stack<std::string> students2;
    std::set<std::string> students3;
    std::set<std::string>::iterator it;
    std::map<std::string, std::string> bookList; // isbn -> title
    std::map<std::string, std::string>::iterator it2;
    // create our OWN Template SAFE array class

    ARRAY<int> myArray(5);
    int temp;

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter value for array (" << i << "):";
        std::cin >> temp;
        // myArray.setValue(i, temp);
        myArray[i] = temp;
        std::cout << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter value for array (" << i << ") = " << myArray[i] << std::endl; 
    }

    ARRAY<std::string> shoppingList(20);

    int i1 = 1, i2 = 5, i3 = 9;

    std::cout << maximum(i1, i2, i3) << std::endl;

    double d1 = 2.3, d2 = 4.5, d3 = 3.4;

    std::cout << maximum(d1, d2, d3) << std::endl;

    students.push("Fred");
    students.push("Susan");
    students.push("Karen");

    std::cout << "Your queue is size " << students.size() << std::endl;

    students.push("Jacob");

    // front or back is a non-destructive "peek"
    std::cout << "First in line is " << students.front() << std::endl;

    students.pop();
    students.push("Tina");

    while (students.size() > 0) {
        std::cout << "Student " << students.front() << std::endl;
        students.pop();
    }

    students2.push("Fred");
    students2.push("Susan");
    students2.push("Karen");

    std::cout << "Your queue is size " << students2.size() << std::endl;

    students2.push("Jacob");

    // front or back is a non-destructive "peek"
    std::cout << "Top is " << students2.top() << std::endl;

    students2.pop();
    students2.push("Tina");

    while (students2.size() > 0) {
        std::cout << "Student " << students2.top() << std::endl;
        students2.pop();
    }

    students3.insert("Fred");
    students3.insert("Susan");
    students3.insert("Karen");

    std::cout << "Your set is size " << students3.size() << std::endl;

    students3.insert("Jacob");

    if (students3.count("Jacob") > 0)
    {
        std::cout << "Jacob is in the set." << std::endl;
        students3.erase("Jacob");
    }

    // use this for conditional structures, keeps a pointer to the one currently in the list
    for (it = students3.begin(); it != students3.end(); it++)
    {
        std::cout << *it << std::endl;
        if (it->length() < 5)
        {
            students3.erase(it);
        }
    }

    // for each loop, copies the object instead of pointing to it
    for (std::string student : students3) {
        std::cout << student << std::endl;
    }

    bookList["905454343"] = "Cujo";
    bookList["934343565"] = "The Stand";

    std::cout << bookList["905454343"] << std::endl;
    std::cout << bookList["934343565"] << std::endl;

    for (it2 = bookList.begin(); it2 != bookList.end(); it2++)
    {
        std::cout << (*it2).first << ": ";
        std::cout << it2->second << std::endl;
    }

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
