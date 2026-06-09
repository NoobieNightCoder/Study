#include "Multiplie.h"

using namespace std;

string Multiplie::operationName() const {
    string result = "*";
    return result;
}

int Multiplie::priority() const {
    int result = 2;
    return result;
}

int Multiplie::argsCount() const {
    int result = 2;
    return result;
}

double Multiplie::execute(const vector<double>& args) const {
    double result = args[0] * args[1];
    return result;
}
