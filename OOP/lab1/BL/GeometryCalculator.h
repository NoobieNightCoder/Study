#pragma once
#include "Shapes.h"
#include <cmath>

class GeometryCalculator {
public:
    static double twoFactor();
    static double getPi();
    static double distance(const Point& first, const Point& second);
    static double polygonPerimeter(const std::vector<Point>& vertices);
};