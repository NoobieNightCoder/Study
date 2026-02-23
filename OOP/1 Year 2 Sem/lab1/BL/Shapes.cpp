#include "Shapes.h"
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// BASIC CONSTS | FUNCTIONS //

const double PI = atan(1) * 4;

static double distance(const Point &a, const Point &b) {
    return sqrt(
        (a.getX() - b.getX()) * (a.getX() - b.getX()) +
        (a.getY() - b.getY()) * (a.getY() - b.getY())
    );
}

static double calcRectAndTriPerim(vector<Point> vertices) {
    double p = 0;
    for (size_t i = 0; i < vertices.size(); i++)
        p += distance(vertices[i], vertices[(i + 1) % vertices.size()]);
    return p;
}

// POINT CLASS FOR COORDS //

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

// CIRCLE //

Circle::Circle(string n, Point c, double r) : name(n), centre(c), radius(r) {}

string Circle::getName()      const { return name;            }
string Circle::getTypeName()  const { return "Circle";        }

Point Circle::getCentre()     const { return centre;          }

double Circle::getPerimeter() const { return 2 * PI * radius; }
double Circle::getRadius()    const { return radius;          }

// RECTANGLE //

Rectangle::Rectangle(string n, vector<Point> v) : name(n), vertices(v) {}

string Rectangle::getName()            const { return name;        }
string Rectangle::getTypeName()        const { return "Rectangle"; }

vector<Point> Rectangle::getVertices() const { return vertices;    }

double Rectangle::getPerimeter()       const { return calcRectAndTriPerim(vertices); }

// TRIANGLE //

Triangle::Triangle(string n, vector<Point> v) : name(n), vertices(v) {}

string Triangle::getName()            const { return name;       }
string Triangle::getTypeName()        const { return "Triangle"; }

vector<Point> Triangle::getVertices() const { return vertices;   }

double Triangle::getPerimeter()       const { return calcRectAndTriPerim(vertices); }