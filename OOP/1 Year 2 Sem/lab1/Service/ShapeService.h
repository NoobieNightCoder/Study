#pragma once

#include <memory>
#include <vector>

#include "../BL/Shapes.h"
#include "IShapeService.h"

class ShapeService : public IShapeService {
private:
    std::vector<std::unique_ptr<Shape>> shapesList;

    static double calcArea(const std::vector<Point>& vertices);

public:
    const std::vector<std::unique_ptr<Shape>>& getShapes() const override;
    bool isEmpty() const override;
    std::size_t size() const override;

    ServiceError addCircle(const std::string& name, const Point& centre, double radius) override;
    ServiceError addRectangle(const std::string& name, const std::vector<Point>& vertices) override;
    ServiceError addTriangle(const std::string& name, const std::vector<Point>& vertices) override;

    double sumPerimeters() const override;
    void sortByPerimeter() override;
    ServiceError deleteById(int oneBasedId) override;
    void deleteByPerimeter(double limit) override;
};
