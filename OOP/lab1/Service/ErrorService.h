#pragma once

#include <string>
#include <exception>

class AppException : public std::exception {
private:
    std::string message;
public:
    explicit AppException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InputException : public AppException {
public:
    using AppException::AppException;

    struct Messages {
        static const std::string InvalidInput;
    };
};

class NotFoundException : public AppException {
public:
    using AppException::AppException;

    struct Messages {
        static const std::string noItem;
        static const std::string noID;
    };
};

class StateException : public AppException {
public:
    using AppException::AppException;

    struct Messages {
        static const std::string EmptyList;
    };
};

class ValidationException : public AppException {
public:
    using AppException::AppException;

    struct Messages {
        static const std::string InvalidName;
        static const std::string InvalidRadius;
        static const std::string InvalidShape;
        static const std::string InvalidThreshold;
    };
};