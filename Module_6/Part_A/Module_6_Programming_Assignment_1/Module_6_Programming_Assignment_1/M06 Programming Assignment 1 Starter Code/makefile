all: date main.cpp dateExcept
	g++ -pedantic-errors -g main.cpp date dateExcept -o main
date: date.h date.cpp
	g++ -pedantic-errors -g -c date.cpp -o date
dateExcept: dateExcept.h dateExcept.cpp	
	g++ -pedantic-errors -g -c dateExcept.cpp -o dateExcept