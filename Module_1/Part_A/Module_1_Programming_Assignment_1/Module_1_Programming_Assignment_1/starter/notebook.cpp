/* Program name: notebook.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 6/7/2024
*  Purpose: Store the method definitions for the notebook class
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream> // for the stringstream for the toString() method so it can output a formatted string
#include <stdexcept> // for invalid argument exception
#include <cmath> // for finding the positive difference between 0 and a negative number.
#include "notebook.h"


// Class functions are implemented here

// constructor method
notebook::notebook(double w, double h, int p, std::string pt, std::string f, std::string pc, std::string ct, std::string cd) {
	// define attributes through input parameters
	width = w;
	height = h;
	pages = p;
	paperType = pt;
	format = f;
	paperColor = pc;
	coverType = ct;
	coverDesign = cd;

}

// accessor methods
const double notebook::getHeight() {
	return height;
}
const double notebook::getWidth() {
	return width;
}
const int notebook::getPages() {
	return pages;
}
const std::string notebook::getCoverDesign() {
	return coverDesign;
}
const std::string notebook::getCoverType() {
	return coverType;
}
const std::string notebook::getFormat() {
	return format;
}
const std::string notebook::getPaperColor() {
	return paperColor;
}
const std::string notebook::getPaperType() {
	return paperType;
}
const std::string notebook::toString() {
	// define variables
	std::stringstream outputStream; // needed to output the formatted text as a single string so it can be returned

	// output the various notebook attributes on the console
	outputStream << "Here is your notebook:" << std::fixed << std::showpoint << std::endl;
	outputStream << "Dimensions: " << std::setprecision(6) << getWidth() << "x" << std::setprecision(6) << getHeight() << std::endl;
	outputStream << "Number of pages: " << std::setprecision(6) << getPages() << std::endl;
	outputStream << "Paper Type: " << std::setprecision(6) << getPaperType() << std::endl;
	outputStream << "Paper Color: " << std::setprecision(6) << getPaperColor() << std::endl;
	outputStream << "Page Format: " << std::setprecision(6) << getFormat() << std::endl;
	outputStream << "Cover Type: " << std::setprecision(6) << getCoverType() << std::endl;
	outputStream << "Cover Design: " << std::setprecision(6) << getCoverDesign() << std::endl;

	return outputStream.str(); // We return the stringstream as an string object
}

// mutator methods

void notebook::setCoverDesign(std::string cd) {
	coverDesign = cd;
}
void notebook::setCoverType(std::string ct) {
	coverType = ct;
}
void notebook::setFormat(std::string f) {
	format = f;
}
void notebook::setHeight(double h) {
	if (h > 0)
		height = h;
	else
		height = fdim(0.0, h); // find positive difference between 0 and h, i.e. convert negative number entered into positive number
}
void notebook::setPages(int p) {
	if (p > 0)
		pages = p;
	else
		pages = fdim(0.0, p); // find positive difference between 0 and p, i.e. convert negative number entered into positive number
}
void notebook::setPaperColor(std::string pc) {
	paperColor = pc;
}
void notebook::setPaperType(std::string pt) {
	paperType = pt;
}
void notebook::setWidth(double w) {
	if (w > 0)
		width = w;
	else
		width = fdim(0.0, w); // find positive difference between 0 and w, i.e. convert negative number entered into positive number
}