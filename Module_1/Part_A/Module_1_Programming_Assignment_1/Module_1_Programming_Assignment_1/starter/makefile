all: notebook main
main: notebook main.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp notebook -o main
notebook: notebook.h notebook.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always notebook.cpp -o notebook
