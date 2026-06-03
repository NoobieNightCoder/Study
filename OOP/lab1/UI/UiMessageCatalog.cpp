#include "UiMessageCatalog.h"

#include <string>
#include <vector>

using namespace std;

namespace {
const vector<MenuItem> mainMenuItems {
    { (int)MainMenuId::addShape,                "Add a shape to the shape list"                         },
    { (int)MainMenuId::printListParameters,     "Print a list of shapes with parameters"                },
    { (int)MainMenuId::printListPerimeters,     "Print a list of shapes with perimeters"                },
    { (int)MainMenuId::printListShapes,         "Print a list of shapes"                                },
    { (int)MainMenuId::printPerimeterSum,       "Print the sum of the perimeters of all shapes"         },
    { (int)MainMenuId::sortShapes,              "Sort shapes by ascending perimeter"                    },
    { (int)MainMenuId::deleteShape,             "Delete one shape by id"                                },
    { (int)MainMenuId::deleteShapesByPerimeter, "Delete shapes with perimeter greater than threshold"   },
    { (int)MainMenuId::exitProgram,             "Exit program"                                          }
};

const vector<MenuItem> shapeMenuItems {
    { (int)ShapeMenuId::circle,     "Circle"    },
    { (int)ShapeMenuId::rectangle,  "Rectangle" },
    { (int)ShapeMenuId::triangle,   "Triangle"  },
    { (int)ShapeMenuId::polygon,    "Polygon"   }
};

const vector<string> messageItems {
    "Shape has been added!",
    "Sum of perimeters: ",
    "List sorted!",
    "Shape has been deleted!",
    "Shapes have been deleted!",
    "Which shape do you want to add?",
    "Lab Work #1"
};

const string itemPrompt = "Enter menu item: ";

const string namePrompt = "Enter name: ";

const string radiusPrompt = "Enter radius: ";

const string verticeCountPrompt = "Enter vertice count: ";

const string centerXPrompt = "Center X: ";
const string centerYPrompt = "Center Y: ";

const string rectanglePrompt = "Rectangle";

const string trianglePrompt = "Triangle";

const string polygonPrompt = "Polygon";

const string shapeIdPrompt = "Shape id to delete: ";

const string perimeterThresholdPrompt = "Enter perimeter threshold: ";
}

const vector<MenuItem>& UiMessageCatalog::getMainMenuItems() {
    const vector<MenuItem>& result = mainMenuItems;
    return result;
}

const vector<MenuItem>& UiMessageCatalog::getShapeMenuItems() {
    const vector<MenuItem>& result = shapeMenuItems;
    return result;
}

const string& UiMessageCatalog::getMessage(UiMessageId messageId) {
    size_t index = (size_t)messageId;
    const string& result = messageItems[index];
    return result;
}

const string& UiMessageCatalog::getItemPrompt() {
    const string& result = itemPrompt;
    return result;
}

const string& UiMessageCatalog::getNamePrompt() {
    const string& result = namePrompt;
    return result;
}

const string& UiMessageCatalog::getRadiusPrompt() {
    const string& result = radiusPrompt;
    return result;
}

const string& UiMessageCatalog::getCenterXPrompt() {
    const string& result = centerXPrompt;
    return result;
}

const string& UiMessageCatalog::getCenterYPrompt() {
    const string& result = centerYPrompt;
    return result;
}

const string& UiMessageCatalog::getRectangleXPrompt(int n) {
    const string& result = rectanglePrompt + " X" + to_string(n) + ": ";
    return result;
}

const string& UiMessageCatalog::getRectangleYPrompt(int n) {
    const string& result = rectanglePrompt + " Y" + to_string(n) + ": ";
    return result;
}

const string& UiMessageCatalog::getTriangleXPrompt(int n) {
    const string& result = trianglePrompt + " X" + to_string(n) + ": ";
    return result;
}

const string& UiMessageCatalog::getTriangleYPrompt(int n) {
    const string& result = trianglePrompt + " Y" + to_string(n) + ": ";
    return result;
}

const string& UiMessageCatalog::getPolygonXPrompt(int n) {
    const string& result = polygonPrompt + " X" + to_string(n) + ": ";
    return result;
}

const string& UiMessageCatalog::getPolygonYPrompt(int n) {
    const string& result = polygonPrompt + " Y" + to_string(n) + ": ";
    return result;
}

const string& UiMessageCatalog::getShapeIdPrompt() {
    const string& result = shapeIdPrompt;
    return result;
}

const string& UiMessageCatalog::getVerticeCountPrompt() {
    const string& result = verticeCountPrompt;
    return result;
}

const string& UiMessageCatalog::getPerimeterThresholdPrompt() {
    const string& result = perimeterThresholdPrompt;
    return result;
}
