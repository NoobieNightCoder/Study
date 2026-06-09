#include "CalculationContext.h"
#include "Exceptions/AppException.h"

using namespace std;

CalculationContext::CalculationContext() : valueExpected(true) {}

bool CalculationContext::isUnaryMinusToken(char token) const {
    bool result = token == '-' && valueExpected && currentNum.empty();
    return result;
}

void CalculationContext::appendNumberToken(char token) {
    currentNum.push_back(token);
    valueExpected = false;
}

void CalculationContext::pushCurrentNumber() {
    if(!currentNum.empty()) {
        if(currentNum == "-") throw InputException(InputException::Messages::InvalidInput);
        
        try {
            double number = stod(currentNum);
            calcStack.push_back(number);
            currentNum = "";
        } catch(...) {
            throw InputException(InputException::Messages::InvalidInput);
        }
    }
}

void CalculationContext::executeOperation(const OperationRepository& operationRepository, const string& op) {
    IOperation* operation = operationRepository.operation(op);
    if(operation == nullptr)
        throw InputException(InputException::Messages::InvalidInput);
    if(calcStack.size() < operation->argsCount())
        throw InputException(InputException::Messages::InvalidInput);

    vector<double> args;
    int firstArgIndex = calcStack.size() - operation->argsCount();
    int index = firstArgIndex;
    while(index < calcStack.size()) {
        args.push_back(calcStack[index]);
        index++;
    }

    int removedCount = 0;
    while(removedCount < operation->argsCount()) {
        calcStack.pop_back();
        removedCount++;
    }

    calcStack.push_back(operation->execute(args));
    valueExpected = false;
}

void CalculationContext::processBracket(const OperationRepository& operationRepository) {
    while(!opStack.empty() && opStack.back() != "(") {
        executeOperation(operationRepository, opStack.back());
        opStack.pop_back();
    }

    bool bracketFound = !opStack.empty() && opStack.back() == "(";
    if(bracketFound) opStack.pop_back();
    if(!bracketFound) throw InputException(InputException::Messages::InvalidInput);
    if(!opStack.empty() && operationRepository.isFunction(opStack.back())) {
        executeOperation(operationRepository, opStack.back());
        opStack.pop_back();
    }
    valueExpected = false;
}

void CalculationContext::processBinaryOperation(const OperationRepository& operationRepository, const string& op) {
    while(!opStack.empty() && opStack.back() != "(" && operationRepository.priority(opStack.back()) >= operationRepository.priority(op)) {
        executeOperation(operationRepository, opStack.back());
        opStack.pop_back();
    }

    opStack.push_back(op);
    valueExpected = true;
}

void CalculationContext::processFunctionOperation(const string& op) {
    opStack.push_back(op);
    valueExpected = true;
}

void CalculationContext::processUnaryMinusBeforeExpression(const OperationRepository& operationRepository) {
    calcStack.push_back(-1);
    processBinaryOperation(operationRepository, "*");
}

void CalculationContext::processOperation(const OperationRepository& operationRepository, const string& op) {
    bool functionOperation = operationRepository.isFunction(op);
    if(op == "(") {
        opStack.push_back(op);
        valueExpected = true;
    }
    if(op == ")") processBracket(operationRepository);
    if(functionOperation) processFunctionOperation(op);
    if(operationRepository.hasOperation(op) && !functionOperation) processBinaryOperation(operationRepository, op);
}

void CalculationContext::executeOperationStack(const OperationRepository& operationRepository) {
    while(!opStack.empty()) {
        if(opStack.back() == "(") throw InputException(InputException::Messages::InvalidInput);
        executeOperation(operationRepository, opStack.back());
        opStack.pop_back();
    }
}

double CalculationContext::result() const {
    bool resultExists = calcStack.size() == 1;
    double result = 0;
    if(resultExists) result = calcStack.back();
    if(!resultExists) throw InputException(InputException::Messages::InvalidInput);
    return result;
}
