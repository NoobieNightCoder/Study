#include "Tan.h"
#include "../Exceptions/AppException.h"
#include <cmath>

using namespace std;

string Tan::operationName() const {
    string result = "tg";
    return result;
}

int Tan::priority() const {
    int result = 3;
    return result;
}

int Tan::argsCount() const {
    int result = 1;
    return result;
}

double Tan::execute(const vector<double>& args) const {
    if(cos(args[0]) == 0) throw InputException(InputException::Messages::NonExistFuncton);
    double result = tan(args[0]);
    return result;
}
