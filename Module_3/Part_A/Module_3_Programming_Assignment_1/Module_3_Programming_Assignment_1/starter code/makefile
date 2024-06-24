CXX = g++
CXXFLAGS = -pedantic-errors -fdiagnostics-color=always -g

all: main

main: main.o candy.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp candy.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

candy.o: candy.cpp candy.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main *.o