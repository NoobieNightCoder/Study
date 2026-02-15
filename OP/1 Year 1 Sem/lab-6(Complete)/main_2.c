#include <stdio.h>
#include <stdlib.h>
#include "arrayTools.h"

#define REQ_INPUT 2

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} statusCodes;

int numInput(int* number) {
    int result = scanf("%d", number);
    return result;
}

statusCodes createMatrix(int* height, int* width, int* matrixSize, int*** matrix) {
    statusCodes result = OK;
    int sizeInputResult = numInput(height) + numInput(width);
    if(sizeInputResult != REQ_INPUT || *height < 0 || *width < 0)
        result = INPUT_ERROR;
    
    *matrixSize = *height * *width;
    
    if(result == OK && *matrixSize) {
        *matrix = (int**)allocateMatrix(*height, *width, sizeof(int));
        if(!*matrix)
            result = MEMORY_ERROR;
    }

    if(result == OK && *matrixSize) {
        int matrixInputResult = inputMatrix(*height, *width, *matrix);
        if(matrixInputResult)
            result = INPUT_ERROR;
    }
    return result;
}

void replaceMaxWithSumUnderSideDiagonal(int height, int width, int** matrix) {
    int* maxPtr = findMaxMatrix(height, width, matrix);
    int sum = 0;
    for(int line = 0; line < height; line++)
        for(int column = 0; line + column < height - 1 && column < width; column++)
            sum += matrix[line][column];
    *maxPtr = sum;
}

void output(statusCodes code, int height, int width, int** matrix) {
    if(code == OK) printMatrix(height, width, matrix);
    else if(code == MEMORY_ERROR) printf("Memory Error");
    else if(code == INPUT_ERROR) printf("Incorrect input");
}

int main() {
    statusCodes programmStatus = OK;
    int height = 0, width = 0, matrixSize = 0;
    int **matrix = NULL;

    programmStatus = createMatrix(&height, &width, &matrixSize, &matrix);
    
    if(programmStatus == OK && matrixSize)
        replaceMaxWithSumUnderSideDiagonal(height, width, matrix);
    
    output(programmStatus, height, width, matrix);
    freeMatrix((void**)matrix, height);
    
    return programmStatus;
}