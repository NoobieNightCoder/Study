#include "shapes.h"
#include <cmath>

using namespace std;

const double PI = atan(1) * 4;



Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }





static double distance(const Point &a, const Point &b) {
    return sqrt(
        (a.getX() - b.getX()) * (a.getX() - b.getX()) +
        (a.getY() - b.getY()) * (a.getY() - b.getY())
    );
}





Shape::Shape(const string &name) : name(name) {}

string Shape::getName() const {
    return name;
}





Circle::Circle(const string &name, const Point &center, double radius) : Shape(name), center(center), radius(radius) {}

double Circle::perimeter() const {
    return 2 * PI * radius;
}

void Circle::accept(ShapeVisitor &visitor) const {
    visitor.visit(*this);
}

Point Circle::getCenter() const { return center; }
double Circle::getRadius() const { return radius; }





Rectangle::Rectangle(const string &name, const vector<Point> &vertices) : Shape(name), vertices(vertices) {}

double Rectangle::perimeter() const {
    double p = 0;
    for (size_t i = 0; i < vertices.size(); i++)
        p += distance(vertices[i], vertices[(i + 1) % vertices.size()]);
    return p;
}

void Rectangle::accept(ShapeVisitor &visitor) const {
    visitor.visit(*this);
}

const vector<Point> &Rectangle::getVertices() const {
    return vertices;
}





Triangle::Triangle(const string &name, const vector<Point> &vertices) : Shape(name), vertices(vertices) {}

double Triangle::perimeter() const {
    double p = 0;
    for (size_t i = 0; i < vertices.size(); i++)
        p += distance(vertices[i], vertices[(i + 1) % vertices.size()]);
    return p;
}

void Triangle::accept(ShapeVisitor &visitor) const {
    visitor.visit(*this);
}

const vector<Point> &Triangle::getVertices() const {
    return vertices;
}
