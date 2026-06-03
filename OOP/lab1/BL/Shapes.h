#pragma once

#include <cstddef>
#include <string>
#include <vector>

class ShapeVisitor;

namespace shapeConstants {
    const std::size_t triangleVertexCount = 3;
    const std::size_t rectangleVertexCount = 4;
}

class Point {
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);

    double getX() const;
    double getY() const;
};

class Shape {
public:
    virtual std::string getName() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void accept(ShapeVisitor& visitor) const = 0;
    virtual ~Shape() = default;
};

#include "ShapeVisitor.h"
#include "GeometryCalculator.h"
#include "ShapeTypes/Circle.h"
#include "ShapeTypes/Triangle.h"
#include "ShapeTypes/Rectangle.h"
#include "ShapeTypes/Polygon.h"
