#include "Triangle.h"

using namespace std;

Triangle::Triangle(const string& shapeName, const vector<Point>& shapeVertices) : name(shapeName), vertices(shapeVertices) {}

string Triangle::getName() const {
    string result = name;
    return result;
}

double Triangle::getPerimeter() const {
    double perimeter = GeometryCalculator::polygonPerimeter(vertices);
    return perimeter;
}

void Triangle::accept(ShapeVisitor& visitor) const {
    visitor.visitTriangle(*this);
}

vector<Point> Triangle::getVertices() const {
    vector<Point> result = vertices;
    return result;
}