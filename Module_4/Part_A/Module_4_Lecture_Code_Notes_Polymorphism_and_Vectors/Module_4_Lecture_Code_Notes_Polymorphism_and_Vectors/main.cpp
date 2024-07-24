#include <iostream>
#include <string>
#include "Employee.h"
#include <vector>
using namespace std;



int main() {

	vector<Employee*> employeeList;

	Employee James("James", "054-34-5432", "C02345");
	James.work();
	cout << James.name << endl;

	employeeList.push_back(new Employee("James", "054-34-5432", "C02345"));

	Secretary Terry("Terense", "054-66-5432", "C02845", 54);
	Terry.work();
	cout << Terry.name << endl;
	employeeList.push_back(new Secretary("Terense", "054-66-5432", "C02845", 54));

	LegalSecretary Susan("Susan", "194-34-5482", "C026345", 54);
	Susan.work();
	cout << Susan.name << endl;
	employeeList.push_back(new LegalSecretary("Susan", "194-34-5482", "C026345", 54));

	Programmer Katie("Katie", "164-24-5762", "C044345", "C++");
	Katie.work();
	cout << Katie.name << endl;
	employeeList.push_back(new Programmer("Katie", "164-24-5762", "C044345", "C++"));

	//Jacob McDaniels 6/14/2024
	GameDeveloper Adria("Adria", "418-39-2180", "C015348", care, caring);
	
	Adria.work();
	Adria.develop();
	
	cout << Adria.name << ", Do you care about making the game bug free and for the user to enjoy playing?" << endl;
	cin >> Adria.caring;
	
	if(Adria.getDoICare() == false)
	{
		cout << "Great job Adria! You are a great game developer!" << endl;
	};
	employeeList.push_back(new GameDeveloper("Adria", "418-39-2180", "C015348", care, caring));

	// Jacob McDaniels 6/14/2024
	SeniorGameDeveloper Austin("Austin", "316-31-4118", "C034078", care, caring, years);

	cout << Austin.name << ", How many years of experince in Game Development do you have?" << endl;
	cin >> Austin.years;

	Austin.lead();

	Austin.work();

	cout << Austin.name << ", Do you care about making the game bug free and for the user to enjoy playing?" << endl;
	cin >> Austin.caring;

	if(Austin.getDoICare() == false)
	{
		cout << "Great job Austin! You are a good leader for the team!" << endl;
	};

	employeeList.push_back(new SeniorGameDeveloper("Austin", "316-31-4118", "C034078", care, caring, years));
	// Kyle Ingersoll 6/14/2024

	Janitor John("John", "617-92-4120", "C012387", 2, false);

	John.work();

	cout << John.name << endl;

	employeeList.push_back(new Janitor("John", "617-92-4120", "C012387", 2, false));


	// Kyle Ingersoll 6/14/2024

	LeadJanitor Michael("Michael", "491-12-4130", "C012387", 6, true, 10);

	Michael.work();

	cout << Michael.name << endl;

	employeeList.push_back(new LeadJanitor("Michael", "491-12-4130", "C012387", 6, true, 10));

	// Kyle Ingersoll 6/24/2024
	Employee* pEmployee = &Katie;
	pEmployee->work();
	// pEmployee->hack();

	for (int i = 0; i < employeeList.size(); i++)
	{
		std::cout << employeeList[i].getName << std::endl;
		employeeList.work();
	}

	float x = 3.45;

	int y = x; // warning -  loss of precision may occur

	std::cout << y;

	// if we are done with employeeList

	// release the employees

	for (int i = (employeeList.size() - 1); i >= 0; i--)
	{
		delete employeeList[i];
		employeeList[i] = NULL;
		employeeList.pop_back();
	}
	
	return 0;


}