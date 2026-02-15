#include <stdio.h>
#include <stdlib.h>
#include "arrayTools.h"

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR,
    SIZE_ERROR
} statusCodes;

int sortZeros(int startPos, int endPos, int* numArray) {
    int currPos = startPos;
    for (int index = currPos; index < endPos; index++)
        if (numArray[index] == 0)
            swapElements(numArray, index, currPos++);
    
    return currPos;
}
int sortPosNums(int startPos, int endPos, int* numArray) {
    int currPos = startPos;
    for (int index = currPos; index < endPos; index++)
        if (numArray[index] > 0)
            swapElements(numArray, index, currPos++);
    
    return currPos;
}
void sort(int startPos, int endPos, int* numArray) {
    for (int iteration = ++startPos; iteration < endPos; iteration++)
        for (int index = startPos; index < endPos; index++)
            if (numArray[index] < numArray[index - 1])
                swapElements(numArray, index, index - 1);
}

void mainSort(int arraySize, int *numArray) {
    int currPos = 0;

    currPos = sortZeros(currPos, arraySize, numArray);
    currPos = sortPosNums(currPos, arraySize, numArray);

    sort(0, currPos, numArray);

    sort(currPos, arraySize, numArray);
}

void output(statusCodes code, int arraySize, int* numArray) {
    if(code == OK) printArray(arraySize, numArray);
    else if(code == MEMORY_ERROR) printf("Memory Error");
    else printf("Incorrect input");
}

int main() {
    int arraySize = -1;
    statusCodes programmStatus = OK;
    
    int inputResult = numInput(&arraySize);
    int checkResult;

    if(inputResult)
        checkResult = sizeCheck(arraySize);
    else
        programmStatus = INPUT_ERROR;

    if(programmStatus == OK && !checkResult)
        programmStatus = SIZE_ERROR;

    int *numArray = NULL;
    
    if(programmStatus == OK) {
        numArray = createArray(arraySize, sizeof(int));
        if(!numArray)
            programmStatus = MEMORY_ERROR;
    }

    if(programmStatus == OK) {
        int arrayInputResult = arrayInput(arraySize, numArray);
        if(arrayInputResult)
            programmStatus = INPUT_ERROR;
    }
    
    if(programmStatus == OK)
        mainSort(arraySize, numArray);
    
    output(programmStatus, arraySize, numArray);
    arrayFree(numArray);
    return programmStatus;
}