#pragma once
#include "IAppCommand.h"
#include "../../BL/CalculatorFacade.h"
#include "../../GUI/DisplayValue.h"

class MemoryRecallCommand : public IAppCommand {
private:
    DisplayValue* displayValue;
    CalculatorFacade* calculatorFacade;
    double* memoryValue;

public:
    MemoryRecallCommand(DisplayValue* displayValue, CalculatorFacade* calculatorFacade, double* memoryValue);
    void execute() override;
};
