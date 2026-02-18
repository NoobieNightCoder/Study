#include <iostream>
#include <memory>
#include <vector>

#include "UI/menuFunctions.h"
#include "MainLogic/shapes.h"
#include "MainLogic/Visitor.h"

#include "MainLogic/ShapesClasses/circle.h"
#include "MainLogic/ShapesClasses/rectangle.h"
#include "MainLogic/ShapesClasses/triangle.h"

using namespace std;

int main() {
    vector<unique_ptr<Shape>> shapesList;
    bool exitFlag = false;

    while(!exitFlag) {
        printMenu();
        int choise = itemInputMenu();
        if(choise == MENU_ADD_SHAPE) {
            int shapeId = addShapeMenu();

            if(shapeId == CIRCLE) {
                string name;
                double x, y, r;

                cout << "Enter shape name: ";
                cin >> name;
                cout << "Center (x y): ";
                cin >> x >> y;
                cout << "Radius: ";
                cin >> r;

                shapesList.push_back(make_unique<Circle>(name, Point(x, y), r));

                cout << "Circle was added!" << endl;
                waitForInput();
            } else if (shapeId == RECTANGLE) {
                string name;
                vector<Point> vertices(4);

                cout << "Enter shape name: ";
                cin >> name;

                shapesList.push_back(make_unique<Rectangle>(name, vertices));

                cout << "Rectangle was added!" << endl;
                waitForInput();

            } else if (shapeId == TRIANGLE) {
                string name;
                vector<Point> vertices(3);

                cout << "Enter shape name: ";
                cin >> name;
                cout << "Enter 3 vertices (x y):\n";
                for (auto &p : vertices) {
                    double x, y;
                    cin >> x >> y;
                    p = Point(x, y);
                }

                shapesList.push_back(make_unique<Triangle>(name, vertices));

                cout << "Triangle was added!" << endl;
                waitForInput();
            }
        } else if (choise == MENU_PRINT_LIST_PERIM) {
            PrintVisitor printer;
            for(const auto &shape : shapesList)
                shape->askPerimeter(printer);
            waitForInput();
        } else if (choise == MENU_PRINT_LIST_PARAM) {
            PrintVisitor printer;
            for(const auto &shape : shapesList)
                shape->askParameters(printer);
            waitForInput();
        }

        else if (choise == MENU_EXIT_PROGRAMM)
            exitFlag = true;
        else {
            cout << "Error: The entered item does not exist" << endl;
            waitForInput();
        }
    }

    return 0;
}