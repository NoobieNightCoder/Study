#pragma once
#include "IAppCommand.h"
#include "../../GUI/DisplayValue.h"

class ClearCommand : public IAppCommand {
private:
    DisplayValue* displayValue;
    bool* isError;

public:
    ClearCommand(DisplayValue* displayValue, bool* isError);
    void execute() override;
};
