#pragma once
#include "IAppCommand.h"

class MemoryClearCommand : public IAppCommand {
private:
    double* memoryValue;

public:
    explicit MemoryClearCommand(double* memoryValue);
    void execute() override;
};
