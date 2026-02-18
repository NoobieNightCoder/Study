#include "shapes.h"
#include <cmath>

using namespace std;

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

double distance(const Point &a, const Point &b) {
    return sqrt(
        (a.getX() - b.getX()) * (a.getX() - b.getX()) +
        (a.getY() - b.getY()) * (a.getY() - b.getY())
    );
}

Shape::Shape(const string &name) : name(name) {}

string Shape::getName() const {
    return name;
}