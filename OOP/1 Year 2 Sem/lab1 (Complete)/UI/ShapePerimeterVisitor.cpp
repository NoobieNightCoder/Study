#include "ShapePerimeterVisitor.h"

#include <sstream>
#include <string>

#include "ShapeTextCatalog.h"

using namespace std;

void ShapePerimeterVisitor::visitCircle(const Circle& circle) {
    ostringstream text;
    text << circle.getName() << " (" << ShapeTextCatalog::getCircleLabel() << ")";
    text << ShapeTextCatalog::getSeparator() << ShapeTextCatalog::getPerimeterLabel() << circle.getPerimeter();
    line = text.str();
}

void ShapePerimeterVisitor::visitRectangle(const Rectangle& rectangle) {
    ostringstream text;
    text << rectangle.getName() << " (" << ShapeTextCatalog::getRectangleLabel() << ")";
    text << ShapeTextCatalog::getSeparator() << ShapeTextCatalog::getPerimeterLabel() << rectangle.getPerimeter();
    line = text.str();
}

void ShapePerimeterVisitor::visitTriangle(const Triangle& triangle) {
    ostringstream text;
    text << triangle.getName() << " (" << ShapeTextCatalog::getTriangleLabel() << ")";
    text << ShapeTextCatalog::getSeparator() << ShapeTextCatalog::getPerimeterLabel() << triangle.getPerimeter();
    line = text.str();
}

string ShapePerimeterVisitor::getLine() const {
    string result = line;
    return result;
}
