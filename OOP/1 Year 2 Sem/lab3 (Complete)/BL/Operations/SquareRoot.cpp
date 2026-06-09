#include "SquareRoot.h"
#include "../Exceptions/AppException.h"
#include <cmath>

using namespace std;

string Sqrt::operationName() const {
    string result = "sqrt";
    return result;
}

int Sqrt::priority() const {
    int result = 3;
    return result;
}

int Sqrt::argsCount() const {
    int result = 1;
    return result;
}

double Sqrt::execute(const vector<double>& args) const {
    if(args[0] < 0) throw InputException(InputException::Messages::SqrtOfNegativeNum);
    double result = sqrt(args[0]);
    return result;
}
