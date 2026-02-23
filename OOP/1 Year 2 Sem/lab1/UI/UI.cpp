#include "UI.h"
#include <iostream>
#include <vector>

#include "InputOutputUI.h"
#include "../BL/Shapes.h"
#include "../BL/FunctionsHandler.h"

using namespace std;

// BASIC MENU //

void printMenu() {
    printMessage(MESSAGE_LAB_NAME);
    for(Menu item : mainMenu)
        cout << item.id << " " << item.description << endl;
}
void printAddShapeMenu() {
    printMessage(MESSAGE_SHAPE_TO_ADD);
    for(Menu item : shapeAddMenu)
        cout << item.id << " " << item.description << endl;
}

void printParameters(const Shape& shape, int index) {
    cout << index << ". " << shape.getName() << " (" << shape.getTypeName() << ")";

    if (auto circle = dynamic_cast<const Circle*>(&shape)) {
        Point c = circle->getCentre();
        cout << "\t|\tRadius: " << circle->getRadius() << "\t|\tCentre: (" << c.getX() << ";" << c.getY() << ")";
    }
    else if (auto rect = dynamic_cast<const Rectangle*>(&shape)) {
        const auto& v = rect->getVertices();
        cout << "\t|\tVertices: ";
        for (const auto& p : v)
            cout << "(" << p.getX() << ";" << p.getY() << ") ";
    }
    else if (auto tri = dynamic_cast<const Triangle*>(&shape)) {
        const auto& v = tri->getVertices();
        cout << "\t|\tVertices: ";
        for (const auto& p : v)
            cout << "(" << p.getX() << ";" << p.getY() << ") ";
    }

    cout << endl;
}

void printPerimeter(const Shape &shape, int index) {
    cout << index << ". " << shape.getName() << " (" << shape.getTypeName() << ")" << "\t|\tPerimeter: " << shape.getPerimeter() << endl;
}



// MENU INPUTS //

int itemInputMenu() {
    int item = inputValue<int>(INPUT_ITEM);
    return item;
}

int idInputMenu() {
    int id = inputValue<int>(INPUT_SHAPE_ID);
    return id;
}

string nameInputMenu(int* errorCode) {
    string result = inputValue<string>(INPUT_NAME);
    if(result.empty() || isBlank(result)) *errorCode = ERROR_BAD_NAME;
    return result;
}

double radiusInputMenu(int* errorCode) {
    double result = inputValue<double>(INPUT_RADIUS);
    if(result <= 0) *errorCode = ERROR_BAD_RADIUS;
    return result;
}

double perimeterInputMenu(int* errorCode) {
    double result = inputValue<double>(INPUT_PERIM_THRESHOLD);
    if(result <= 0) *errorCode = ERROR_BAD_PERIM_THRESHOLD;
    return result;
}

Point centreInputMenu() {
    double x = inputValue<double>(INPUT_CENTRE_X);
    double y = inputValue<double>(INPUT_CENTRE_Y);

    Point result(x, y);
    return result;
}

vector<Point> rectangleVerticesInputMenu() {
    vector<Point> vertices;

    double x1 = inputValue<double>(INPUT_RECT_VERTS_X1);
    double y1 = inputValue<double>(INPUT_RECT_VERTS_Y1);
    double x2 = inputValue<double>(INPUT_RECT_VERTS_X2);
    double y2 = inputValue<double>(INPUT_RECT_VERTS_Y2);

    vertices.emplace_back(x1, y1);
    vertices.emplace_back(x2, y1);
    vertices.emplace_back(x2, y2);
    vertices.emplace_back(x1, y2);

    return vertices;
}

vector<Point> triangleVerticesInputMenu() {
    vector<Point> vertices;

    for(int inputMessageID = INPUT_TRI_VERTS_X1; inputMessageID <= INPUT_TRI_VERTS_Y3; inputMessageID++) {
        double x = inputValue<double>(inputMessageID++);
        double y = inputValue<double>(inputMessageID);
        vertices.emplace_back(x, y);
    }

    return vertices;
}