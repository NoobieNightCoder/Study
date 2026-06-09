#pragma once
#include "IAppCommand.h"
#include "../../GUI/DisplayValue.h"

class FuncCommand : public IAppCommand {
private:
    DisplayValue* displayValue;

public:
    explicit FuncCommand(DisplayValue* displayValue);
    void execute() override;
};
