#pragma once
#include <string>
#include <iostream>

#define ADD_TEST(f) { #f, f }

inline void report(const std::string& testName, bool passed) {
    std::cout << "[ " << (passed ? " OK " : "FAIL") << " ] " << testName << "()" << std::endl;
}