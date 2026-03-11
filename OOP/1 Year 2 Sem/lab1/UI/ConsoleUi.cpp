#include "ConsoleUi.h"

#include <string>
#include <vector>

#include "ShapeParametersVisitor.h"
#include "ShapePerimeterVisitor.h"

using namespace std;

ConsoleUi::ConsoleUi(IInputOutputUI& inputOutput) : io(inputOutput) {}

int ConsoleUi::noError() const {
    int value = io.noError();
    return value;
}

void ConsoleUi::printMainMenu() const {
    io.printMainMenu();
}

void ConsoleUi::printAddShapeMenu() const {
    io.printShapeMenu();
}

void ConsoleUi::printMessage(UiMessageId messageId) const {
    io.printMessage(messageId);
}

void ConsoleUi::printMessage(UiMessageId messageId, double value) const {
    io.printMessage(messageId, value);
}

void ConsoleUi::printError(UiErrorId errorId) const {
    io.printError(errorId);
}

void ConsoleUi::printShapeParameters(const Shape& shape, int index) const {
    ShapeParametersVisitor visitor;
    shape.accept(visitor);
    io.printShapeLine(index, visitor.getLine());
}

void ConsoleUi::printShapePerimeter(const Shape& shape, int index) const {
    ShapePerimeterVisitor visitor;
    shape.accept(visitor);
    io.printShapeLine(index, visitor.getLine());
}

int ConsoleUi::readMenuItem() const {
    int item = io.readMenuItem();
    return item;
}

int ConsoleUi::readShapeId() const {
    int shapeId = io.readShapeId();
    return shapeId;
}

string ConsoleUi::readName(int& errorCode) const {
    string name = io.readName(errorCode);
    return name;
}

double ConsoleUi::readRadius(int& errorCode) const {
    double radius = io.readRadius(errorCode);
    return radius;
}

double ConsoleUi::readPerimeterThreshold(int& errorCode) const {
    double threshold = io.readPerimeterThreshold(errorCode);
    return threshold;
}

Point ConsoleUi::readCentre() const {
    Point centre = io.readCentre();
    return centre;
}

vector<Point> ConsoleUi::readRectangleVertices() const {
    vector<Point> vertices = io.readRectangleVertices();
    return vertices;
}

vector<Point> ConsoleUi::readTriangleVertices() const {
    vector<Point> vertices = io.readTriangleVertices();
    return vertices;
}
