#pragma once

#include <string>
#include <vector>

#include "../BL/Shapes.h"
#include "IInputOutputUI.h"
#include "IUi.h"

class ConsoleUi : public IUi {
private:
    IInputOutputUI& io;

public:
    explicit ConsoleUi(IInputOutputUI& io);

    int noError() const override;

    void printMainMenu() const override;
    void printAddShapeMenu() const override;
    void printMessage(UiMessageId messageId) const override;
    void printMessage(UiMessageId messageId, double value) const override;
    void printError(UiErrorId errorId) const override;
    void printShapeParameters(const Shape& shape, int index) const override;
    void printShapePerimeter(const Shape& shape, int index) const override;

    int readMenuItem() const override;
    int readShapeId() const override;
    std::string readName(int& errorCode) const override;
    double readRadius(int& errorCode) const override;
    double readPerimeterThreshold(int& errorCode) const override;
    Point readCentre() const override;
    std::vector<Point> readRectangleVertices() const override;
    std::vector<Point> readTriangleVertices() const override;
};
