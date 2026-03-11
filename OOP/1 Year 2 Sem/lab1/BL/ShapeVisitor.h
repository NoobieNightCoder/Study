#pragma once

class Circle;
class Rectangle;
class Triangle;

class ShapeVisitor {
public:
    virtual void visitCircle(const Circle& circle) = 0;
    virtual void visitRectangle(const Rectangle& rectangle) = 0;
    virtual void visitTriangle(const Triangle& triangle) = 0;
    virtual ~ShapeVisitor() = default;
};
