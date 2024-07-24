//Jacob McDaniels 6/14/2024
// lecture assignment class implementation here
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;


Employee::~Employee() {
    cout << "Terminating Employee " << name << endl;
  }
  string Employee::getName() {
    return name;
  }
  string Employee::getSSN() {
    return ssn;
  }
  string Employee::getEmployeeNumber() {
    return employeeNumber;
  }


  Secretary::Secretary(string name, string ssn, string employeeNumber, int wpm) : Employee::Employee(name, ssn, employeeNumber) {
    wordsPerMinute = wpm;
    cout << "promoting " << name << " to secretary" << endl;
  }
  Secretary::~Secretary() {
    cout << "Demoting" << name << " to Employee!!!!" << endl;
  }
  void Secretary::type() {
    cout << "Type Type Type" << endl;
  }
  void Secretary::work() {
    cout << "Type Type Gossip Gossip Gossip!!!" << endl;
  }
  double Secretary::getPaid() {
      double hoursWorked = 40.00;
      double hourlyRate = 23.00;
      return (hoursWorked * hourlyRate);
  }


  LegalSecretary::LegalSecretary(string name, string ssn, string employeeNumber, int wpm) : Secretary::Secretary(name, ssn, employeeNumber,wpm) {
    cout << "promoting " << name << " to legal secretary" << endl;
  }
  LegalSecretary::~LegalSecretary() {
    cout << "Demoting" << name << " to Secretary!!!!" << endl;
  }
  void LegalSecretary::fileBriefs() {
    cout << "Filing Filing Filing Briefs at the courthouse and online" << endl;
  }
  void LegalSecretary::takeDictation() {
    cout << "Taking Dictation!!!" << endl;
  }
  void LegalSecretary::work() {  //polymorphism
    cout << "Take Dicatation, Type and File Breifs and Motions!!!" << endl;
  }



  Programmer::Programmer(string name, string ssn, string employeeNumber, string languages) : Employee::Employee(name, ssn, employeeNumber) {
    programmingLanguages = languages;
    cout << "Promoting " << name << " to Programmer!!! " << endl;
  }
  Programmer::Programmer() {
    cout << "Demoting " << name << " to Employee!!!" << endl;
  }
  void Programmer::develop() {
    cout << "Agile!! Web!! Prototying!!! WaterFall!!" << endl;
  }
  void Programmer::hack() {
    cout << "Hack Hack Hack!!!" << endl;
  }
  void Programmer::work() {
    cout << "Code Code Code Test Test Debug Debug Debug Test Debug ARghhh!!!!" << endl;

  }
  double Programmer::getPaid() {
      double salary = 50.00;
      return (salary / 52.2);
  }

// Jacob McDaniels 6/14/2024

  GameDeveloper::GameDeveloper(string name, string ssn, string employeeNumber, bool care, string caring) : Employee::Employee(name, ssn, employeeNumber) {
    care = doICare;
    caring = careStr;
    cout << "Promoting " << name << "to Game Developer!... :)" << endl;
  }
  GameDeveloper::~GameDeveloper() {
    if (doICare == true)
    {
      cout << "Demoting " << name << "to Employee!...Go clean the bathrooms! :(" << endl;
    }
  }
  bool GameDeveloper::getDoICare() {
    return !(careStr == "Yes");
  }
  void GameDeveloper::develop() {
    cout << "Developing the game...tired" << endl;
  }
  void GameDeveloper::work() {
    cout << "code, code, code, debug, debug, I need a break" << endl;
  }

// Jacob McDaniels 6/14/2024

  SeniorGameDeveloper::SeniorGameDeveloper(string name, string ssn, string employeeNumber, bool care, string caring, int years) : GameDeveloper::GameDeveloper(name, ssn, employeeNumber, care, caring) {
    experienceInYears = years;
    cout << "Promoting " << name << "to Senior Game Developer!... :)" << endl;
  }
  SeniorGameDeveloper::~SeniorGameDeveloper() {
    if (doICare == true) {
      cout << "Demoting " << name << "to Game Developer!...Go finish the game yourself" << endl;
    }
  }
  int SeniorGameDeveloper::getExperienceInYears() {
    return experienceInYears;
  }
  bool SeniorGameDeveloper::getDoICare() {
    return !(careCh == "Yes");
  }
  void SeniorGameDeveloper::lead() {
    cout << "This is what, why, how, and when we are going to develop this game." << endl;
  }
  void SeniorGameDeveloper::work() {
    cout << "email, email, email, -developer asks question-...but I don't care" << endl;
  }
