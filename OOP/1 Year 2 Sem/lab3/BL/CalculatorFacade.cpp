#include "CalculatorFacade.h"
#include <sstream>
#include <iomanip>

#define NUM_PRESICION 10

using namespace std;

string CalculatorFacade::formatResult(double value) const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(NUM_PRESICION) << value;
    string result = oss.str();
    result = trimResult(result);
    return result;
}

string CalculatorFacade::trimResult(string value) const {
    while(value.find('.') != -1 && value.back() == '0') {
        value.pop_back();
    }

    if(value.back() == '.') value.pop_back();
    if(value == "-0") value = "0";

    string result = value;
    return result;
}

string CalculatorFacade::calculate(const string& problem) {
    calculator.setProblem(problem);
    string result = formatResult(calculator.calculateProblem());
    return result;
}

string CalculatorFacade::valueText(double value) const {
    string result = formatResult(value);
    return result;
}
