#include <iostream>
#include <stdlib.h>

#include "UI/menuFunctions.h"

using namespace std;

int main() {
    bool exitFlag = false;

    while(!exitFlag) {
        printMenu();
        int choise = inputMenu();
        if(choise == 1)
            addShapeMenu();
        else if (choise == 8)
            exitFlag = true;
        else {
            cout << "Error: The entered item does not exist" << endl;
            waitForInput();
        }
    }

    return 0;
}