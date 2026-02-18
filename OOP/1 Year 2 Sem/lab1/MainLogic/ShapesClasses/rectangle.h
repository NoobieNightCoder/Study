#pragma once

#include "../shapes.h"
#include <vector>
#include <string>

class Rectangle : public Shape {
private:
    std::vector<Point> vertices;

public:
    Rectangle(const std::string &name,
              const std::vector<Point> &vertices);

    double perimeter() const override;
    void askPerimeter(ShapeVisitor &visitor) const override;
    void askParameters(ShapeVisitor &visitor) const override;

    const std::vector<Point> &getVertices() const;
};