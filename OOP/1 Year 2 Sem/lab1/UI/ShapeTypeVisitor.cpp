#include "ShapeTypeVisitor.h"

#include <sstream>
#include <string>
#include <vector>

#include "ShapeTextCatalog.h"

using namespace std;

void ShapeTypeVisitor::visitCircle(const Circle& circle) {
    ostringstream text;

    text << circle.getName() << " (" << ShapeTextCatalog::getCircleLabel() << ")";

    line = text.str();
}

void ShapeTypeVisitor::visitRectangle(const Rectangle& rectangle) {
    ostringstream text;
    text << rectangle.getName() << " (" << ShapeTextCatalog::getRectangleLabel() << ")";
    line = text.str();
}

void ShapeTypeVisitor::visitTriangle(const Triangle& triangle) {
    ostringstream text;
    text << triangle.getName() << " (" << ShapeTextCatalog::getTriangleLabel() << ")";
    line = text.str();
}

string ShapeTypeVisitor::getLine() const {
    string result = line;
    return result;
}
