#include "FunctionsHandler.h"

#include <algorithm>
#include <vector>
#include <memory>
#include <cmath>

#include "Shapes.h"

using namespace std;

// NEEDED FUNCTIONS //

static double distance(const Point &a, const Point &b) {
    return sqrt(
        (a.getX() - b.getX()) * (a.getX() - b.getX()) +
        (a.getY() - b.getY()) * (a.getY() - b.getY())
    );
}

bool isBlank(string &str) {
    return all_of(str.begin(), str.end(),
        [](unsigned char c) {
            return isspace(c);
        });
}

double calcArea(vector<Point> vertices) {
    double result = 0;
    if(size(vertices) == TRIANGLE_VERTICES) {
        double a = distance(vertices[0], vertices[1]);
        double b = distance(vertices[1], vertices[2]);
        double c = distance(vertices[2], vertices[0]);

        double p = (a + b + c) / 2.0;

        result = sqrt(p * (p - a) * (p - b) * (p - c));
    } else if (size(vertices) == RECTANGE_VERTICES) {
        double a = distance(vertices[0], vertices[1]);
        double b = distance(vertices[1], vertices[2]);

        result = a * b;
    }

    return result;
}



// PRIMARY FUNCTIONS //

double sumPerimeters(vector<unique_ptr<Shape>> &shapesList) {
    double sum = 0;
    for(auto &shape : shapesList)
        sum += shape->getPerimeter();
    
    return sum;
}

void sortList(vector<unique_ptr<Shape>> &shapesList) {
    sort(shapesList.begin(), shapesList.end(),
         []
         (auto& a, auto& b) {
            return a->getPerimeter() < b->getPerimeter();
         }
    );
}

void deleteShape(vector<unique_ptr<Shape>> &shapesList, int shapeID) {
    shapesList.erase(shapesList.cbegin() + shapeID);
}

void deleteShapesByPerim(vector<unique_ptr<Shape>> &shapesList, double limit) {
    shapesList.erase(
        remove_if(shapesList.begin(), shapesList.end(),
            [limit]
            (auto& shape) {
                return shape->getPerimeter() > limit;
            }),
        shapesList.end()
    );
}