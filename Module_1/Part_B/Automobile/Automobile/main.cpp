#include <iomanip>
#include <string>
#include "Automobile.h"

void printCarSpecs(const Automobile &thisAutomobile) { // friend breaks protection upon the class's private members
	
	std::cout << thisAutomobile.make << " " << thisAutomobile.model << std::endl;
	thisAutomobile.milage = 0;
}

int main() {

	std::cout << "We have " << Automobile::getCarCount() << " Cars!!!" << std::endl;

	Automobile myAuto(Chevy, "Citation", "Red", "VX123FGR12", 1999, true, true);

	printCarSpecs(myAuto);

	std::cout << "We have " << Automobile::getCarCount() << " Cars!!!" << std::endl;

	Make carMake;
	std::string carModel;

	std::cout << "Enter Make: ";
	std::cin >> carMake;
	std::cout << std::endl;
	std::cout << "Enter Model: ";
	std::cin >> carModel;
	std::cout << std::endl;

	std::cout << makes[Chevy] << std::endl;

	std::cout << myAuto.toString() << std::endl;

	myAuto.paint("Red");
	double distance;
	do {
		std::cout << "Enter distance you want to drive: ";
		std::cin >> distance;
		std::cout << std::endl;
	} while (distance <= 0);

	while (true) {
		try {
			std::cout << "You drove " << myAuto.drive(distance) << std::endl;
			break;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;

			std::cout << "Enter distance you want to drive: ";
			std::cin >> distance;
			std::cout << std::endl;
		}
	}
	

	std::cout << "You drove " << myAuto.drive(500.0) << std::endl;

	std::cout << myAuto.toString() << std::endl;

	std::cout << "You added " << myAuto.refuel(500.0) << std::endl;

	std::cout << myAuto.toString() << std::endl;


	
	return 0;

}