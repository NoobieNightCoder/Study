#include "rectangle.h"
#include "../shapes.h"
#include "../Visitor.h"

#include <string>
#include <vector>

using namespace std;

Rectangle::Rectangle(const string &name, const vector<Point> &vertices) : Shape(name), vertices(vertices) {}

double Rectangle::perimeter() const {
    double p = 0;
    for (size_t i = 0; i < vertices.size(); i++)
        p += distance(vertices[i], vertices[(i + 1) % vertices.size()]);
    return p;
}

void Rectangle::askPerimeter(ShapeVisitor &visitor) const {
    visitor.getPerimeter(*this);
}

void Rectangle::askParameters(ShapeVisitor &visitor) const {
    visitor.getParams(*this);
}

const vector<Point> &Rectangle::getVertices() const {
    return vertices;
}