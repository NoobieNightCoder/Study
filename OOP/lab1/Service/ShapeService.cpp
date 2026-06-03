#include "ShapeService.h"

#include "ErrorService.h"

#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>

#define ZERO 0
#define ONE 1
#define TWO 2

using namespace std;

namespace {
    class ShapeMath final {
    public:

        static double distance(const Point& first, const Point& second) {
            double deltaX = first.getX() - second.getX();
            double deltaY = first.getY() - second.getY();
            double value = sqrt(deltaX * deltaX + deltaY * deltaY);
            return value;
        }

        static double triangleArea(const vector<Point>& vertices) {
            double firstSide = distance(vertices[ZERO], vertices[ONE]);
            double secondSide = distance(vertices[ONE], vertices[TWO]);
            double thirdSide = distance(vertices[TWO], vertices[ZERO]);
            double semiperimeter = (firstSide + secondSide + thirdSide) / TWO;
            double area = sqrt(semiperimeter * (semiperimeter - firstSide) * (semiperimeter - secondSide) * (semiperimeter - thirdSide));
            return area;
        }

        static double rectangleArea(const vector<Point>& vertices) {
            double firstSide = distance(vertices[ZERO], vertices[ONE]);
            double secondSide = distance(vertices[ONE], vertices[TWO]);
            double area = firstSide * secondSide;
            return area;
        }

        static bool isPolygonConvex(const std::vector<Point>& vertices) {
            bool status = true;
            size_t verticeNum = vertices.size();

            if (verticeNum < 3) status = false;
            else {
                bool got_negative = false;
                bool got_positive = false;

                for (size_t i = 0; i < verticeNum && status; ++i) {
                    const Point& p1 = vertices[i];
                    const Point& p2 = vertices[(i + 1) % verticeNum];
                    const Point& p3 = vertices[(i + 2) % verticeNum];

                    // Вектор A 
                    double ax = p2.getX() - p1.getX();
                    double ay = p2.getY() - p1.getY();

                    // Вектор B
                    double bx = p3.getX() - p2.getX();
                    double by = p3.getY() - p2.getY();

                    double cross_product = ax * by - ay * bx;

                    if (cross_product < 0)
                        got_negative = true;
                    else if (cross_product > 0)
                        got_positive = true;

                    if (got_negative && got_positive)
                        status = false;
                }
            }
            return status;
        }
    };
}

const vector<unique_ptr<Shape>>& ShapeService::getShapes() const {
    const vector<unique_ptr<Shape>>& result = shapesList;
    return result;
}

bool ShapeService::isEmpty() const {
    bool result = shapesList.empty();
    return result;
}

size_t ShapeService::size() const {
    size_t result = shapesList.size();
    return result;
}

double ShapeService::calcArea(const vector<Point>& vertices) {
    double area = 0;
    bool isTriangle = vertices.size() == shapeConstants::triangleVertexCount;
    bool isRectangle = vertices.size() == shapeConstants::rectangleVertexCount;

    if (isTriangle)
        area = ShapeMath::triangleArea(vertices);

    if (isRectangle)
        area = ShapeMath::rectangleArea(vertices);

    return area;
}

void ShapeService::addCircle(const string& name, const Point& centre, double radius) {
    if (radius <= 0) 
        throw ValidationException(ValidationException::Messages::InvalidRadius);
    
    shapesList.push_back(make_unique<Circle>(name, centre, radius));
}

void ShapeService::addRectangle(const string& name, const vector<Point>& vertices) {
    if (calcArea(vertices) == 0)
        throw ValidationException(ValidationException::Messages::InvalidShape);

    shapesList.push_back(make_unique<Rectangle>(name, vertices));
}

void ShapeService::addTriangle(const string& name, const vector<Point>& vertices) {
    if (calcArea(vertices) == 0)
        throw ValidationException(ValidationException::Messages::InvalidShape);

    shapesList.push_back(make_unique<Triangle>(name, vertices));
}

void ShapeService::addPolygon(const string& name, const vector<Point>& vertices) {
    if (!ShapeMath::isPolygonConvex(vertices))
        throw ValidationException(ValidationException::Messages::InvalidShape);

    shapesList.push_back(make_unique<Polygon>(name, vertices));
}


double ShapeService::sumPerimeters() const {
    double perimeterSum = 0;
    for (const auto& shape : shapesList)
        perimeterSum += shape->getPerimeter();

    return perimeterSum;
}

void ShapeService::sortByPerimeter() {
    sort(shapesList.begin(), shapesList.end(),
        [](const auto& left, const auto& right) {
            bool lessValue = left->getPerimeter() < right->getPerimeter();
            return lessValue;
        });
}

void ShapeService::deleteById(int oneBasedId) {
    bool idIsTooSmall = oneBasedId <= 0;
    bool idIsTooBig = (size_t)oneBasedId > shapesList.size();

    if (idIsTooSmall || idIsTooBig)
        throw NotFoundException(NotFoundException::Messages::noID);

    shapesList.erase(shapesList.begin() + (oneBasedId - 1));
}

void ShapeService::deleteByPerimeter(double limit) {
    shapesList.erase(
        remove_if(shapesList.begin(), shapesList.end(),
            [limit](const auto& shape) {
                bool removeShape = shape->getPerimeter() > limit;
                return removeShape;
            }),
        shapesList.end()
    );
}
