#include "AppException.h"

using namespace std;

const string InputException::Messages::InvalidInput = "Invalid input";
const string InputException::Messages::DivisionByZero = "Division by zero";
const string InputException::Messages::NonExistFuncton = "Function does not exist at the given point";
const string InputException::Messages::SqrtOfNegativeNum = "Square root of negative number";

AppException::AppException(const std::string& msg) : message(msg) {}

const char* AppException::what() const noexcept {
    const char* result = message.c_str();
    return result;
}

bool InputException::isDivisionByZero() const {
    bool result = what() == Messages::DivisionByZero;
    return result;
}

bool InputException::isFunctionExist() const {
    bool result = what() == Messages::NonExistFuncton;
    return result;
}

bool InputException::isSqrtOfNegativeNum() const {
    bool result = what() == Messages::SqrtOfNegativeNum;
    return result;
}