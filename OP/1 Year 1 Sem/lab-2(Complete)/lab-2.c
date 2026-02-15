#include <stdio.h>
#include <math.h>



typedef enum {
    REQ_INPUT = 3,
    REQ_ITERATIONS = 2
} Requirements;

typedef enum {
    OK,
    ERROR
} programmCodes;

int input(float* xFrom, float* xTo, int* iterations) {
    short result = scanf("%f %f %d", xFrom, xTo, iterations);
    return result;
}

void printX(float currentX) {
    printf("% 5.3f\t|", currentX);
}

void printY(float currentX) {
    float y = tan(currentX) * sqrt(currentX);
    if(isnan(y))
        printf("  nan\t|");
    else
        printf("% 5.3f\t|", y);
}

void functionFor(float xFrom, float xTo, int iterations) {
    float step = (xTo - xFrom) / (iterations - 1);
    float currentX = xFrom;
    printf("for:\nx\t|");

    for(int currIter = 0; currIter < iterations; currIter++) {
        printX(currentX);
        currentX += step;
    }

    printf("\nf(x)\t|");
    currentX = xFrom;
    for(int currIter = 0; currIter < iterations; currIter++) {
        printY(currentX);
        currentX += step;
    }
}

void functionWhile(float xFrom, float xTo, int iterations) {
    float step = (xTo - xFrom) / (iterations - 1);
    float currentX = xFrom;
    printf("while:\nx\t|");

    int currIter = 0;
    
    while(currIter < iterations) {
        printX(currentX);
        currentX += step;
        currIter++;
    }

    printf("\nf(x)\t|");

    currIter = 0;
    currentX = xFrom;
    while(currIter < iterations) {
        printY(currentX);
        currentX += step;
        currIter++;
    }
}

void functionDoWhile(float xFrom, float xTo, int iterations) {
    float step = (xTo - xFrom) / (iterations - 1);
    float currentX = xFrom;

    printf("do while:\nx\t|");

    int currIter = 0;
    do {
        printX(currentX);
        currentX += step;
        currIter++;
    } while(currIter < iterations);

    printf("\nf(x)\t|");

    currIter = 0;
    currentX = xFrom;
    do {
        printY(currentX);
        currentX += step;
        currIter++;
    } while(currIter < iterations);
}

int check(float xFrom, float xTo, int iterations, short inputStatus) {
    Requirements result = OK;
    if(inputStatus != REQ_INPUT || xFrom >= xTo || iterations < REQ_ITERATIONS)
        result = ERROR;
    
    return result;
}

int main() {
    float xFrom, xTo;
    int iterations;

    int inputResult = input(&xFrom, &xTo, &iterations);
    int checkResult = check(xFrom, xTo, iterations, inputResult);
    
    if(checkResult == ERROR) {
        printf("Incorrect input");
    } else {
        functionFor(xFrom, xTo, iterations);
        printf("\n\n");
        functionWhile(xFrom, xTo, iterations);
        printf("\n\n");
        functionDoWhile(xFrom, xTo, iterations);
    }
    return checkResult;
}
