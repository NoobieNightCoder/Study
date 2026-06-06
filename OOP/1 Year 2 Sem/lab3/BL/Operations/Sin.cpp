#include "Sin.h"
#include <cmath>

using namespace std;

string Sin::operationName() const {
    string result = "sin";
    return result;
}

int Sin::priority() const {
    int result = 3;
    return result;
}

int Sin::argsCount() const {
    int result = 1;
    return result;
}

double Sin::execute(const vector<double>& args) const {
    double result = sin(args[0]);
    return result;
}
