#pragma once

#include "ShapesClasses/circle.h"
#include "ShapesClasses/rectangle.h"
#include "ShapesClasses/triangle.h"

class Circle;
class Rectangle;
class Triangle;

class ShapeVisitor {
public:
    virtual ~ShapeVisitor() = default;

    virtual void getPerimeter(const Circle&) = 0;
    virtual void getPerimeter(const Rectangle&) = 0;
    virtual void getPerimeter(const Triangle&) = 0;

    virtual void getParams(const Circle&) = 0;
    virtual void getParams(const Rectangle&) = 0;
    virtual void getParams(const Triangle&) = 0;
};


class PrintVisitor : public ShapeVisitor {
private:
    int index = 1;

public:
    /*  GET PERIMETERs   */
    void getPerimeter(const Circle &c) override;
    void getPerimeter(const Rectangle &r) override;
    void getPerimeter(const Triangle &t) override;

    /*  GET PARAMETERS   */
    void getParams(const Circle &c) override;
    void getParams(const Rectangle &r) override;
    void getParams(const Triangle &t) override;
};