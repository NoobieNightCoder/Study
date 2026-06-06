#pragma once

#include <string>
#include <vector>

#include "../BL/Shapes.h"
#include "UiMessageCatalog.h"

class IInputOutputUI {
public:
    virtual void printMainMenu() const = 0;
    virtual void printShapeMenu() const = 0;
    virtual void printMessage(UiMessageId messageId) const = 0;
    virtual void printMessage(UiMessageId messageId, double value) const = 0;
    virtual void printError(std::string errorMessage) const = 0;
    virtual void printShapeLine(int index, const std::string& line) const = 0;

    virtual int readMenuItem() const = 0;
    virtual int readShapeId() const = 0;
    virtual std::string readName() const = 0;
    virtual double readRadius() const = 0;
    virtual double readPerimeterThreshold() const = 0;
    virtual Point readCentre() const = 0;
    virtual std::vector<Point> readRectangleVertices() const = 0;
    virtual std::vector<Point> readTriangleVertices() const = 0;

    virtual ~IInputOutputUI() = default;
};
