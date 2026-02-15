#include <stdio.h>
#include <stdlib.h>
#include "arrayTools.h"

#define SORT_STEP 2
#define REQ_INPUT 2

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} statusCodes;

// Для сортировки по возрастанию
int ascending(int a, int b)  {
    return a < b;
}

// Для сортировки по убыванию
int descending(int a, int b) {
    return a > b;
}

int numInput(int* number) {
    int result = scanf("%d", number);
    return result;
}

void matrixPrintArray(int height, int width, int* numArray) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%d ", numArray[(i * width) + j]);
        }
        printf("\n");
    }
}

statusCodes createArray(int** numArray, int arraySize) {
    statusCodes programmStatus = OK;
    if(programmStatus == OK) {
        *numArray = allocateArray(arraySize, sizeof(int));
        if(!*numArray)
            programmStatus = MEMORY_ERROR;
    }

    if(programmStatus == OK) {
        int arrayInputResult = inputArray(arraySize, *numArray);
        if(arrayInputResult)
            programmStatus = INPUT_ERROR;
    }
    return programmStatus;
}

void snakeSort(int arrayHeight, int arrayWidth, int* numArray) {
    sortArray(0, arrayHeight * arrayWidth, numArray, descending);
    for(int line = arrayHeight - SORT_STEP; line >= 0; line -= SORT_STEP) {
        int start = line * arrayWidth;
        sortArray(start, start + arrayWidth, numArray, ascending);
    }
}

void output(statusCodes code, int arrayHeight, int arrayWidth, int* numArray) {
    if(code == OK) matrixPrintArray(arrayHeight, arrayWidth, numArray);
    else if(code == MEMORY_ERROR) printf("Memory Error");
    else if(code == INPUT_ERROR) printf("Incorrect input");
}

int main() {
    statusCodes programmStatus = OK;
    int arrayHeight = 0, arrayWidth = 0, arraySize = 0;
    int *numArray = NULL;

    int sizeInputResult = numInput(&arrayHeight) + numInput(&arrayWidth);
    arraySize = arrayHeight * arrayWidth;

    if(sizeInputResult != REQ_INPUT || arraySize <= 0)
        programmStatus = INPUT_ERROR;
    else
        programmStatus = createArray(&numArray, arraySize);
    
    
    if(programmStatus == OK)
        snakeSort(arrayHeight, arrayWidth, numArray);
    
    output(programmStatus, arrayHeight, arrayWidth, numArray);
    freeArray(numArray);

    return programmStatus;
}