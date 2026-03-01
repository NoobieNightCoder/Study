#include "Shapes.h"

#include <cmath>
#include <vector>

using namespace std;

namespace {
    class GeometryCalculator {
    public:
        static double twoFactor() {
            double factor = 1.0 + 1.0;
            return factor;
        }

        static double getPi() {
            double piValue = acos(-1.0);
            return piValue;
        }

        static double distance(const Point& first, const Point& second) {
            double deltaX = first.getX() - second.getX();
            double deltaY = first.getY() - second.getY();
            double distanceValue = sqrt(deltaX * deltaX + deltaY * deltaY);
            return distanceValue;
        }

        static double polygonPerimeter(const vector<Point>& vertices) {
            double perimeter = 0;
            size_t index = 0;

            while (index < vertices.size()) {
                size_t nextIndex = (index + 1) % vertices.size();
                perimeter += distance(vertices[index], vertices[nextIndex]);
                index += 1;
            }

            return perimeter;
        }
    };
}

// POINT //

Point::Point() : x(0), y(0) {}

Point::Point(double xValue, double yValue) : x(xValue), y(yValue) {}

double Point::getX() const {
    double result = x;
    return result;
}

double Point::getY() const {
    double result = y;
    return result;
}

// CIRCLE //

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

// RECTANGLE //

Rectangle::Rectangle(const string& shapeName, const vector<Point>& shapeVertices)
    : name(shapeName), vertices(shapeVertices) {}

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

// TRIANGLE //

Triangle::Triangle(const string& shapeName, const vector<Point>& shapeVertices)
    : name(shapeName), vertices(shapeVertices) {}

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
