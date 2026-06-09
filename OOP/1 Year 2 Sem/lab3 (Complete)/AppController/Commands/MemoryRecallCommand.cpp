#include "MemoryRecallCommand.h"

MemoryRecallCommand::MemoryRecallCommand(DisplayValue* displayValue, CalculatorFacade* calculatorFacade, double* memoryValue):
    displayValue(displayValue),
    calculatorFacade(calculatorFacade),
    memoryValue(memoryValue) {}

void MemoryRecallCommand::execute() {
    displayValue->setText(calculatorFacade->valueText(*memoryValue));
}
