#include "FuncCommand.h"

using namespace std;

FuncCommand::FuncCommand(DisplayValue* displayValue) : displayValue(displayValue) {}

void FuncCommand::execute() {
    string result = "1/(" + displayValue->text() + ")";
    displayValue->setText(result);
}
