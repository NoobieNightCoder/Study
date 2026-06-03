#include "Polygon.h"

using namespace std;

Polygon::Polygon(const string& shapeName, const vector<Point>& shapeVertices) : name(shapeName), vertices(shapeVertices) {}

string Polygon::getName() const {
    string result = name;
    return result;
}

double Polygon::getPerimeter() const {
    double perimeter = GeometryCalculator::polygonPerimeter(vertices);
    return perimeter;
}

void Polygon::accept(ShapeVisitor& visitor) const {
    visitor.visitPolygon(*this);
}

vector<Point> Polygon::getVertices() const {
    vector<Point> result = vertices;
    return result;
}