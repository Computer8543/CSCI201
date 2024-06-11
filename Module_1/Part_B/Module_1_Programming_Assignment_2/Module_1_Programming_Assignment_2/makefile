all: burger main 
main: main.cpp burger
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp burger -o main
burger: burger.h burger.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g -c burger.cpp -o burger
