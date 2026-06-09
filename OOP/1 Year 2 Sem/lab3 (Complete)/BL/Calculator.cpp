#include "Calculator.h"
#include "Exceptions/AppException.h"

using namespace std;

void Calculator::setProblem(const string& value) {
    problem = value;
}

bool Calculator::isNumberToken(char token) const {
    bool result = nums.find(token) != -1;
    return result;
}

bool Calculator::isOperationToken(const string& token) const {
    bool result = operations.find(token) != -1;
    return result;
}

bool Calculator::isWordToken(char token) const {
    bool result = isalpha(token);
    return result;
}

bool Calculator::isWrongToken(char token, bool numberToken, bool operationToken, bool unaryMinusToken, bool wordToken) const {
    bool result = !numberToken && !operationToken && !unaryMinusToken && !wordToken && !isspace(token);
    return result;
}

bool Calculator::isUnaryMinusBeforeExpression(bool unaryMinusToken, char nextToken) const {
    bool result = unaryMinusToken && (nextToken == '(' || isWordToken(nextToken));
    return result;
}

void Calculator::processToken(CalculationContext& context, char token, char nextToken) const {
    string tokenText(1, token);
    bool numberToken = isNumberToken(token);
    bool operationToken = isOperationToken(tokenText);
    bool unaryMinusToken = context.isUnaryMinusToken(token);
    bool wordToken = isWordToken(token);
    bool unaryMinusBeforeExpression = isUnaryMinusBeforeExpression(unaryMinusToken, nextToken);

    if(numberToken || (unaryMinusToken && !unaryMinusBeforeExpression)) context.appendNumberToken(token);
    if(unaryMinusBeforeExpression) context.processUnaryMinusBeforeExpression(operationRepository);
    if(operationToken && !unaryMinusToken) {
        context.pushCurrentNumber();
        context.processOperation(operationRepository, tokenText);
    }
    if(isWrongToken(token, numberToken, operationToken, unaryMinusToken, wordToken)) throw InputException(InputException::Messages::InvalidInput);
}

string Calculator::readWord(int& index) const {
    string result = "";

    while(index < problem.size() && isWordToken(problem[index])) {
        result.push_back(problem[index]);
        index++;
    }

    index--;
    return result;
}

void Calculator::processWord(CalculationContext& context, const string& token) const {
    bool operationExists = operationRepository.hasOperation(token);
    if(operationExists) context.processOperation(operationRepository, token);
    if(!operationExists) throw InputException(InputException::Messages::InvalidInput);
}

double Calculator::calculateProblem() {
    CalculationContext context;

    int index = 0;
    while(index < problem.size()) {
        char nextToken = '\0';
        if(index + 1 < problem.size()) nextToken = problem[index + 1];
        bool wordToken = isWordToken(problem[index]);
        if(wordToken) processWord(context, readWord(index));
        if(!wordToken) processToken(context, problem[index], nextToken);
        index++;
    }

    context.pushCurrentNumber();
    context.executeOperationStack(operationRepository);

    double result = context.result();
    return result;
}
