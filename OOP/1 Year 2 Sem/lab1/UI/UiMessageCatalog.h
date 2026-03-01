#pragma once

#include <string>
#include <vector>

struct MenuItem {
    int id;
    std::string description;
};

enum class MainMenuId {
    addShape = 1,
    printListParameters = 2,
    printListPerimeters = 3,
    printPerimeterSum = 4,
    sortShapes = 5,
    deleteShape = 6,
    deleteShapesByPerimeter = 7,
    exitProgram = 8
};

enum class ShapeMenuId {
    circle = 1,
    rectangle = 2,
    triangle = 3
};

enum class UiMessageId {
    shapeAdded = 0,
    sumPerimeters = 1,
    listSorted = 2,
    shapeDeleted = 3,
    shapesDeleted = 4,
    chooseShapeToAdd = 5,
    appTitle = 6
};

enum class UiErrorId {
    incorrectInput = 0,
    badItem = 1,
    emptyList = 2,
    badName = 3,
    badRadius = 4,
    badShape = 5,
    badId = 6,
    badPerimeterThreshold = 7
};

class UiMessageCatalog final {
public:
    static const std::vector<MenuItem>& getMainMenuItems();
    static const std::vector<MenuItem>& getShapeMenuItems();
    static const std::string& getMessage(UiMessageId messageId);
    static const std::string& getError(UiErrorId errorId);

    static const std::string& getItemPrompt();
    static const std::string& getNamePrompt();
    static const std::string& getRadiusPrompt();
    static const std::string& getCenterXPrompt();
    static const std::string& getCenterYPrompt();
    static const std::string& getRectangleX1Prompt();
    static const std::string& getRectangleY1Prompt();
    static const std::string& getRectangleX2Prompt();
    static const std::string& getRectangleY2Prompt();
    static const std::string& getTriangleX1Prompt();
    static const std::string& getTriangleY1Prompt();
    static const std::string& getTriangleX2Prompt();
    static const std::string& getTriangleY2Prompt();
    static const std::string& getTriangleX3Prompt();
    static const std::string& getTriangleY3Prompt();
    static const std::string& getShapeIdPrompt();
    static const std::string& getPerimeterThresholdPrompt();
};
