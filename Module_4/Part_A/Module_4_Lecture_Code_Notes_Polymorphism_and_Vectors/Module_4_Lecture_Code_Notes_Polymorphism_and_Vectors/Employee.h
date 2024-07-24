#pragma once
// Jacob McDaniels 6/14/2024
// if looking to do Lecture assignmnet add prototypes in this file and implementation in Employee.cpp
#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
  string name;
protected:
  string employeeNumber;
  string ssn;
public:
  Employee(string name, string ssn, string employeeNumber);
  ~Employee();
  string getName();
  string getSSN();
  string getEmployeeNumber();
  void virtual work() = 0;
  virtual double getPaid() = 0;
};

class Secretary : public Employee {
private:
  int wordsPerMinute;
public:
  Secretary(string name, string ssn, string employeeNumber, int wpm) : Employee(name, ssn, employeeNumber);
  ~Secretary();
  void type();
  virtual void work();
  double getPaid();
};

class LegalSecretary : public Secretary {
public:
  LegalSecretary(string name, string ssn, string employeeNumber, int wpm) : Secretary(name, ssn, employeeNumber,wpm);
  ~LegalSecretary();
  void fileBriefs();
  void takeDictation();
  virtual void work();
};
class Programmer : public Employee {
protected:
  string programmingLanguages;
public:
  Programmer(string name, string ssn, string employeeNumber, string languages) : Employee(name, ssn, employeeNumber);
  ~Programmer();
  void develop();
  void hack();
  virtual void work();
  double getPaid();
};
// Jacob McDaniels 6/14/2024
class GameDeveloper : public Employee {
protected: 
  bool doICare;
public:
  GameDeveloper(string name, string ssn, string employeeNumber, bool Care) : Employee(name, ssn, employeeNumber);
  ~GameDeveloper();
  char getDoICare();
  void develop();
  virtual void work();
};
// Jacob McDaniels 6/14/2024
class SeniorGameDeveloper : public GameDeveloper {
protected:
  int experienceInYears;
public:
  SeniorGameDeveloper(string name, string ssn, string employeeNumber, bool Care, int years) : GameDeveloper(name, ssn, employeeNumber, Care);
  ~SeniorGameDeveloper();
  int getExperinceInYears();
  void lead();
  void virtual work();
};