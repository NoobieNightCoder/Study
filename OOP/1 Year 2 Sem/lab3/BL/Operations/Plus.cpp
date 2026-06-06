#include "Plus.h"

using namespace std;

string Plus::operationName() const {
    string result = "+";
    return result;
}

int Plus::priority() const {
    int result = 1;
    return result;
}

int Plus::argsCount() const {
    int result = 2;
    return result;
}

double Plus::execute(const vector<double>& args) const {
    double result = args[0] + args[1];
    return result;
}
