#include "InputOutputUI.h"

#include <iostream>

using namespace std;

void printError(int errorMessageID) {
    cout << "Error " << errorMessageID << ": " << errorMessagesMenu[errorMessageID].description << endl;
}

void printMessage(int id) {
    cout << messagesMenu[id].description << endl;
}