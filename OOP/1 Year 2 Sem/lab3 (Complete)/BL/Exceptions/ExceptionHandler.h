#pragma once
#include "AppException.h"
#include <string>

class ExceptionHandler {
private:
    std::string wrongInputText() const;
    std::string divisionByZeroText() const;
    std::string nonExistFunctionText() const;
    std::string sqrtOfNegativeNum() const;

public:
    std::string handle(const InputException& exception);
    std::string handle(const AppException& exception);
    std::string handleUnknown();
};
