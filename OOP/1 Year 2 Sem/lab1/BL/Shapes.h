#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "ShapeVisitor.h"

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

class Triangle : public Shape {
private:
    std::string name;
    std::vector<Point> vertices;

public:
    Triangle(const std::string& name, const std::vector<Point>& vertices);

    std::string getName() const override;
    double getPerimeter() const override;
    void accept(ShapeVisitor& visitor) const override;

    std::vector<Point> getVertices() const;
};
