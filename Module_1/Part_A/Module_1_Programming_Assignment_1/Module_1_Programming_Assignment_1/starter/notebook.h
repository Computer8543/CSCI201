/* Program name: notebook.h
*  Author: Kyle Ingersoll
*  Date last updated: 6/7/2024
*  Purpose: Store the private attributes and public method prototypes for the notebook class
*/
#pragma once 
#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept> // for invalid argument exception
#include <sstream> // for the stringstream for the toString() method so it can output a formatted string
#include <cmath> // for finding the positive difference between 0 and a negative number.

// class is defined here 
// see the puml(plant uml) file or the .svg(image) for the class diagram that describes the class you need to create.

class notebook {
private:
	// attributes made private below
	double height;
	double width;
	int pages;
	std::string coverDesign;
	std::string coverType;
	std::string format;
	std::string paperColor;
	std::string paperType;

public:
	// methods made public to interface with the private attributes above
	
	// constructor method
	notebook(double w, double h, int p, std::string pt, std::string f, std::string pc, std::string ct, std::string cd);

	// accessor methods
	const double getHeight();
	const double getWidth();
	const int getPages();
	const std::string getCoverDesign();
	const std::string getCoverType();
	const std::string getFormat();
	const std::string getPaperColor();
	const std::string getPaperType();
	const std::string toString();

	// mutator methods

	void setCoverDesign(std::string cd);
	void setCoverType(std::string ct);
	void setFormat(std::string f);
	void setHeight(double h);
	void setPages(int p);
	void setPaperColor(std::string pc);
	void setPaperType(std::string pt);
	void setWidth(double w);
};

#endif