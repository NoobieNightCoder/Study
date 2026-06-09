#pragma once
#include "IAppCommand.h"
#include "../../BL/CalculatorFacade.h"
#include "../../BL/Exceptions/ExceptionHandler.h"
#include "../../GUI/DisplayValue.h"

class MemoryPlusCommand : public IAppCommand {
private:
    DisplayValue* displayValue;
    CalculatorFacade* calculatorFacade;
    ExceptionHandler* exceptionHandler;
    bool* isError;
    double* memoryValue;

    void setError(const std::string& text);

public:
    MemoryPlusCommand(DisplayValue* displayValue, CalculatorFacade* calculatorFacade, ExceptionHandler* exceptionHandler, bool* isError, double* memoryValue);
    void execute() override;
};
