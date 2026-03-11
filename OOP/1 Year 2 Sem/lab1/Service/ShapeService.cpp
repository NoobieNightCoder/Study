#include "ShapeService.h"

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

    if (isTriangle) {
        area = ShapeMath::triangleArea(vertices);
    }
    if (isRectangle) {
        area = ShapeMath::rectangleArea(vertices);
    }

    return area;
}

ServiceError ShapeService::addCircle(const string& name, const Point& centre, double radius) {
    ServiceError result = ServiceError::none;
    bool hasError = radius <= 0;

    if (hasError) {
        result = ServiceError::badRadius;
    }
    if (!hasError) {
        shapesList.push_back(make_unique<Circle>(name, centre, radius));
    }

    return result;
}

ServiceError ShapeService::addRectangle(const string& name, const vector<Point>& vertices) {
    ServiceError result = ServiceError::none;
    bool hasError = calcArea(vertices) == 0;

    if (hasError) {
        result = ServiceError::badShape;
    }
    if (!hasError) {
        shapesList.push_back(make_unique<Rectangle>(name, vertices));
    }

    return result;
}

ServiceError ShapeService::addTriangle(const string& name, const vector<Point>& vertices) {
    ServiceError result = ServiceError::none;
    bool hasError = calcArea(vertices) == 0;

    if (hasError) {
        result = ServiceError::badShape;
    }
    if (!hasError) {
        shapesList.push_back(make_unique<Triangle>(name, vertices));
    }

    return result;
}

double ShapeService::sumPerimeters() const {
    double perimeterSum = 0;
    for (const auto& shape : shapesList) {
        perimeterSum += shape->getPerimeter();
    }
    return perimeterSum;
}

void ShapeService::sortByPerimeter() {
    sort(shapesList.begin(), shapesList.end(),
        [](const auto& left, const auto& right) {
            bool lessValue = left->getPerimeter() < right->getPerimeter();
            return lessValue;
        });
}

ServiceError ShapeService::deleteById(int oneBasedId) {
    ServiceError result = ServiceError::none;
    bool idIsTooSmall = oneBasedId <= 0;
    bool idIsTooBig = (size_t)oneBasedId > shapesList.size();
    bool hasError = idIsTooSmall || idIsTooBig;

    if (hasError) {
        result = ServiceError::badId;
    }
    if (!hasError) {
        shapesList.erase(shapesList.begin() + (oneBasedId - 1));
    }

    return result;
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
