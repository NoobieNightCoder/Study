#pragma once

#include <string>
#include <vector>

#include "../BL/ShapeVisitor.h"
#include "../BL/Shapes.h"

class ShapeTypeVisitor : public ShapeVisitor {
private:
    std::string line;
public:
    void visitCircle(const Circle& circle) override;
    void visitRectangle(const Rectangle& rectangle) override;
    void visitTriangle(const Triangle& triangle) override;
    void visitPolygon(const Polygon& polygon) override;
    std::string getLine() const;
};
