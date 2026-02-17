#include "menuFunctions.h"
#include <stdlib.h>

using namespace std;

void waitForInput() {
    cin.get();
    cin.get();
}

int itemInputMenu() {
    int result = 0;

    cout << "Enter menu item: ";
    cin >> result;

    return result;
}

void printMenu() {
    system("CLS");
    cout << "Lab Work #1" << endl << endl;
    
    for(Menu item : menuList)
        cout << item.id << " " << item.description << endl;
}

int addShapeMenu() {
    system("CLS");
    cout << "Which shape do you want to add?" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Triangle" << endl;

    int result = itemInputMenu();

    return result;
}