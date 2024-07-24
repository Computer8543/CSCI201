// Module_6_Lecture_Code_Notes_Assert.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <assert.h>

// function prototype
double accumulateTotal(int total, int newValue) throw (std::invalid_argument, std::overflow_error, std::underflow_error); // we can put a throw statement in the function header to specify the type of errors that can be thrown

int main()
{
    int x;
    int total = 0;
    

    for (int i = 0; i < 10; i++)
    {
        /*
        while (x < 0) {
            std::cout << "Invalid Value!!!!" << std::endl;
            std::cout << "Enter a value: ";
            std::cin >> x;
        }
        */

        while (true) {
            try {
                std::cout << "Enter a value: ";
                std::cin >> x;
                accumulateTotal(total, x);
                // assert will ABORT immediately if the "assertion" fails
                // do not leave an assertion in production code
                // assert(x < 100);
                break;
            }
            catch (std::invalid_argument& e) { // include a referance to the actual object being thrown so it gets handled! 
                std::cout << e.what() << std::endl;
                // write to a log file
            }
            catch (std::logic_error& e) { // execute base classes of errors last, with derived classes of errors first, since the base class covers all the derived classes.
                std::cout << e.what() << std::endl;
            }
            // catch (int& e) {
            //    std::cout << x << " is out of range - ignored!!!" << std::endl;
            // }
            catch (std::overflow_error& e) {
                std::cout << e.what() << std::endl;
                break;
                // write to a log file
            }
            catch (std::underflow_error& e) {
                std::cout << e.what() << std::endl;
            }
            catch (...) {
                std::cout << "This catches anything!!!!" << std::endl;
                std::cerr << "This catches anything!!!!" << std::endl; // cerr is standard error, by default set to cout, but can be redirected to an log file
            }
        }
    }
    

    std::cout << "x = " << x << std::endl;

    
    system("pause"); // output a "press any key to continue" message and wait

    return 0;
}
// function definitions
double accumulateTotal(int total, int newValue) throw (std::invalid_argument, std::overflow_error, std::underflow_error) {
    
    if (newValue < 0)
    {
        // throw newValue;
        throw std::invalid_argument("Value cannot be < 0!!!!");
    }

    if (total + newValue > 100) {
        throw std::overflow_error("Value would exceed upper limit!!!");
    }

    
    throw std::underflow_error("Minimum not reached");
    
    total += newValue;

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
