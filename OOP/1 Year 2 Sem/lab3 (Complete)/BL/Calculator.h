#pragma once
#include "CalculationContext.h"
#include "Operations/OperationRepository.h"
#include <string>

class Calculator {
private:
    std::string problem;
    const std::string nums = "0123456789.";
    const std::string operations = "+-/*()";
    OperationRepository operationRepository;

    bool isNumberToken(char token) const;
    bool isOperationToken(const std::string& token) const;
    bool isWordToken(char token) const;
    bool isWrongToken(char token, bool numberToken, bool operationToken, bool unaryMinusToken, bool wordToken) const;
    bool isUnaryMinusBeforeExpression(bool unaryMinusToken, char nextToken) const;
    std::string readWord(int& index) const;
    void processWord(CalculationContext& context, const std::string& token) const;
    void processToken(CalculationContext& context, char token, char nextToken) const;

public:
    void setProblem(const std::string& value);
    double calculateProblem();
};
