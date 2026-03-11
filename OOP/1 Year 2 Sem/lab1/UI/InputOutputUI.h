#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../BL/Shapes.h"
#include "IInputOutputUI.h"
#include "UiMessageCatalog.h"

class InputOutputUI : public IInputOutputUI {
private:
    template<typename T>
    T readValue(const std::string& prompt) const {
        T result {};
        bool isValid = false;

        std::cout << prompt;
        while (!isValid) {
            std::string line;
            std::getline(std::cin, line);

            std::stringstream stream(line);
            T value {};
            bool canRead = (bool)(stream >> value);
            bool isEof = stream.eof();
            isValid = canRead && isEof;

            if (isValid) {
                result = value;
            } else {
                printError(UiErrorId::incorrectInput);
                std::cout << prompt;
            }
        }

        return result;
    }

public:
    void printMainMenu() const override;
    void printShapeMenu() const override;
    void printMessage(UiMessageId messageId) const override;
    void printMessage(UiMessageId messageId, double value) const override;
    void printError(UiErrorId errorId) const override;
    void printShapeLine(int index, const std::string& line) const override;

    int readMenuItem() const override;
    int readShapeId() const override;
    std::string readName() const override;
    double readRadius() const override;
    double readPerimeterThreshold() const override;
    Point readCentre() const override;
    std::vector<Point> readRectangleVertices() const override;
    std::vector<Point> readTriangleVertices() const override;
};
