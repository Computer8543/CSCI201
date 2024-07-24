#pragma once
#include <iostream>
#include <string>

class Game {
private:
	static int numGames;
	std::string* players;
	int* numPlayers;
public:
	Game(int numPlayers) {
		players = new std::string[numPlayers];
		this->numPlayers = new int;
		*(this->numPlayers) = numPlayers;
		for (int i = 0; i < numPlayers; i++)
		{
			std::cout << "Enter Player Name: ";
			std::cin >> players[i];
			std::cout << std::endl;
		}
		numGames++;
	}
	Game(const Game& orig) {
		numPlayers = new int;
		*numPlayers = orig.getNumPlayers();
		players = new std::string[*numPlayers];
		for (int i = 0; i < *numPlayers; i++)
		{
			players[i] = orig.players[i];
		}
		numGames++;
	}
	~Game() {
		delete numPlayers;
		numPlayers = NULL;
		delete[] players;
		players = NULL;
		numGames--;
	}
	int getNumPlayers() {
		return *numPlayers;
	}
	void addPlayer() {
		// to change the size of an array - need to create a new array
		// - copy the contents from the old to the new
		// add to the new array
		std::string* newNames = new std::string[(*numPlayers + 1)];
		for (int i = 0; i < *numPlayers; i++)
		{
			newNames[i] = players[i];
		}
		*numPlayers += 1;
		std::cout << "Enter new player name: ";
		std::cin >> players[(*numPlayers - 1)];

		delete[] players;
		players = newNames;
		
	}
	void printPlayers() {
		for (int i = 0; i < *numPlayers; i++)
		{
			std::cout << players[i] << std::endl;
		}
	}
};

int Game::numGames = 0;
