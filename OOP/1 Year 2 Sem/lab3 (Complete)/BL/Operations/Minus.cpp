#include "Minus.h"

using namespace std;

string Minus::operationName() const {
    string result = "-";
    return result;
}

int Minus::priority() const {
    int result = 1;
    return result;
}

int Minus::argsCount() const {
    int result = 2;
    return result;
}

double Minus::execute(const vector<double>& args) const {
    double result = args[0] - args[1];
    return result;
}
