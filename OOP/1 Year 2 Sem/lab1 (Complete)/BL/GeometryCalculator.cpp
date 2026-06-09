#include "GeometryCalculator.h"

using namespace std;

double GeometryCalculator::twoFactor() {
    double factor = 1.0 + 1.0;
    return factor;
}

double GeometryCalculator::getPi() {
    double piValue = acos(-1.0);
    return piValue;
}

double GeometryCalculator::distance(const Point& first, const Point& second) {
    double deltaX = first.getX() - second.getX();
    double deltaY = first.getY() - second.getY();
    double distanceValue = sqrt(deltaX * deltaX + deltaY * deltaY);
    return distanceValue;
}

double GeometryCalculator::polygonPerimeter(const vector<Point>& vertices) {
    double perimeter = 0;
    size_t index = 0;

    while (index < vertices.size()) {
        size_t nextIndex = (index + 1) % vertices.size();
        perimeter += distance(vertices[index], vertices[nextIndex]);
        index += 1;
    }

    return perimeter;
}