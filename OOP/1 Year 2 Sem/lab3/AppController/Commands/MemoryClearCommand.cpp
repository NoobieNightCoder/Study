#include "MemoryClearCommand.h"

MemoryClearCommand::MemoryClearCommand(double* memoryValue) : memoryValue(memoryValue) {}

void MemoryClearCommand::execute() {
    *memoryValue = 0;
}
