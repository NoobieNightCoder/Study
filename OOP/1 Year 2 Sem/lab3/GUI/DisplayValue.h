#pragma once
#include <QString>
#include <string>

class DisplayValue {
private:
    QString value;
    const QString mathOperations = "+-/*";

    bool isMathOperation(const QString& token) const;
    bool isLastMathOperation() const;
    bool canAppendToken(const QString& token) const;
    QString currentNumber() const;

public:
    DisplayValue();
    void appendToken(const std::string& token);
    void removeLastToken();
    void clear();
    void setText(const std::string& text);
    std::string text() const;
};
