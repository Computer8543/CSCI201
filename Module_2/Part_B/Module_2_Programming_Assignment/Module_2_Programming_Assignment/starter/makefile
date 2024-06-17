all: main character
main: character main.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp character -o main
character: character.cpp character.h
	g++ -pedantic-errors -g -c -fdiagnostics-color=always character.cpp -o character