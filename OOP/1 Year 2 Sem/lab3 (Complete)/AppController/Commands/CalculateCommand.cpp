#include "CalculateCommand.h"

using namespace std;

CalculateCommand::CalculateCommand(DisplayValue* displayValue, CalculatorFacade* calculatorFacade, ExceptionHandler* exceptionHandler, bool* isError):
    displayValue(displayValue),
    calculatorFacade(calculatorFacade),
    exceptionHandler(exceptionHandler),
    isError(isError) {}

void CalculateCommand::setError(const string& text) {
    *isError = true;
    displayValue->setText(text);
}

void CalculateCommand::execute() {
    try {
        displayValue->setText(calculatorFacade->calculate(displayValue->text()));
    } catch(const InputException& exception) {
        setError(exceptionHandler->handle(exception));
    } catch(const AppException& exception) {
        setError(exceptionHandler->handle(exception));
    } catch(...) {
        setError(exceptionHandler->handleUnknown());
    }
}
