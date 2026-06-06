#pragma once
#include "Calculator.h"
#include <string>

class CalculatorFacade {
private:
    Calculator calculator;

    std::string formatResult(double value) const;
    std::string trimResult(std::string value) const;

public:
    std::string calculate(const std::string& problem);
    std::string valueText(double value) const;
};
