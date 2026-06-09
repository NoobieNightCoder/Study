#pragma once
#include "Commands/CalculateCommand.h"
#include "Commands/ClearCommand.h"
#include "Commands/DeleteCommand.h"
#include "Commands/IAppCommand.h"
#include "Commands/MemoryClearCommand.h"
#include "Commands/MemoryMinusCommand.h"
#include "Commands/MemoryPlusCommand.h"
#include "Commands/MemoryRecallCommand.h"
#include "Commands/FuncCommand.h"
#include "../GUI/DisplayValue.h"
#include "../BL/Exceptions/ExceptionHandler.h"
#include "../BL/CalculatorFacade.h"
#include <map>
#include <string>

class AppController {
private:
    CalculatorFacade calculatorFacade;
    ExceptionHandler exceptionHandler;
    DisplayValue displayValue;
    bool isError;
    bool isResult;
    double memoryValue;
    ClearCommand clearCommand;
    DeleteCommand deleteCommand;
    CalculateCommand calculateCommand;
    MemoryClearCommand memoryClearCommand;
    MemoryRecallCommand memoryRecallCommand;
    MemoryPlusCommand memoryPlusCommand;
    MemoryMinusCommand memoryMinusCommand;
    FuncCommand functionCommand;
    std::map<std::string, IAppCommand*> commandMap;

    bool isCommand(const std::string& token) const;
    void fillCommandMap();

public:
    AppController();
    void enterToken(const std::string& token);
    void enterFunction(const std::string& token);
    void executeCommand(const std::string& token);
    std::string text() const;
};
