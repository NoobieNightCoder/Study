#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR,
    SIZE_ERROR
} statusCodes;

void* createArray(int size, int byteSize) {
    return calloc(size, byteSize);
}

void arrayFree(void* array) {
    free(array);
}

int sizeCheck(int arraySize) {
    int result = (arraySize > 0);
    return result;
}

int numInput(double* number) {
    int result = scanf("%lf", number);
    return result;
}

int sizeInput(int* number) {
    int result = scanf("%d", number);
    return result;
}

int arrayInput(int arraySize, double* numArray) {
    int result = OK;
    for (int index = 0; index < arraySize && result == OK; index++) {
        int inputResult = numInput(numArray + index);
        if(!inputResult) result = INPUT_ERROR;
    }
    return result;
}

int lastZeroIndex(int arraySize, double* numArray) {
    int lastZero = -1;
    for (int index = 0; index < arraySize; index++) {
        if (numArray[index] == 0) lastZero = index;
    }
    return lastZero;
}

int firstMaxNumIndex(int arraySize, double* numArray) {
    int maxIndex = 0;
    for (int index = 1; index < arraySize; index++)
        if (numArray[index] > numArray[maxIndex])
            maxIndex = index;
    return maxIndex;
}

double avgCalc(double* numArray, int lastZero, int maxIndex) {
    double avg = 0;
    double sum = 0;

    if(lastZero != -1) {
        if(lastZero > maxIndex) {
            int buffer = lastZero;
            lastZero = maxIndex;
            maxIndex = buffer;
        }
        if(lastZero != maxIndex) {
            for (int index = lastZero; index <= maxIndex; index++)
                sum += numArray[index];
            avg = sum / fabs(maxIndex - lastZero);
        }
    }
    return avg;
}

double computeAverageBetweenZeroAndMax(int arraySize, double* numArray) {
    int lastZero = lastZeroIndex(arraySize, numArray);
    int maxIndex = firstMaxNumIndex(arraySize, numArray);
    double avg = avgCalc(numArray, lastZero, maxIndex);
    return avg;
}

void output(statusCodes code, double avg) {
    if(code == INPUT_ERROR || code == SIZE_ERROR)
        printf("Incorrect input");
    else if(code == MEMORY_ERROR) 
        printf("Memory error");
    else printf("%lg", avg);
}

int main() {
    int arraySize = 0;
    double avg;
    statusCodes programmStatus = OK;
    
    int inputResult = sizeInput(&arraySize);
    int checkResult;

    if(inputResult)
        checkResult = sizeCheck(arraySize);
    else
        programmStatus = INPUT_ERROR;
    
    if(programmStatus == OK && !checkResult)
        programmStatus = SIZE_ERROR;

    double *numArray = NULL;
    
    if(programmStatus == OK) {
        numArray = createArray(arraySize, sizeof(double));
        if(!numArray)
            programmStatus = MEMORY_ERROR;
    }

    if(programmStatus == OK) {
        int arrayInputResult = arrayInput(arraySize, numArray);
        if(arrayInputResult)
            programmStatus = INPUT_ERROR;
    }
    
    if(programmStatus == OK)
        avg = computeAverageBetweenZeroAndMax(arraySize, numArray);

    output(programmStatus, avg);
    arrayFree(numArray);
    return programmStatus;
}
