#pragma once
#include "../Shapes.h"

class Rectangle : public Shape {
private:
    std::string name;
    std::vector<Point> vertices;

public:
    Rectangle(const std::string& name, const std::vector<Point>& vertices);

    std::string getName() const override;
    double getPerimeter() const override;
    void accept(ShapeVisitor& visitor) const override;

    std::vector<Point> getVertices() const;
};