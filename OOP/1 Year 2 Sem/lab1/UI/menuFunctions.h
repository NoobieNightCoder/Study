#pragma once

#include <iostream>

class Point;

typedef enum {
    MENU_ADD_SHAPE              = 1,
    MENU_PRINT_LIST_PARAM       = 2,
    MENU_PRINT_LIST_PERIM       = 3,
    MENU_PRINT_PERIM_SUM        = 4,
    MENU_SORT_SHAPES            = 5,
    MENU_DELETE_SHAPE           = 6,
    MENU_DELETE_SHAPES_BY_PERIM = 7,
    MENU_EXIT_PROGRAMM          = 8
} menuCodes;

typedef enum {
    CIRCLE      = 1,
    RECTANGLE   = 2,
    TRIANGLE    = 3
} ShapesID;


struct Menu {
    int id;
    std::string description;
};

const Menu mainMenu[] {
    { MENU_ADD_SHAPE,                "Add a shape to the shape collection"                                  },
    { MENU_PRINT_LIST_PARAM,         "Print a list of shapes with parameters"                               },
    { MENU_PRINT_LIST_PERIM,         "Print a list of shapes with perimeters"                               },
    { MENU_PRINT_PERIM_SUM,          "Print the sum of the perimeters of all shapes"                        },
    { MENU_SORT_SHAPES,              "Sort the shapes in the collection by ascending perimeter"             },
    { MENU_DELETE_SHAPE,             "Remove a shape from the collection by number"                         },
    { MENU_DELETE_SHAPES_BY_PERIM,   "Remove shapes from the collection larger than the entered perimeter"  },
    { MENU_EXIT_PROGRAMM,            "Exit the program"                                                     }
};

const Menu shapeAddMenu[] {
    { CIRCLE,       "Circle"    },
    { RECTANGLE,    "Rectangle" },
    { TRIANGLE,     "Triangle"  }
};

void waitForInput();

void printMenu();

int addShapeMenu();

int itemInputMenu();
std::string nameInputMenu();
double radiusInputMenu();
std::vector<Point> rectangleVerticesInputMenu();
std::vector<Point> triangleVerticesInputMenu();

void printParamsMenu();

void printPerimsMenu();

void printPerimSumMenu();

void deleteShapeByIndexMenu();

void deleteShapesByPerimMenu();