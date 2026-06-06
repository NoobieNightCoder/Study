#include "OperationRepository.h"

using namespace std;

OperationRepository::OperationRepository() {
    fillOperations();
}

void OperationRepository::fillOperations() {
    operations[plus.operationName()] = &plus;
    operations[minus.operationName()] = &minus;
    operations[multiplie.operationName()] = &multiplie;
    operations[division.operationName()] = &division;
    operations[sinus.operationName()] = &sinus;
    operations[cosinus.operationName()] = &cosinus;
    operations[tangens.operationName()] = &tangens;
    operations[cotangens.operationName()] = &cotangens;
    operations[squareRoot.operationName()] = &squareRoot;
}

IOperation* OperationRepository::operation(const string& operationName) const {
    auto it = operations.find(operationName);
    IOperation* result = (it != operations.end()) ? it->second : nullptr;

    return result;
}

bool OperationRepository::hasOperation(const string& operationName) const {
    bool result = operations.find(operationName) != operations.end();
    return result;
}

bool OperationRepository::isFunction(const string& operationName) const {
    IOperation* currentOperation = operation(operationName);
    bool result = currentOperation != nullptr && currentOperation->argsCount() == 1;
    return result;
}

int OperationRepository::priority(const string& operationName) const {
    IOperation* currentOperation = operation(operationName);
    int result = 0;
    if(currentOperation != nullptr) result = currentOperation->priority();
    return result;
}
