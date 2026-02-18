#pragma once
#include <string>
#include <vector>

class ShapeVisitor;

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
private:
    std::string name;

public:
    explicit Shape(const std::string &name);
    virtual ~Shape() = default;

    std::string getName() const;

    virtual double perimeter() const = 0;
    virtual void askPerimeter(ShapeVisitor &visitor) const = 0;
    virtual void askParameters(ShapeVisitor &visitor) const = 0;
};

double distance(const Point &a, const Point &b); // For Calculations