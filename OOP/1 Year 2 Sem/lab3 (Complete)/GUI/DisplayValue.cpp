#include "DisplayValue.h"

using namespace std;

DisplayValue::DisplayValue() : value("0") {}

bool DisplayValue::isMathOperation(const QString& token) const {
    bool result = mathOperations.contains(token);
    return result;
}

bool DisplayValue::isLastMathOperation() const {
    bool result = !value.isEmpty() && isMathOperation(value.right(1));
    return result;
}

bool DisplayValue::canAppendToken(const QString& token) const {
    bool result = token != "." || !currentNumber().contains(".");
    return result;
}

QString DisplayValue::currentNumber() const {
    int index = value.size() - 1;
    while(index >= 0 && !isMathOperation(value.mid(index, 1))) {
        index--;
    }

    QString result = value.mid(index + 1);
    return result;
}

void DisplayValue::appendToken(const string& token) {
    QString tokenText = QString::fromStdString(token);
    bool needClearZero = value == "0" && token != ".";
    bool needReplaceOperation = isMathOperation(tokenText) && isLastMathOperation();
    bool canAppend = canAppendToken(tokenText);

    if(needClearZero) value = "";
    if(needReplaceOperation) value.chop(1);

    if(canAppend) value += tokenText;
}

void DisplayValue::removeLastToken() {
    if(value != "0") value.chop(1);
    if(value.isEmpty()) value = "0";
}

void DisplayValue::clear() {
    value = "0";
}

void DisplayValue::setText(const string& text) {
    value = QString::fromStdString(text);
}

string DisplayValue::text() const {
    string result = value.toStdString();
    return result;
}
