#pragma once
#include "IAppCommand.h"
#include "../../BL/CalculatorFacade.h"
#include "../../BL/Exceptions/ExceptionHandler.h"
#include "../../GUI/DisplayValue.h"

class CalculateCommand : public IAppCommand {
private:
    DisplayValue* displayValue;
    CalculatorFacade* calculatorFacade;
    ExceptionHandler* exceptionHandler;
    bool* isError;

    void setError(const std::string& text);

public:
    CalculateCommand(DisplayValue* displayValue, CalculatorFacade* calculatorFacade, ExceptionHandler* exceptionHandler, bool* isError);
    void execute() override;
};
