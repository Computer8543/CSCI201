#include <iomanip>
#include <string>
#include "Automobile.h"

int main() {
	Automobile myAuto(Chevy, "Citation", "Red", "VX123FGR12", 1999, true, true);

	std::cout << makes[Chevy] << std::endl;

	std::cout << myAuto.toString() << std::endl;

	myAuto.paint("Red");
	double distance;
	do {
		std::cout << "Enter distance you want to drive: ";
		cin >> distance;
		std::cout << std::endl;
	} while (distance <= 0);

	while (true) {
		try {
			std::cout << "You drove " << myAuto.drive(distance) << std::endl;
			break;
		}
		catch (invalid_argument& e) {
			std::cout << e.what() << std::endl;

			std::cout << "Enter distance you want to drive: ";
			cin >> distance;
			std::cout << std::endl;
		}
	}
	

	std::cout << "You drove " << myAuto.drive(500.0) << std::endl;

	std::cout << myAuto.toString() << std::endl;

	std::cout << "You added " << myAuto.refuel(500.0) << std::endl;

	std::cout << myAuto.toString() << std::endl;


	
	return 0;

}