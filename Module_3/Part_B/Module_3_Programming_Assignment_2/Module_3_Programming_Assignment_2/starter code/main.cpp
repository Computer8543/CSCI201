#include "candy.h"
#include <iostream>
#include <iomanip>
#include <limits>

void intro();
void resetStream();

int main()
{

    std::cout << "Thank you for choosing The Cavity Factory, where tooth decay is our priority!" << std::endl;

    return 0;
}

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
