/* Program name: server.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 7/16/2024
*  Purpose: Create a server program to receive a color enum in binary form and sends a format string and the name of color back to the client.
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
enum color { SUNSET, CHERRY, PHANTOM, TITANIUM, GEAUX, LIGHTNING, FOREST, MIDNIGHT, PASSION, ROOT, STORM, OCEAN, GLACIAL };

// color enum to name of color string map
std::map<color, std::string> colorEnumToNameOfColorStringMap{
	{SUNSET, "Sunset Orange"}, {CHERRY, "Cherry Bomb"}, {PHANTOM, "Phantom Black"},
	{TITANIUM, "Titanium Silver"}, {GEAUX, "Geaux Gold"}, {LIGHTNING, "Lightning Yellow"},
	{FOREST, "Forest Green"}, {MIDNIGHT, "Midnight Blue"}, {PASSION, "Passion Purple"},
	{ROOT, "Root Beer"}, {STORM, "Storm Surge"}, {OCEAN, "Ocean's Rip"},
	{GLACIAL, "Glacial White"}
};

// iterator for both maps
std::map<color, std::string>::iterator it;

// color enum to format string map
std::map<color, std::string> colorEnumToFormatStringMap{ 
	{SUNSET, "\033[1m\033[38;5;166m"}, {CHERRY, " \033[1m\033[38;5;160m"}, {PHANTOM, "\033[1m\033[38;5;0m\033[48;5;15m"},
	{TITANIUM, "\033[1m\033[38;5;249m"}, {GEAUX, "\033[1m\033[38;5;179m"}, {LIGHTNING, "\033[1m\033[38;5;11m"},
	{FOREST, "\033[1m\033[38;5;2m"}, {MIDNIGHT, "\033[1m\033[38;5;17m\033[48;5;15m"}, {PASSION, "\033[1m\033[38;5;5m"},
	{ROOT, "\033[1m\033[38;5;94m"}, {STORM, "\033[1m\033[38;5;242m"}, {OCEAN, "\033[1m\033[38;5;27m"},
	{GLACIAL, "\033[1m\033[38;5;15m"}

};


int main() {
	
	try {

		// variables to hold the incoming/outgoing data and the size of data
		char dataBuffer[bufferSize];
		int msgSize;


		

		// front desk, someone listening
		TCPServerSocket serverSocket(portNum);

		// you create the TCPServerSocket first, then make the SocketAddress and bind it to the TCPServerSocket
		SocketAddress address = SocketAddress(serverIPAddress, portNum);

		// bind serverSocket to address
		serverSocket.bind(address);
		

		while (true) {
			// someone answers
			TCPSocket* sock = serverSocket.accept(); // established connection with the client

			

			// load the data into dataBuffer up to bufferSize to get message size
			msgSize = sock->recv(dataBuffer, bufferSize);

			// if there is a message, output Recieved message
			if (msgSize > 0)
			{
				// convert dataBuffer message into int
				int integerValue = std::stoi(dataBuffer);

				// convert cstring back into enum
				color colorEnum = static_cast<color>(integerValue);

				

				// output value you recieved
				std::cout << "Request Recieved " << std::endl;
				std::cout << "receiving: " << colorEnum << std::endl;

				// TODO: determine what to reply
				
				// if binaryLong is less than 0 or greater than 12, set dataBuffer to spell out 'Error'. 
				if (colorEnum < 0 || colorEnum > 12)
				{
					std::string errorString = "Error";
					int errorStringLength = errorString.length();
					msgSize = (errorStringLength + 1);
					
					// not the safe version of strncpy, used to get it to work on CodeGrade
					std::strncpy(dataBuffer, errorString.c_str(), (bufferSize - 1));
				}
				else {
					
					int i = 0;

					// convert enumValue into string and then cstring
					std::string formatAndNameOfColorString = colorEnumToFormatStringMap[colorEnum] + colorEnumToNameOfColorStringMap[colorEnum];
					const char* formatAndNameOfColorCString = formatAndNameOfColorString.c_str();
					int formatAndNameOfColorCStringLength = formatAndNameOfColorString.length();
					msgSize = (formatAndNameOfColorCStringLength + 1);

					// copy the formatCString into dataBuffer unsafely
					std::strncpy(dataBuffer, formatAndNameOfColorCString, (bufferSize - 1));
					
				}
				// send reply
				sock->send(dataBuffer, msgSize);
			}
			else {
				std::cout << "Message not receieved!!!" << std::endl;
			}

			// server closes connection
			delete sock;
			sock = NULL;

		}

		serverSocket.close();
	}
	catch (SocketException& e) {
		std::cout << "Socket Error" << std::endl;
		std::cout << e.what() << std::endl;
	}

	// end program normally
	return 0;
}
