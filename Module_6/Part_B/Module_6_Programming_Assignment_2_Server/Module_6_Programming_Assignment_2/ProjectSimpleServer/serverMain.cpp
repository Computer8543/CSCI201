#include <iostream>
#include "PracticalSocket.h"
#include <cstdlib>
#include <map>
using namespace std;


const int portNum = 9999;
const int bufferSize = 1024;

int main() {

    try {

        // variables to hold the incoming/outgoing data and the size of data
        char dataBuffer[bufferSize];
        int msgSize;

        cout << "Starting Server!!!" << endl;

        TCPServerSocket serverSocket(portNum);

        while (true) {
            cout << "Waiting for connection!!!" << endl;
            TCPSocket* sock = serverSocket.accept();  // established connection with client
            cout << "Call Received" << endl;


            msgSize = sock->recv(dataBuffer, bufferSize);

            enum Topping { JALAPENO = 1, PEPPERONI, MUSHROOM};
            map<Topping, string> pizzaTopping = { {JALAPENO,"Jalapeno"},{PEPPERONI,"Pepperoni"},{MUSHROOM,"Mushroom"} };
            map<string, string> pizzaToppingMap = { {"1","Jalapeno"},{"2","Pepperoni"},{"3","Mushroom"}};

            Topping selected; 

            if (msgSize > 0) {
                cout << "Received " << dataBuffer << endl;


                int value = std::stoi(dataBuffer);
                selected = Topping(value);

                string stringToBeReturned = pizzaTopping[selected];
                
                strncpy_s(dataBuffer, stringToBeReturned.c_str(), bufferSize - 1);

             
                msgSize = pizzaTopping[selected].size() + 1;

                // TODO: determine what to reply
                // "12" "033/hjklhuyhjhjhj"

                // send reply

                sock->send(dataBuffer, msgSize);

            }
            else {
                cout << "message not received!!!" << endl;
            }

            delete sock;




        }

        serverSocket.close();

    }
    catch (SocketException& e) {
        cout << "Socket Error" << endl;
        cout << e.what() << endl;
    }


    return 0;
}