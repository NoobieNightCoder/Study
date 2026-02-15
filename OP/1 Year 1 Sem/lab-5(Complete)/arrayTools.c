#include <stdio.h>
#include <stdlib.h>
#include "arrayTools.h"

typedef enum {
    OK,
    INPUT_ERROR
} statusCodes;

void* createArray(int size, int byteSize) {
    return calloc(size, byteSize);
}

void arrayFree(void* array) {
    free(array);
}

int sizeCheck(int arraySize) {
    int result = (arraySize >= 0);
    return result;
}

int numInput(int* number) {
    int result = scanf("%d", number);
    return result;
}

int arrayInput(int arraySize, int* numArray) {
    int result = OK;
    for (int index = 0; index < arraySize && result == OK; index++) {
        int inputResult = numInput(numArray + index);
        if(!inputResult) result = INPUT_ERROR;
    }
    return result;
}

void swapElements(int* numArray, int indexA, int indexB) {
    int temp = numArray[indexA];
    numArray[indexA] = numArray[indexB];
    numArray[indexB] = temp;
}

void printArray(int arraySize, int* numArray) {
    for(int index = 0; index < arraySize; index++)
        printf("%d ", numArray[index]);
    printf("\n");
}