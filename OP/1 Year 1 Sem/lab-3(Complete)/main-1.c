#include <stdio.h>
#include <math.h>

#define INPUT_REQ 1

typedef enum {
    OK,
    ERROR
} programmCodes;

int input(float* eps) {
    int result = scanf("%f", eps);
    return result;
}

int checkInput(int inputResult, float eps) {
    programmCodes result = OK;

    if(inputResult != INPUT_REQ || eps <= 0)
        result = ERROR;

    return result;
}

float calculation(float eps) {
    //                      A(n) = -A(n - 1) / n                    //
    float result = 1;

    float currNum = result;
    int iteration = 1;
    
    while(fabs(currNum) > eps) {
        currNum *= -1.0 / iteration;
        result += currNum;
        iteration++;
    }

    return result;
}

void mainFunction(float eps) {
	float sum = calculation(eps);
    printf("%.6g", sum);
}

int main() {
    float eps;

    int inputResult = input(&eps);
    programmCodes checkResult = checkInput(inputResult, eps);

    if(checkResult == OK)
    	mainFunction(eps);
    else
        printf("Incorrect input");

    return checkResult;
}