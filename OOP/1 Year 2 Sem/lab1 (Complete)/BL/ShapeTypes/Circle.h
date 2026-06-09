#pragma once
#include "../Shapes.h"

class Circle : public Shape {
private:
    std::string name;
    Point centre;
    double radius;

public:
    Circle(const std::string& name, const Point& centre, double radius);

    std::string getName() const override;
    double getPerimeter() const override;
    void accept(ShapeVisitor& visitor) const override;

    Point getCentre() const;
    double getRadius() const;
};