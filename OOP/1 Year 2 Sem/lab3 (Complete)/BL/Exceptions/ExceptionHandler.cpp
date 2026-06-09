#include "ExceptionHandler.h"

using namespace std;

string ExceptionHandler::wrongInputText() const {
    string result = "Некорректный ввод";
    return result;
}

string ExceptionHandler::divisionByZeroText() const {
    string result = "Деление на ноль";
    return result;
}

string ExceptionHandler::nonExistFunctionText() const {
    string result = "Функция в заданной точке не существует";
    return result;
}

string ExceptionHandler::sqrtOfNegativeNum() const {
    string result = "Корень отрицательного числа не существует";
    return result;
}

string ExceptionHandler::handle(const InputException& exception) {
    string result = wrongInputText();
    if(exception.isDivisionByZero()) result = divisionByZeroText();
    if(exception.isFunctionExist()) result = nonExistFunctionText();
    if(exception.isSqrtOfNegativeNum()) result = sqrtOfNegativeNum();
    return result;
}

string ExceptionHandler::handle(const AppException&) {
    string result = wrongInputText();
    return result;
}

string ExceptionHandler::handleUnknown() {
    string result = wrongInputText();
    return result;
}
