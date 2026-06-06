#include "MemoryPlusCommand.h"

using namespace std;

MemoryPlusCommand::MemoryPlusCommand(DisplayValue* displayValue, CalculatorFacade* calculatorFacade, ExceptionHandler* exceptionHandler, bool* isError, double* memoryValue):
    displayValue(displayValue),
    calculatorFacade(calculatorFacade),
    exceptionHandler(exceptionHandler),
    isError(isError),
    memoryValue(memoryValue) {}

void MemoryPlusCommand::setError(const string& text) {
    *isError = true;
    displayValue->setText(text);
}

void MemoryPlusCommand::execute() {
    try {
        string value = calculatorFacade->calculate(displayValue->text());
        *memoryValue += stod(value);
    } catch(const InputException& exception) {
        setError(exceptionHandler->handle(exception));
    } catch(const AppException& exception) {
        setError(exceptionHandler->handle(exception));
    } catch(...) {
        setError(exceptionHandler->handleUnknown());
    }
}
