#pragma once

#include <string>

class ShapeTextCatalog final {
public:
    static const std::string& getCircleLabel();
    static const std::string& getRectangleLabel();
    static const std::string& getTriangleLabel();
    static const std::string& getPolygonLabel();
    static const std::string& getRadiusLabel();
    static const std::string& getCenterLabel();
    static const std::string& getVerticesLabel();
    static const std::string& getPerimeterLabel();
    static const std::string& getSeparator();
};
