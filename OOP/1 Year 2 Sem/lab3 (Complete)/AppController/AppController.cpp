#include "AppController.h"
#include "Commands/EnterTokenCommand.h"

using namespace std;

AppController::AppController():
    isError(false),
    isResult(false),
    memoryValue(0),
    clearCommand(&displayValue, &isError),
    deleteCommand(&displayValue),
    calculateCommand(&displayValue, &calculatorFacade, &exceptionHandler, &isError),
    memoryClearCommand(&memoryValue),
    memoryRecallCommand(&displayValue, &calculatorFacade, &memoryValue),
    memoryPlusCommand(&displayValue, &calculatorFacade, &exceptionHandler, &isError, &memoryValue),
    memoryMinusCommand(&displayValue, &calculatorFacade, &exceptionHandler, &isError, &memoryValue),
    functionCommand(&displayValue)
{
    fillCommandMap();
}

void AppController::fillCommandMap() {
    commandMap["Del"] = &deleteCommand;
    commandMap["C"] = &clearCommand;
    commandMap["="] = &calculateCommand;
    commandMap["MC"] = &memoryClearCommand;
    commandMap["MR"] = &memoryRecallCommand;
    commandMap["M+"] = &memoryPlusCommand;
    commandMap["M-"] = &memoryMinusCommand;
    commandMap["1/x"] = &functionCommand;
}

bool AppController::isCommand(const string& token) const {
    bool result = commandMap.find(token) != commandMap.end();
    return result;
}

void AppController::enterToken(const string& token) {
    bool canProcess = !isError;
    if(canProcess) {
        isResult = false;
        EnterTokenCommand enterTokenCommand(&displayValue, token);
        enterTokenCommand.execute();
    }
}

void AppController::enterFunction(const string& token) {
    bool canProcess = !isError;
    if(canProcess) {
        isResult = false;
        EnterTokenCommand enterTokenCommand(&displayValue, token + "(");
        enterTokenCommand.execute();
    }
}

void AppController::executeCommand(const string& token) {
    bool command = isCommand(token);
    bool errorReset = isError && token == "C";
    bool resetAfterCalc = isResult && token == "Del";
    bool canProcess = !isError && command;

    if(errorReset) clearCommand.execute();
    else if(resetAfterCalc && !isError) clearCommand.execute();

    if(canProcess) {
        commandMap[token]->execute();
        if(token == "=")
            isResult = true;
    }
}

string AppController::text() const {
    string result = displayValue.text();
    return result;
}
