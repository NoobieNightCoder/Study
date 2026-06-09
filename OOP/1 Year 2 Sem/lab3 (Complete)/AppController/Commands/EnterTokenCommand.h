#pragma once
#include "IAppCommand.h"
#include "../../GUI/DisplayValue.h"
#include <string>

class EnterTokenCommand : public IAppCommand {
private:
    DisplayValue* displayValue;
    std::string token;

public:
    EnterTokenCommand(DisplayValue* displayValue, const std::string& token);
    void execute() override;
};
