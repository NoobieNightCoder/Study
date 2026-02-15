#pragma once

#include <iostream>

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

struct Menu {
    int id;
    std::string description;
};

const Menu menuList[] {
    { MENU_ADD_SHAPE,                "Add a shape to the shape collection"                                  },
    { MENU_PRINT_LIST_PARAM,         "Print a list of shapes with parameters"                               },
    { MENU_PRINT_LIST_PERIM,         "Print a list of shapes with perimeters"                               },
    { MENU_PRINT_PERIM_SUM,          "Print the sum of the perimeters of all shapes"                        },
    { MENU_SORT_SHAPES,              "Sort the shapes in the collection by ascending perimeter"             },
    { MENU_DELETE_SHAPE,             "Remove a shape from the collection by number"                         },
    { MENU_DELETE_SHAPES_BY_PERIM,   "Remove shapes from the collection larger than the entered perimeter"  },
    { MENU_EXIT_PROGRAMM,            "Exit the program"                                                     }
};

int inputMenu();

void waitForInput();

void printMenu();
void addShapeMenu();