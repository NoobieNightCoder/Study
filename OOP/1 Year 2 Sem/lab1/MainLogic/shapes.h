#pragma once
#include <string>
#include <vector>

using namespace std;

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


class Circle;
class Rectangle;
class Triangle;


class ShapeVisitor {
public:
    virtual ~ShapeVisitor() = default;

    virtual void visit(const Circle&) = 0;
    virtual void visit(const Rectangle&) = 0;
    virtual void visit(const Triangle&) = 0;
};





class Shape {
private:
    string name;

public:
    explicit Shape(const string &name);
    virtual ~Shape() = default;

    string getName() const;

    virtual double perimeter() const = 0;
    virtual void accept(ShapeVisitor &visitor) const = 0;
};



class Circle : public Shape {
private:
    Point center;
    double radius;

public:
    Circle(const string &name,
           const Point &center,
           double radius);

    double perimeter() const override;
    void accept(ShapeVisitor &visitor) const override;


    Point getCenter() const;
    double getRadius() const;
};



class Rectangle : public Shape {
private:
    vector<Point> vertices;

public:
    Rectangle(const string &name,
              const vector<Point> &vertices);

    double perimeter() const override;
    void accept(ShapeVisitor &visitor) const override;

    const vector<Point> &getVertices() const;
};



class Triangle : public Shape {
private:
    vector<Point> vertices;
public:
    Triangle(const string &name,
             const vector<Point> &vertices);

    double perimeter() const override;
    void accept(ShapeVisitor &visitor) const override;

    const vector<Point> &getVertices() const;
};
