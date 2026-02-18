#include "circle.h"
#include "../shapes.h"
#include "../Visitor.h"

#include <string>
#include <cmath>

using namespace std;

const double PI = atan(1) * 4;

Circle::Circle(const string &name, const Point &center, double radius) : Shape(name), center(center), radius(radius) {}

double Circle::perimeter() const {
    return 2 * PI * radius;
}

void Circle::askPerimeter(ShapeVisitor &visitor) const {
    visitor.getPerimeter(*this);
}

void Circle::askParameters(ShapeVisitor &visitor) const {
    visitor.getParams(*this);
}

Point Circle::getCenter() const { return center; }
double Circle::getRadius() const { return radius; }