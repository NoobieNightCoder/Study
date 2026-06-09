#pragma once
#include "IAppCommand.h"
#include "../../GUI/DisplayValue.h"

class DeleteCommand : public IAppCommand {
private:
    DisplayValue* displayValue;

public:
    explicit DeleteCommand(DisplayValue* displayValue);
    void execute() override;
};
