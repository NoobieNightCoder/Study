#include "ShapeParametersVisitor.h"

#include <sstream>
#include <string>
#include <vector>

#include "ShapeTextCatalog.h"

using namespace std;

string ShapeParametersVisitor::verticesToText(const vector<Point>& vertices) const {
    ostringstream text;
    size_t index = 0;

    while (index < vertices.size()) {
        text << "(" << vertices[index].getX() << ";" << vertices[index].getY() << ")";
        bool hasNext = (index + 1) < vertices.size();
        if (hasNext) {
            text << " ";
        }
        index += 1;
    }

    string result = text.str();
    return result;
}

void ShapeParametersVisitor::visitCircle(const Circle& circle) {
    Point center = circle.getCentre();
    ostringstream text;

    text << circle.getName() << " (" << ShapeTextCatalog::getCircleLabel() << ")";
    text << ShapeTextCatalog::getSeparator() << ShapeTextCatalog::getRadiusLabel() << circle.getRadius();
    text << ShapeTextCatalog::getSeparator() << ShapeTextCatalog::getCenterLabel();
    text << "(" << center.getX() << ";" << center.getY() << ")";
    line = text.str();
}

void ShapeParametersVisitor::visitRectangle(const Rectangle& rectangle) {
    ostringstream text;
    text << rectangle.getName() << " (" << ShapeTextCatalog::getRectangleLabel() << ")";
    text << ShapeTextCatalog::getSeparator() << ShapeTextCatalog::getVerticesLabel();
    text << verticesToText(rectangle.getVertices());
    line = text.str();
}

void ShapeParametersVisitor::visitTriangle(const Triangle& triangle) {
    ostringstream text;
    text << triangle.getName() << " (" << ShapeTextCatalog::getTriangleLabel() << ")";
    text << ShapeTextCatalog::getSeparator() << ShapeTextCatalog::getVerticesLabel();
    text << verticesToText(triangle.getVertices());
    line = text.str();
}

string ShapeParametersVisitor::getLine() const {
    string result = line;
    return result;
}
