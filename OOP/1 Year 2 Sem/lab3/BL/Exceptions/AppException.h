#pragma once
#include <exception>
#include <string>

class AppException : public std::exception {
private:
    const std::string message;

public:
    explicit AppException(const std::string& msg);
    const char* what() const noexcept override;
};

class InputException : public AppException {
public:
    using AppException::AppException;
    bool isDivisionByZero() const;
    bool isFunctionExist() const;
    bool isSqrtOfNegativeNum() const;

    struct Messages {
        static const std::string InvalidInput;
        static const std::string DivisionByZero;
        static const std::string NonExistFuncton;
        static const std::string SqrtOfNegativeNum;
    };
};
