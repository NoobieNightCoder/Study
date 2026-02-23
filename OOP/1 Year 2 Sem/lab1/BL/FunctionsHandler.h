#pragma once

#include <vector>
#include <memory>

class Shape;
class Point;

// NEEDED FUNCTIONS //
bool isBlank(std::string &str);
double calcArea(std::vector<Point> vertices);

// PRIMARY FUNCTIONS //
double sumPerimeters(std::vector<std::unique_ptr<Shape>> &shapesList);
void sortList(std::vector<std::unique_ptr<Shape>> &shapesList);
void deleteShape(std::vector<std::unique_ptr<Shape>> &shapesList, int shapeID);
void deleteShapesByPerim(std::vector<std::unique_ptr<Shape>> &shapesList, double limit);

