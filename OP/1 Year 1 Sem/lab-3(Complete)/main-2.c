#include <stdio.h>
#include <math.h>

#define INPUT_REQ 3

typedef enum {
    OK,
    ERROR
} programmCodes;

int input(double* startX, double* endX, double* eps) {
    int result = scanf("%lf %lf %lf", startX, endX, eps);
    return result;
}

int check(int inputResult, double startX, double endX, double eps) {
    programmCodes result = OK;

    if(inputResult != INPUT_REQ || eps <= 0 || eps > 1 || startX <= 0)
        result = ERROR;

    return result;
}

double function(double x) {
    return log(x);
}

double calculation(double startX, double endX, int iterations) {
    double rectWidth = (endX - startX) / iterations;
    double result = 0.0;
    
    for(int iteration = 1; iteration <= iterations; iteration++) {
        double x = startX + (iteration * rectWidth);
        result += function(x);
    }

    return result * rectWidth;
}

void mainFunction(double startX, double endX, double eps) {
	int iteration = 1;
    double previousResult = calculation(startX, endX, iteration);

    iteration *= 2;

    double currentResult = calculation(startX, endX, iteration);

    while (fabs(currentResult - previousResult) >= eps) {
        previousResult = currentResult;
        iteration *= 2;
        currentResult = calculation(startX, endX, iteration);
    }

    printf("%.6lf", currentResult);
}

int main() {
    double startX, endX;
    double eps;

    int inputResult = input(&startX, &endX, &eps);
    programmCodes checkResult = check(inputResult, startX, endX, eps);

    if(checkResult == OK)
        mainFunction(startX, endX, eps);
    else
        printf("Incorrect input");
        
    return checkResult;
}