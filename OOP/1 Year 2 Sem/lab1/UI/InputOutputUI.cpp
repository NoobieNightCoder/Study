#include "InputOutputUI.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void InputOutputUI::printMainMenu() const {
    printMessage(UiMessageId::appTitle);
    for (const auto& item : UiMessageCatalog::getMainMenuItems()) {
        cout << item.id << " " << item.description << endl;
    }
}

void InputOutputUI::printShapeMenu() const {
    printMessage(UiMessageId::chooseShapeToAdd);
    for (const auto& item : UiMessageCatalog::getShapeMenuItems()) {
        cout << item.id << " " << item.description << endl;
    }
}

void InputOutputUI::printMessage(UiMessageId messageId) const {
    cout << UiMessageCatalog::getMessage(messageId) << endl;
}

void InputOutputUI::printMessage(UiMessageId messageId, double value) const {
    cout << UiMessageCatalog::getMessage(messageId) << value << endl;
}

void InputOutputUI::printError(UiErrorId errorId) const {
    cout << "Error " << (int)errorId << ": " << UiMessageCatalog::getError(errorId) << endl;
}

void InputOutputUI::printShapeLine(int index, const string& line) const {
    cout << index << ". " << line << endl;
}

int InputOutputUI::readMenuItem() const {
    int item = readValue<int>(UiMessageCatalog::getItemPrompt());
    return item;
}

int InputOutputUI::readShapeId() const {
    int shapeId = readValue<int>(UiMessageCatalog::getShapeIdPrompt());
    return shapeId;
}

string InputOutputUI::readName() const {
    string name = readValue<string>(UiMessageCatalog::getNamePrompt());
    bool hasError = name.empty();

    if (hasError)
        throw (int)UiErrorId::badName;

    return name;
}

double InputOutputUI::readRadius() const {
    double radius = readValue<double>(UiMessageCatalog::getRadiusPrompt());
    bool hasError = radius <= 0;

    if (hasError) {
        throw (int)UiErrorId::badRadius;
    }

    return radius;
}

double InputOutputUI::readPerimeterThreshold() const {
    double threshold = readValue<double>(UiMessageCatalog::getPerimeterThresholdPrompt());
    bool hasError = threshold <= 0;

    if (hasError) {
        throw (int)UiErrorId::badPerimeterThreshold;
    }

    return threshold;
}

Point InputOutputUI::readCentre() const {
    double x = readValue<double>(UiMessageCatalog::getCenterXPrompt());
    double y = readValue<double>(UiMessageCatalog::getCenterYPrompt());
    Point centerPoint(x, y);
    return centerPoint;
}

vector<Point> InputOutputUI::readRectangleVertices() const {
    double x1 = readValue<double>(UiMessageCatalog::getRectangleX1Prompt());
    double y1 = readValue<double>(UiMessageCatalog::getRectangleY1Prompt());
    double x2 = readValue<double>(UiMessageCatalog::getRectangleX2Prompt());
    double y2 = readValue<double>(UiMessageCatalog::getRectangleY2Prompt());

    vector<Point> vertices;
    vertices.reserve(shapeConstants::rectangleVertexCount);
    vertices.emplace_back(x1, y1);
    vertices.emplace_back(x2, y1);
    vertices.emplace_back(x2, y2);
    vertices.emplace_back(x1, y2);
    return vertices;
}

vector<Point> InputOutputUI::readTriangleVertices() const {
    double x1 = readValue<double>(UiMessageCatalog::getTriangleX1Prompt());
    double y1 = readValue<double>(UiMessageCatalog::getTriangleY1Prompt());
    double x2 = readValue<double>(UiMessageCatalog::getTriangleX2Prompt());
    double y2 = readValue<double>(UiMessageCatalog::getTriangleY2Prompt());
    double x3 = readValue<double>(UiMessageCatalog::getTriangleX3Prompt());
    double y3 = readValue<double>(UiMessageCatalog::getTriangleY3Prompt());

    vector<Point> vertices;
    vertices.reserve(shapeConstants::triangleVertexCount);
    vertices.emplace_back(x1, y1);
    vertices.emplace_back(x2, y2);
    vertices.emplace_back(x3, y3);
    return vertices;
}
