#include "InputOutputUI.h"

#include "../Service/ErrorService.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void InputOutputUI::printMainMenu() const {
    printMessage(UiMessageId::appTitle);
    for (const auto& item : UiMessageCatalog::getMainMenuItems())
        cout << item.id << " " << item.description << endl;
}

void InputOutputUI::printShapeMenu() const {
    printMessage(UiMessageId::chooseShapeToAdd);
    for (const auto& item : UiMessageCatalog::getShapeMenuItems())
        cout << item.id << " " << item.description << endl;
}

void InputOutputUI::printMessage(UiMessageId messageId) const {
    cout << UiMessageCatalog::getMessage(messageId) << endl;
}

void InputOutputUI::printMessage(UiMessageId messageId, double value) const {
    cout << UiMessageCatalog::getMessage(messageId) << value << endl;
}

void InputOutputUI::printError(string errorMessage) const {
    cout << "Error: " << errorMessage << endl;
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
        throw ValidationException(ValidationException::Messages::InvalidName);

    return name;
}

double InputOutputUI::readRadius() const {
    double radius = readValue<double>(UiMessageCatalog::getRadiusPrompt());

    if (radius <= 0)
        throw ValidationException(ValidationException::Messages::InvalidRadius);

    return radius;
}

double InputOutputUI::readPerimeterThreshold() const {
    double threshold = readValue<double>(UiMessageCatalog::getPerimeterThresholdPrompt());

    if (threshold <= 0)
        throw ValidationException(ValidationException::Messages::InvalidThreshold);

    return threshold;
}

Point InputOutputUI::readCentre() const {
    double x = readValue<double>(UiMessageCatalog::getCenterXPrompt());
    double y = readValue<double>(UiMessageCatalog::getCenterYPrompt());
    Point centerPoint(x, y);

    return centerPoint;
}

vector<Point> InputOutputUI::readRectangleVertices() const {
    double x1 = readValue<double>(UiMessageCatalog::getRectangleXPrompt(1));
    double y1 = readValue<double>(UiMessageCatalog::getRectangleYPrompt(1));
    double x2 = readValue<double>(UiMessageCatalog::getRectangleXPrompt(2));
    double y2 = readValue<double>(UiMessageCatalog::getRectangleYPrompt(2));

    vector<Point> vertices;
    vertices.reserve(shapeConstants::rectangleVertexCount);
    vertices.emplace_back(x1, y1);
    vertices.emplace_back(x2, y1);
    vertices.emplace_back(x2, y2);
    vertices.emplace_back(x1, y2);

    return vertices;
}

vector<Point> InputOutputUI::readTriangleVertices() const {
    vector<Point> vertices;
    vertices.reserve(shapeConstants::triangleVertexCount);

    for(int vertice = 0; vertice < shapeConstants::triangleVertexCount; vertice++) {
        double x = readValue<double>(UiMessageCatalog::getTriangleXPrompt(vertice + 1));
        double y = readValue<double>(UiMessageCatalog::getTriangleYPrompt(vertice + 1));
        vertices.emplace_back(x, y);
    }

    return vertices;
}

vector<Point> InputOutputUI::readPolygonVertices() const {
    vector<Point> vertices;

    double verticeCount = readValue<int>(UiMessageCatalog::getVerticeCountPrompt());
    vertices.reserve(verticeCount);

    for(int vertice = 0; vertice < verticeCount; vertice++) {
        double x = readValue<double>(UiMessageCatalog::getPolygonXPrompt(vertice + 1));
        double y = readValue<double>(UiMessageCatalog::getPolygonYPrompt(vertice + 1));
        vertices.emplace_back(x, y);
    }

    return vertices;
}