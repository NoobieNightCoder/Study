#include "Division.h"
#include "../Exceptions/AppException.h"

using namespace std;

string Division::operationName() const {
    string result = "/";
    return result;
}

int Division::priority() const {
    int result = 2;
    return result;
}

int Division::argsCount() const {
    int result = 2;
    return result;
}

double Division::execute(const vector<double>& args) const {
    double result = 0;
    if(args[1] == 0) throw InputException(InputException::Messages::DivisionByZero);
    result = args[0] / args[1];
    return result;
}
