#include "EnterTokenCommand.h"

using namespace std;

EnterTokenCommand::EnterTokenCommand(DisplayValue* displayValue, const string& token) : displayValue(displayValue), token(token) {}

void EnterTokenCommand::execute() {
    displayValue->appendToken(token);
}
