#include <iostream>
#include <memory>
#include <vector>

#include "UI/menuFunctions.h"
#include "MainLogic/shapes.h"

typedef enum {
    CIRCLE      = 1,
    RECTANGLE   = 2,
    TRIANGLE    = 3
} ShapesID;

using namespace std;

class PrintVisitor : public ShapeVisitor {
private:
    int index = 1;

public:
    void visit(const Circle &c) override {
        cout << index++ << ". " << c.getName() << " (Circle)\t|\tPerimeter: " << c.perimeter() << endl;
    }

    void visit(const Rectangle &r) override {
        cout << index++ << ". " << r.getName() << " (Rectangle)\t|\tPerimeter: " << r.perimeter() << endl;
    }

    void visit(const Triangle &t) override {
        cout << index++ << ". " << t.getName() << " (Triangle)\t|\tPerimeter: " << t.perimeter() << endl;
    }
};

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
                cout << "Enter 2 opposite vertices (x y):" << endl;

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
                shape->accept(printer);
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