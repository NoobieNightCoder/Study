#include "UiMessageCatalog.h"

#include <string>
#include <vector>

using namespace std;

namespace {
const vector<MenuItem> mainMenuItems {
    { (int)MainMenuId::addShape,                "Add a shape to the shape list"                         },
    { (int)MainMenuId::printListParameters,     "Print a list of shapes with parameters"                },
    { (int)MainMenuId::printListPerimeters,     "Print a list of shapes with perimeters"                },
    { (int)MainMenuId::printPerimeterSum,       "Print the sum of the perimeters of all shapes"         },
    { (int)MainMenuId::sortShapes,              "Sort shapes by ascending perimeter"                    },
    { (int)MainMenuId::deleteShape,             "Delete one shape by id"                                },
    { (int)MainMenuId::deleteShapesByPerimeter, "Delete shapes with perimeter greater than threshold"   },
    { (int)MainMenuId::exitProgram,             "Exit program"                                          }
};

const vector<MenuItem> shapeMenuItems {
    { (int)ShapeMenuId::circle,     "Circle"    },
    { (int)ShapeMenuId::rectangle,  "Rectangle" },
    { (int)ShapeMenuId::triangle,   "Triangle"  }
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

const vector<string> errorItems {
    "Invalid input. Try again.",
    "This item does not exist.",
    "The shape list is empty.",
    "This name cannot be applied.",
    "Radius must be greater than zero.",
    "This shape cannot exist.",
    "This id does not exist.",
    "Perimeter threshold must be greater than zero."
};

const string itemPrompt = "Enter menu item: ";

const string namePrompt = "Enter name: ";

const string radiusPrompt = "Enter radius: ";

const string centerXPrompt = "Center X: ";
const string centerYPrompt = "Center Y: ";

const string rectangleX1Prompt = "Rectangle x1: ";
const string rectangleY1Prompt = "Rectangle y1: ";
const string rectangleX2Prompt = "Rectangle x2: ";
const string rectangleY2Prompt = "Rectangle y2: ";

const string triangleX1Prompt = "Triangle x1: ";
const string triangleY1Prompt = "Triangle y1: ";
const string triangleX2Prompt = "Triangle x2: ";
const string triangleY2Prompt = "Triangle y2: ";
const string triangleX3Prompt = "Triangle x3: ";
const string triangleY3Prompt = "Triangle y3: ";

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

const string& UiMessageCatalog::getError(UiErrorId errorId) {
    size_t index = (size_t)errorId;
    const string& result = errorItems[index];
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

const string& UiMessageCatalog::getRectangleX1Prompt() {
    const string& result = rectangleX1Prompt;
    return result;
}

const string& UiMessageCatalog::getRectangleY1Prompt() {
    const string& result = rectangleY1Prompt;
    return result;
}

const string& UiMessageCatalog::getRectangleX2Prompt() {
    const string& result = rectangleX2Prompt;
    return result;
}

const string& UiMessageCatalog::getRectangleY2Prompt() {
    const string& result = rectangleY2Prompt;
    return result;
}

const string& UiMessageCatalog::getTriangleX1Prompt() {
    const string& result = triangleX1Prompt;
    return result;
}

const string& UiMessageCatalog::getTriangleY1Prompt() {
    const string& result = triangleY1Prompt;
    return result;
}

const string& UiMessageCatalog::getTriangleX2Prompt() {
    const string& result = triangleX2Prompt;
    return result;
}

const string& UiMessageCatalog::getTriangleY2Prompt() {
    const string& result = triangleY2Prompt;
    return result;
}

const string& UiMessageCatalog::getTriangleX3Prompt() {
    const string& result = triangleX3Prompt;
    return result;
}

const string& UiMessageCatalog::getTriangleY3Prompt() {
    const string& result = triangleY3Prompt;
    return result;
}

const string& UiMessageCatalog::getShapeIdPrompt() {
    const string& result = shapeIdPrompt;
    return result;
}

const string& UiMessageCatalog::getPerimeterThresholdPrompt() {
    const string& result = perimeterThresholdPrompt;
    return result;
}
