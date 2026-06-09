#include "Cos.h"
#include <cmath>

using namespace std;

string Cos::operationName() const {
    string result = "cos";
    return result;
}

int Cos::priority() const {
    int result = 3;
    return result;
}

int Cos::argsCount() const {
    int result = 1;
    return result;
}

double Cos::execute(const vector<double>& args) const {
    double result = cos(args[0]);
    return result;
}
