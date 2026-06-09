#pragma once

#include <string>

#include "../BL/ShapeVisitor.h"
#include "../BL/Shapes.h"

class ShapePerimeterVisitor : public ShapeVisitor {
private:
    std::string line;

public:
    void visitCircle(const Circle& circle) override;
    void visitRectangle(const Rectangle& rectangle) override;
    void visitTriangle(const Triangle& triangle) override;
    std::string getLine() const;
};
