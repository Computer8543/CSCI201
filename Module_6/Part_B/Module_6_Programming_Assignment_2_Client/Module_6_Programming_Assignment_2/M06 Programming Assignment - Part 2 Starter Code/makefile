all: client server
server: PracticalSocket.o server.cpp
	g++ -pedantic-errors -g server.cpp PracticalSocket.o -o server
client: PracticalSocket.o client.cpp
	g++ -pedantic-errors -g client.cpp PracticalSocket.o -o client
PracticalSocket.o: PracticalSocket.cpp PracticalSocket.h
	g++ -g PracticalSocket.cpp -o PracticalSocket.o -c
clean:
	rm PracticalSocket.o
	rm a.out