#include "ShapeTextCatalog.h"

#include <string>

using namespace std;

namespace {
const string circleLabel    = "Circle";
const string rectangleLabel = "Rectangle";
const string triangleLabel  = "Triangle";
const string radiusLabel    = "Radius: ";
const string centerLabel    = "Center: ";
const string verticesLabel  = "Vertices: ";
const string perimeterLabel = "Perimeter: ";
const string separator      = " | ";
}

const string& ShapeTextCatalog::getCircleLabel() {
    const string& result = circleLabel;
    return result;
}

const string& ShapeTextCatalog::getRectangleLabel() {
    const string& result = rectangleLabel;
    return result;
}

const string& ShapeTextCatalog::getTriangleLabel() {
    const string& result = triangleLabel;
    return result;
}

const string& ShapeTextCatalog::getRadiusLabel() {
    const string& result = radiusLabel;
    return result;
}

const string& ShapeTextCatalog::getCenterLabel() {
    const string& result = centerLabel;
    return result;
}

const string& ShapeTextCatalog::getVerticesLabel() {
    const string& result = verticesLabel;
    return result;
}

const string& ShapeTextCatalog::getPerimeterLabel() {
    const string& result = perimeterLabel;
    return result;
}

const string& ShapeTextCatalog::getSeparator() {
    const string& result = separator;
    return result;
}
