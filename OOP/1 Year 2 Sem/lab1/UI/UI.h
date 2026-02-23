#pragma once

#include <iostream>
#include <string>
#include <vector>

class Point;
class Shape;


// BASIC MENU //
void printMenu();
void printAddShapeMenu();
void printParameters(const Shape& shape, int index);
void printPerimeter(const Shape &shape, int index);


// MENU INPUTS //
int itemInputMenu();
int idInputMenu();

std::string nameInputMenu(int* errorCode);

double radiusInputMenu(int* errorCode);
double perimeterInputMenu(int* errorCode);

Point centreInputMenu();

std::vector<Point> rectangleVerticesInputMenu();
std::vector<Point> triangleVerticesInputMenu();