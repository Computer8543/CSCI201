#include <iostream>
#include "PracticalSocket.h"
#include "windows.h"
#include <cstdlib>
using namespace std;

const in_port_t portNum = 9999;
const int bufferSize = 1024;
const char* server = "127.0.0.1"; // assuming a loopback address

int main() {

    try {
        string messageToSend;
        cout << "Enter Message To Send: ";
        getline(cin,messageToSend);
        // variables to hold the incoming/outgoing data and the size of data
        //char dataBuffer[bufferSize] = "Testing 123";
        //int msgSize = 12;
        char dataBuffer[bufferSize];
        strncpy_s(dataBuffer, messageToSend.c_str(), bufferSize-1);
        int msgSize = messageToSend.size()+1;


        TCPSocket socket(server, portNum);

        //TODO - Determine What To SEND



        socket.send(dataBuffer, msgSize);


        msgSize = socket.recv(dataBuffer, bufferSize);
        if (msgSize > 0) {
            cout << "Received " << dataBuffer << endl;

            // TODO: determine what print
            // What else to do


        }
        else {
            cout << "message not received!!!" << endl;
        }

        socket.close();

    }
    catch (SocketException& e) {
        cout << "Socket Error" << endl;
        cout << e.what() << endl;
    }


    return 0;
}