#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(const string& shapeName, const vector<Point>& shapeVertices) : name(shapeName), vertices(shapeVertices) {}

string Rectangle::getName() const {
    string result = name;
    return result;
}

double Rectangle::getPerimeter() const {
    double perimeter = GeometryCalculator::polygonPerimeter(vertices);
    return perimeter;
}

void Rectangle::accept(ShapeVisitor& visitor) const {
    visitor.visitRectangle(*this);
}

vector<Point> Rectangle::getVertices() const {
    vector<Point> result = vertices;
    return result;
}