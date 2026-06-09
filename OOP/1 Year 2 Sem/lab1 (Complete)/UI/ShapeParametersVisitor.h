#pragma once

#include <string>
#include <vector>

#include "../BL/ShapeVisitor.h"
#include "../BL/Shapes.h"

class ShapeParametersVisitor : public ShapeVisitor {
private:
    std::string line;

    std::string verticesToText(const std::vector<Point>& vertices) const;

public:
    void visitCircle(const Circle& circle) override;
    void visitRectangle(const Rectangle& rectangle) override;
    void visitTriangle(const Triangle& triangle) override;
    std::string getLine() const;
};
