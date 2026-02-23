#pragma once

#include <string>
#include <vector>


#define TRIANGLE_VERTICES 3
#define RECTANGE_VERTICES 4

// POINT CLASS FOR COORDS //

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

// MAIN SHAPE CLASS //

class Shape {
public:
    virtual std::string getName()     const = 0;
    virtual std::string getTypeName() const = 0;
    virtual double getPerimeter()     const = 0;

    virtual ~Shape() = default;
};

// CIRCLE //

class Circle : public Shape {
private:
    std::string name;
    Point centre;
    double radius;

public:
    Circle(std::string n, Point c, double r);

    std::string getName() const override;
    std::string getTypeName() const override;
    double getPerimeter() const override;

    Point getCentre() const;
    double getRadius() const;
};

// RECTANGLE //

class Rectangle : public Shape {
private:
    std::string name;
    std::vector<Point> vertices;
public:
    Rectangle(std::string n, std::vector<Point> v);
    std::string getName() const override;
    std::string getTypeName() const override;
    std::vector<Point> getVertices() const;
    double getPerimeter() const override;
};

// TRIANGLE //

class Triangle : public Shape {
private:
    std::string name;
    std::vector<Point> vertices;
public:
    Triangle(std::string n, std::vector<Point> v);
    std::string getName() const override;
    std::string getTypeName() const override;
    std::vector<Point> getVertices() const;
    double getPerimeter() const override;
};