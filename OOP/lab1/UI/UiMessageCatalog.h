#pragma once

#include <string>
#include <vector>

struct MenuItem {
    int id;
    std::string description;
};

enum class MainMenuId {
    addShape = 1,
    printListParameters,
    printListPerimeters,
    printListShapes,
    printPerimeterSum,
    sortShapes,
    deleteShape,
    deleteShapesByPerimeter,
    exitProgram
};

enum class ShapeMenuId {
    circle = 1,
    rectangle,
    triangle
};

enum class UiMessageId {
    shapeAdded,
    sumPerimeters,
    listSorted,
    shapeDeleted,
    shapesDeleted,
    chooseShapeToAdd,
    appTitle
};

class UiMessageCatalog final {
public:
    static const std::vector<MenuItem>& getMainMenuItems();
    static const std::vector<MenuItem>& getShapeMenuItems();

    static const std::string& getMessage(UiMessageId messageId);

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
