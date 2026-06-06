#include "Cotan.h"
#include "../Exceptions/AppException.h"
#include <cmath>

using namespace std;

string Cotan::operationName() const {
    string result = "ctg";
    return result;
}

int Cotan::priority() const {
    int result = 3;
    return result;
}

int Cotan::argsCount() const {
    int result = 1;
    return result;
}

double Cotan::execute(const vector<double>& args) const {
    if(cos(args[0]) == 0 || sin(args[0]) == 0) throw InputException(InputException::Messages::NonExistFuncton);
    double result = 1 / tan(args[0]);
    return result;
}
