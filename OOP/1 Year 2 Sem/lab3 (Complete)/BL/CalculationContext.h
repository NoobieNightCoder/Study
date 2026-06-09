#pragma once
#include "Operations/OperationRepository.h"
#include <string>
#include <vector>

class CalculationContext {
private:
    std::vector<double> calcStack;
    std::vector<std::string> opStack;
    std::string currentNum;
    bool valueExpected;

    void executeOperation(const OperationRepository& operationRepository, const std::string& op);
    void processBracket(const OperationRepository& operationRepository);
    void processBinaryOperation(const OperationRepository& operationRepository, const std::string& op);
    void processFunctionOperation(const std::string& op);

public:
    CalculationContext();
    bool isUnaryMinusToken(char token) const;
    void appendNumberToken(char token);
    void pushCurrentNumber();
    void processUnaryMinusBeforeExpression(const OperationRepository& operationRepository);
    void processOperation(const OperationRepository& operationRepository, const std::string& op);
    void executeOperationStack(const OperationRepository& operationRepository);
    double result() const;
};
