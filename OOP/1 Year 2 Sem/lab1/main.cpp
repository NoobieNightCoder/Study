#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "UI/InputOutputUI.h"
#include "UI/UI.h"
#include "BL/Shapes.h"
#include "BL/FunctionsHandler.h"

using namespace std;

// CREATING SHAPES //

int createCircle(vector<unique_ptr<Shape>> &shapesList) {
    int errorCode = -1;

    double radius = 0;
    Point centre;

    string name = nameInputMenu(&errorCode);

    if(errorCode == -1)
        radius = radiusInputMenu(&errorCode);

    if(errorCode == -1)
        centre = centreInputMenu();

    if(errorCode == -1)
        shapesList.push_back(make_unique<Circle>(name, centre, radius));

    return errorCode;
}

int createRectangle(vector<unique_ptr<Shape>> &shapesList) {
    int errorCode = -1;
    vector<Point> vertices(RECTANGE_VERTICES);

    string name = nameInputMenu(&errorCode);

    if(errorCode == -1) {
        vertices = rectangleVerticesInputMenu();
        if(calcArea(vertices) == 0) errorCode = ERROR_BAD_SHAPE;
    }

    if(errorCode == -1)
        shapesList.push_back(make_unique<Rectangle>(name, vertices));

    return errorCode;
}

int createTriangle(vector<unique_ptr<Shape>> &shapesList) {
    int errorCode = -1;
    vector<Point> vertices(TRIANGLE_VERTICES);

    string name = nameInputMenu(&errorCode);
    
    if(errorCode == -1) {
        vertices = triangleVerticesInputMenu();
        if(calcArea(vertices) == 0) errorCode = ERROR_BAD_SHAPE;
    }

    if(errorCode == -1)
        shapesList.push_back(make_unique<Triangle>(name, vertices));

    return errorCode;
}



// MENU FUNCTIONS //

void addShapeMenu(vector<unique_ptr<Shape>>& shapesList) {
    int errorCode = -1;

    printAddShapeMenu();
    int item = itemInputMenu();

    if     (item == CIRCLE)     errorCode = createCircle(shapesList);
    else if(item == RECTANGLE)  errorCode = createRectangle(shapesList);
    else if(item == TRIANGLE)   errorCode = createTriangle(shapesList);
    else    errorCode = ERROR_BAD_ITEM;

    if(errorCode == -1)
        printMessage(MESSAGE_SHAPE_ADDED);
    else
        printError(errorCode);
}

void listParamMenu(vector<unique_ptr<Shape>> &shapesList) {
    if(size(shapesList) == 0)
        printError(ERROR_EMPTY_LIST);
    else {
        int count = 1;
        for(auto &shape : shapesList)
            printParameters(*shape, count++);
    }
}

void listPerimMenu(vector<unique_ptr<Shape>> &shapesList) {
    if(size(shapesList) == 0)
        printError(ERROR_EMPTY_LIST);
    else {
        int count = 1;
        for(auto &shape : shapesList)
            printPerimeter(*shape, count++);
    }
}

void sumPerimMenu(vector<unique_ptr<Shape>> &shapesList) {
    if(size(shapesList) == 0)
        printError(ERROR_EMPTY_LIST);
    else {
        double sum = sumPerimeters(shapesList);
        printMessage(MESSAGE_SUM_PERIM, sum);
    }
}

void sortListMenu(vector<unique_ptr<Shape>> &shapesList) {
    if(size(shapesList) == 0)
        printError(ERROR_EMPTY_LIST);
    else {
        sortList(shapesList);
        printMessage(MESSAGE_LIST_SORT);
    }
}

void deleteShapeMenu(vector<unique_ptr<Shape>> &shapesList) {
    int errorCode = -1;
    int shapeID = 0;

    if(size(shapesList) == 0)
        errorCode = ERROR_EMPTY_LIST;
    else 
        shapeID = idInputMenu();

    if(errorCode == -1 && (shapeID <= 0 || shapeID > (int)size(shapesList)))
        errorCode = ERROR_BAD_ID;

    if(errorCode == -1) {
        deleteShape(shapesList, --shapeID);
        printMessage(MESSAGE_SHAPE_DELETED);
    } else printError(errorCode);
}

void deleteShapesByPerimMenu(vector<unique_ptr<Shape>>& shapesList) {
    int errorCode = -1;
    double limit = 0;

    if(size(shapesList) == 0)
        errorCode = ERROR_EMPTY_LIST;
    else {
        printMessage(INPUT_PERIM_THRESHOLD);
        limit = perimeterInputMenu(&errorCode);
    }

    if(errorCode == -1) {
        deleteShapesByPerim(shapesList, limit);
        printMessage(MESSAGE_SHAPES_DELETED);
    } else printError(errorCode);
}

// MAIN //

int main() {
    vector<unique_ptr<Shape>> shapesList;
    bool exitFlag = true;

    while(exitFlag) {
        printMenu();
        int item = itemInputMenu();

        if     (item == MENU_ADD_SHAPE)              addShapeMenu(shapesList);
        else if(item == MENU_PRINT_LIST_PARAM)       listParamMenu(shapesList);
        else if(item == MENU_PRINT_LIST_PERIM)       listPerimMenu(shapesList);
        else if(item == MENU_PRINT_PERIM_SUM)        sumPerimMenu(shapesList);
        else if(item == MENU_SORT_SHAPES)            sortListMenu(shapesList);
        else if(item == MENU_DELETE_SHAPE)           deleteShapeMenu(shapesList);
        else if(item == MENU_DELETE_SHAPES_BY_PERIM) deleteShapesByPerimMenu(shapesList);
        else if(item == MENU_EXIT_PROGRAMM)          exitFlag = false;
        
        else    printError(ERROR_BAD_ITEM);
    }

    return 0;
}