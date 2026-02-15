#include <stdio.h>
#include <math.h>

#define REQ_INPUT 2
#define EPS       0.000001

typedef enum {
    INPUT_ERROR = 0,
    ABOVE   = 1,
    ON      = 2,
    UNDER   = 3
} lineCodes;

typedef enum {
    OK = 0,
    PROGRAMM_ERROR = 1
} programmCodes;

int input(float* x, float* y) {
    printf("Line equation: y = 0.5x + 1\nPlease insert coordinates of the point: ");

    int result = scanf("%f %f", x, y);
    return result;
}

int check(float dotX, float dotY) {  
    lineCodes result;  

    float lineY = (0.5 * dotX) + 1;

    if(dotY > lineY + EPS) result = ABOVE;
    else if(fabs(lineY - dotY) <= EPS) result = ON;
    else result = UNDER;
    
    return result;
}

void output(lineCodes statusCode) {
    if(statusCode == INPUT_ERROR)
        printf("Result: Incorrect input");
    else if(statusCode == ABOVE)
        printf("Point is above the line");
    else if(statusCode == ON)
        printf("Point is on the line");
    else if(statusCode == UNDER)
        printf("Point is under the line");
}

int main() {
    float x, y;
    int inputStatus;
    programmCodes endProgramm = OK;
    lineCodes statusCode;

    inputStatus = input(&x, &y);

    if(inputStatus != REQ_INPUT) {
        statusCode = INPUT_ERROR;
        endProgramm = PROGRAMM_ERROR;
    } else {
        statusCode = check(x, y);
    }

    output(statusCode);
    return endProgramm;
}