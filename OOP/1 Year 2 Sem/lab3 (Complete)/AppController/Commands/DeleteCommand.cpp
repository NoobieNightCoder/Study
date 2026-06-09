#include "DeleteCommand.h"

DeleteCommand::DeleteCommand(DisplayValue* displayValue) : displayValue(displayValue) {}

void DeleteCommand::execute() {
    displayValue->removeLastToken();
}
