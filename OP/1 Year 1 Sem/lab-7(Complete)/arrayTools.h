#ifndef ARRAYTOOLS_H
#define ARRAYTOOLS_H

// GENERAL FUNCTION //
void swapElements(int* elemA, int* elemB);

// ONE-DIM ARRAYS //
void freeArray(void* array);
void* allocateArray(int arraySize, int byteSize);

int inputArray(int arraySize, int* array);

int findMaxArray(int arraySize, int* array);
int findMinArray(int arraySize, int* array);

void sortArray(int startPos, int endPos, int* array, int (*compare)(int, int));

void printArray(int arraySize, int* array);

// TWO-DIM ARRAYS //
void freeMatrix(void** matrix, int height);
void* allocateMatrix(int height, int width, int byteSize);

int inputMatrix(int height, int width, int** matrix);

int* findMaxMatrix(int height, int width, int** matrix);
int* findMinMatrix(int height, int width, int** matrix);

void printMatrix(int height, int width, int** matrix);

#endif