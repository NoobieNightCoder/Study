#pragma once

#include "../shapes.h"
#include <vector>
#include <string>

class Circle : public Shape {
private:
    Point center;
    double radius;

public:
    Circle(const std::string &name,
           const Point &center,
           double radius);

    double perimeter() const override;
    void askPerimeter(ShapeVisitor &visitor) const override;
    void askParameters(ShapeVisitor &visitor) const override;

    Point getCenter() const;
    double getRadius() const;
};