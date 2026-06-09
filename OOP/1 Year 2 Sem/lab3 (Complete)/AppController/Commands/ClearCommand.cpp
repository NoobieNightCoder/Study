#include "ClearCommand.h"

ClearCommand::ClearCommand(DisplayValue* displayValue, bool* isError) : displayValue(displayValue), isError(isError) {}

void ClearCommand::execute() {
    *isError = false;
    displayValue->clear();
}
