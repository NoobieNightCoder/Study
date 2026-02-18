#include "menuFunctions.h"
#include "../MainLogic/shapes.h"
#include <stdlib.h>

using namespace std;

void waitForInput() {
    cin.get();
    cin.get();
}

void printMenu() {
    system("CLS");
    cout << "Lab Work #1" << endl << endl;
    
    for(Menu item : mainMenu)
        cout << item.id << " " << item.description << endl;
}

int addShapeMenu() {
    system("CLS");
    cout << "Which shape do you want to add?" << endl;
    for(Menu item : shapeAddMenu)
        cout << item.id << " " << item.description << endl;

    int result = itemInputMenu();

    return result;
}

int itemInputMenu() {
    int result = 0;

    cout << "Enter menu item: ";
    cin >> result;

    return result;
}

string nameInputMenu() {
    string result = "";

    cout << "Enter name: ";
    cin >> result;

    return result;
}

double radiusInputMenu() {
    double result = 0;

    cout << "Enter radius: ";
    cin >> result;

    return result;
}

vector<Point> rectangleVerticesInputMenu() {
    vector<Point> vertices(4);

    cout << "Enter 2 opposite vertices [x y]:" << endl;

    int counter = 1;
    for (auto &p : vertices) {
        if(counter % 2 == 0) p = Point(0, 0);
        else {
            double x, y;
            cin >> x >> y;
            p = Point(x, y);
        }
        counter++;
    }
    
    vertices[1] = Point(vertices[2].getX(), vertices[0].getY());
    vertices[3] = Point(vertices[0].getX(), vertices[2].getY());

    return vertices;
}