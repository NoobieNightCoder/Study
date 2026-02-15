#include <stdio.h>
#include <stdlib.h>
#include "arrayTools.h"

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} statusCodes;

int numInput(int* number) {
    int result = scanf("%d", number);
    return result;
}

statusCodes createMatrix(int* matrixSize, int*** matrix) {
    statusCodes result = OK;
    int sizeInputResult = numInput(matrixSize);
    if(!sizeInputResult || *matrixSize < 0)
        result = INPUT_ERROR;
    
    if(result == OK && *matrixSize) {
        *matrix = (int**)allocateMatrix(*matrixSize, *matrixSize, sizeof(int));
        if(!*matrix)
            result = MEMORY_ERROR;
    }

    if(result == OK && *matrixSize) {
        int matrixInputResult = inputMatrix(*matrixSize, *matrixSize, *matrix);
        if(matrixInputResult)
            result = INPUT_ERROR;
    }
    return result;
}

void altTransposeMatrix(int size, int** matrix) {
    for(int line = 0; line < size - 1; line++) {
        for(int column = 0; column < size - 1 - line; column++)
            swapElements(matrix[line] + column, matrix[size - 1 - column] + (size - 1 - line));
    }
}

void output(statusCodes code, int size, int** matrix) {
    if(code == OK) printMatrix(size, size, matrix);
    else if(code == MEMORY_ERROR) printf("Memory Error");
    else printf("Incorrect input");
}

int main() {
    statusCodes programmStatus = OK;
    int matrixSize = 0;
    int** matrix = NULL;
    
    programmStatus = createMatrix(&matrixSize, &matrix);
    
    if(programmStatus == OK)
        altTransposeMatrix(matrixSize, matrix);
    
    output(programmStatus, matrixSize, matrix);
    freeMatrix((void**)matrix, matrixSize);
    return programmStatus;
}