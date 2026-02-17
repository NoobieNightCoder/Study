#pragma once

#include <string>

// struct Circle {
//     std::string name;
//     double centre;
//     double radius;
// };

// struct Rectangle {
//     std::string name;
//     double point1;
//     double point2;
// };

// struct Triangle {
//     std::string name;
//     double point1;
//     double point2;
//     double point3;
// };

class Shapes {
public:
    Shapes(std::string name) {
        this->name = name;
    }
private:
    std::string name;
};

class Circle: public Shapes {
private:
    double centre;
    double radius;
public:
    int create();
    double getPerimeter();
};

class Rectangle: public Shapes {
private:
    double point1;
    double point2;
public:
    int create();
    double getPerimeter();
};

class Triangle: public Shapes {
private:
    double point1;
    double point2;
    double point3;
public:
    int create();
    double getPerimeter();
};