// Module_4_Part_A_Lecture_Code_Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "game.h"

int main()
{
	int numPlayers;

	std::cout << "Enter number of players: ";
	std::cin >> numPlayers;
	std::cout << std::endl;

	Game game1(numPlayers);

	Game game2 = game1;

	Game game3(game1);

	game1.addPlayer();

	game2.addPlayer();

	game3.addPlayer();

	std::cout << "End of Game!!!" << std::endl;

	game1.printPlayers();
	game2.printPlayers();
	game3.printPlayers();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
