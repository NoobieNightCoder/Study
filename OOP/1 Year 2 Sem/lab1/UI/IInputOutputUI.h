#pragma once

#include <string>
#include <vector>

#include "../BL/Shapes.h"
#include "UiMessageCatalog.h"

class IInputOutputUI {
public:
    virtual int noError() const = 0;

    virtual void printMainMenu() const = 0;
    virtual void printShapeMenu() const = 0;
    virtual void printMessage(UiMessageId messageId) const = 0;
    virtual void printMessage(UiMessageId messageId, double value) const = 0;
    virtual void printError(UiErrorId errorId) const = 0;
    virtual void printShapeLine(int index, const std::string& line) const = 0;

    virtual int readMenuItem() const = 0;
    virtual int readShapeId() const = 0;
    virtual std::string readName(int& errorCode) const = 0;
    virtual double readRadius(int& errorCode) const = 0;
    virtual double readPerimeterThreshold(int& errorCode) const = 0;
    virtual Point readCentre() const = 0;
    virtual std::vector<Point> readRectangleVertices() const = 0;
    virtual std::vector<Point> readTriangleVertices() const = 0;

    virtual ~IInputOutputUI() = default;
};
