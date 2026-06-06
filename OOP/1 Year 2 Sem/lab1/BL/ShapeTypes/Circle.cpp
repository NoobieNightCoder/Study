#include "Circle.h"

using namespace std;

Circle::Circle(const string& shapeName, const Point& shapeCentre, double shapeRadius)
    : name(shapeName), centre(shapeCentre), radius(shapeRadius) {}

string Circle::getName() const {
    string result = name;
    return result;
}

double Circle::getPerimeter() const {
    double perimeter = GeometryCalculator::twoFactor() * GeometryCalculator::getPi() * radius;
    return perimeter;
}

void Circle::accept(ShapeVisitor& visitor) const {
    visitor.visitCircle(*this);
}

Point Circle::getCentre() const {
    Point result = centre;
    return result;
}

double Circle::getRadius() const {
    double result = radius;
    return result;
}