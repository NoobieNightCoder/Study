#pragma once
#include <string>
#include <vector>

class IOperation {
public:
    virtual std::string operationName() const = 0;
    virtual int priority() const = 0;
    virtual int argsCount() const = 0;
    virtual double execute(const std::vector<double>& args) const = 0;

    virtual ~IOperation() = default;
};
