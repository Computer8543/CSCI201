/* Program name: client.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 7/16/2024
*  Purpose: Create a client program to send a color enum in binary form and receives format string and the name of color from the server.
*/
#pragma warning(disable : 4996) // Using an unsafe version of strncpy so it would work in CodeGrade, so I will have to suppress warnings to get it to compile on my computer
#include <iostream>
#include "PracticalSocket.h"
#include <cstdlib>
#include <map>
#include <string>

// constant global variables
const in_port_t portNum = 9999;
const int bufferSize = 1024;
const char* serverIPAddress = "127.0.0.53"; // assuming a loopback address

// colors enum
enum color {SUNSET, CHERRY, PHANTOM, TITANIUM, GEAUX, LIGHTNING, FOREST, MIDNIGHT, PASSION, ROOT, STORM, OCEAN, GLACIAL};

// color enum to name of color string map
std::map<color, std::string> colorEnumToNameOfColorStringMap {
	{SUNSET, "Sunset Orange"}, {CHERRY, "Cherry Bomb"}, {PHANTOM, "Phantom Black"},
	{TITANIUM, "Titanium Silver"}, {GEAUX, "Geaux Gold"}, {LIGHTNING, "Lightning Yellow"},
	{FOREST, "Forest Green"}, {MIDNIGHT, "Midnight Blue"}, {PASSION, "Passion Purple"},
	{ROOT, "Root Beer"}, {STORM, "Storm Surge"}, {OCEAN, "Ocean's Rip"}, 
	{GLACIAL, "Glacial White"}
};
std::map<color, std::string>::iterator it; 

int main() {

	try {
		// initialize variables
		int enumMenuChoice;
		int i = 0;

		// display menu to the user and prompt them to make a choice
		std::cout << "Choose a color from the list below:" << std::endl;

		for (it = colorEnumToNameOfColorStringMap.begin(); it != colorEnumToNameOfColorStringMap.end(); it++) {
			std::cout << it->first << ". " << it->second << std::endl;
		}

		std::cin >> enumMenuChoice;
		std::cout << std::endl;

		// variables to hold the incoming/outgoing data and the size of data
		char dataBuffer[bufferSize];
		int msgSize;
		

		// front desk, someone listening
		TCPSocket socket(serverIPAddress, portNum);


		// TODO: determine what to send

		// convert decimal integer to string
		std::string enumString = std::to_string(enumMenuChoice);

		// get length of enumString
		int enumStringLength = enumString.length();
		msgSize = (enumStringLength + 1);
		// convert string to cstring
		const char* enumCharArray = enumString.c_str();

		// copy over enumCharArray to dataBuffer not safely
		std::strncpy(dataBuffer, enumCharArray, (bufferSize - 1));

		// send information
		socket.send(dataBuffer, msgSize);

		
		

		msgSize = socket.recv(dataBuffer, bufferSize);



		// if there is a message, output Recieved message
		if (msgSize > 0)
		{
			std::cout << "Server Response: " << dataBuffer << std::endl;

			// TODO: determine what to print
			// What else to do
		}
		else {
			std::cout << "Message not receieved!!!" << std::endl;
		}

		socket.close();
	}
	catch (SocketException& e) {
		std::cout << "Socket Error" << std::endl;
		std::cout << e.what() << std::endl;
	}
 
	// end program normally
	return 0;
}