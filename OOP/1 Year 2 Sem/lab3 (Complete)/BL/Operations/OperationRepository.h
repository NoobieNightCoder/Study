#pragma once
#include "Operations.h"
#include <map>
#include <string>

class OperationRepository {
private:
    Plus plus;
    Minus minus;
    Multiplie multiplie;
    Division division;
    Sin sinus;
    Cos cosinus;
    Tan tangens;
    Cotan cotangens;
    Sqrt squareRoot;
    std::map<std::string, IOperation*> operations;

    void fillOperations();

public:
    OperationRepository();
    IOperation* operation(const std::string& operationName) const;
    bool hasOperation(const std::string& operationName) const;
    bool isFunction(const std::string& operationName) const;
    int priority(const std::string& operationName) const;
};
