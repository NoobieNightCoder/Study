#include <stdio.h>
#include <stdlib.h>
#include "arrayTools.h"

#define REQ_INPUT 2

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} statusCodes;

// GENERAL FUNCTIONS //

static int numInput(int* number) {
    int result = scanf("%d", number);
    return result;
}

void swapElements(int* elemA, int* elemB) {
    int temp = *elemA;
    *elemA = *elemB;
    *elemB = temp;
}

// ONE-DIM ARRAYS //
void freeArray(void* array) {
    free(array);
}

void* allocateArray(int arraySize, int byteSize) {
    return calloc(arraySize, byteSize);
}

int inputArray(int arraySize, int* numArray) {
    int result = OK;
    for (int index = 0; index < arraySize && result == OK; index++) {
        int inputResult = numInput(numArray + index);
        if(!inputResult) result = INPUT_ERROR;
    }
    return result;
}

int findMaxArray(int arraySize, int* numArray) {
    int maxIndex = 0;
    for(int index = 1; index < arraySize; index++)
        if(numArray[index] > numArray[maxIndex])
            maxIndex = index;
    
    return maxIndex;
}

int findMinArray(int arraySize, int* numArray) {
    int minIndex = 0;
    for(int index = 1; index < arraySize; index++)
        if(numArray[index] < numArray[minIndex])
            minIndex = index;
    
    return minIndex;
}

void sortArray(int startPos, int endPos, int* numArray, int(*compare)(int, int)) {
    for (int iteration = ++startPos; iteration < endPos; iteration++)
        for (int index = startPos; index < endPos; index++)
            if (compare(numArray[index], numArray[index - 1]))
                swapElements(numArray + index, numArray + index - 1);
}

void printArray(int arraySize, int* numArray) {
    for(int i = 0; i < arraySize; i++)
        printf("%d ", numArray[i]);
    printf("\n");
}

// TWO-DIM ARRAYS //
void freeMatrix(void** matrix, int height) {
    if(matrix)
        for (int line = 0; line < height; line++)
            freeArray(matrix[line]);
    freeArray(matrix);
}

void* allocateMatrix(int height, int width, int byteSize) {
    int flag = 1;
    void** matrix = calloc(height, sizeof(void*));
    for (int line = 0; line < height && matrix && flag; line++) {
        matrix[line] = allocateArray(width, byteSize);
        if(!matrix[line])
            flag = 0;
    }
    if(!flag)
        freeMatrix(matrix, height);
    return matrix;
}

int inputMatrix(int height, int width, int** matrix) {
    int result = OK;
    for (int line = 0; line < height && result == OK; line++) {
        for(int column = 0; column < width && result == OK; column++) {
            int inputResult = numInput(&matrix[line][column]);
            if(!inputResult) result = INPUT_ERROR;
        }
    }
    return result;
}

int* findMaxMatrix(int height, int width, int** matrix) {
    int* ptr = &matrix[0][0];
    for(int line = 0; line < height; line++)
        for(int column = 1; column < width; column++) {
            if(matrix[line][column] > *ptr)
                ptr = &matrix[line][column];
        }
    return ptr;
}

int* findMinMatrix(int height, int width, int** matrix) {
    int* ptr = &matrix[0][0];
    for(int line = 0; line < height; line++)
        for(int column = 1; column < width; column++) {
            if(matrix[line][column] < *ptr)
                ptr = &matrix[line][column];
        }
    return ptr;
}

void printMatrix(int height, int width, int** matrix) {
    for(int line = 0; line < height; line++) {
        for(int column = 0; column < width; column++) {
            printf("%d ", matrix[line][column]);
        }
        printf("\n");
    }
}