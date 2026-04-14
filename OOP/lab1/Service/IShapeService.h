#pragma once

#include <memory>
#include <vector>

#include "../BL/Shapes.h"

enum class ServiceError {
    none = -1,
    badRadius = 1,
    badShape = 2,
    badId = 3
};

class IShapeService {
public:
    virtual const std::vector<std::unique_ptr<Shape>>& getShapes() const = 0;
    virtual bool isEmpty() const = 0;
    virtual std::size_t size() const = 0;

    virtual void addCircle(const std::string& name, const Point& centre, double radius) = 0;
    virtual void addRectangle(const std::string& name, const std::vector<Point>& vertices) = 0;
    virtual void addTriangle(const std::string& name, const std::vector<Point>& vertices) = 0;

    virtual double sumPerimeters() const = 0;
    virtual void sortByPerimeter() = 0;
    virtual void deleteById(int oneBasedId) = 0;
    virtual void deleteByPerimeter(double limit) = 0;

    virtual ~IShapeService() = default;
};
