#include "Shapes.h"

#include <cmath>
#include <vector>

using namespace std;

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