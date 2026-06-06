#pragma once
#include "IOperation.h"
#include <string>
#include <vector>

class Sin : public IOperation {
public:
    std::string operationName() const override;
    int priority() const override;
    int argsCount() const override;
    double execute(const std::vector<double>& args) const override;
};
