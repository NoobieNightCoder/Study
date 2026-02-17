#include <iostream>
#include <stdlib.h>
#include <vector>

#include "UI/menuFunctions.h"
#include "shapes.h"

using namespace std;

int main() {
    bool exitFlag = false;

    vector<Shapes> a;

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