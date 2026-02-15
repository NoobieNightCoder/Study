#include <stdio.h>
#include <stdlib.h>
#include "myString.h"

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} programCodes;

int numInput(int* num) {
    return scanf("%d", num);
}

programCodes createStrArray(char*** strArray, int strCount) {
    programCodes result = OK;

    *strArray = calloc(strCount, sizeof(char*));
    if (*strArray == NULL) result = MEMORY_ERROR;

    if (result == OK) {
        for (int i = 0; i < strCount && result == OK; i++) {
            (*strArray)[i] = getLine();
            if ((*strArray)[i] == NULL) 
                result = MEMORY_ERROR;
        }
    }

    return result;
}

programCodes getStrVariables(char** whatToChange, char** changeToStr) {
    programCodes result = OK;

    *whatToChange = getLine();
    *changeToStr = getLine();

    if (*whatToChange == NULL || *changeToStr == NULL) {
        result = INPUT_ERROR;
    }

    return result;
}

int processStrings(char*** nameStrings, char** whatToChange, char** changeToStr, int strCount) {
    int returnCode = OK;

    returnCode = createStrArray(nameStrings, strCount);
    
    if (returnCode == OK)
        returnCode = getStrVariables(whatToChange, changeToStr);
    
    if(returnCode == OK) {
        for (int i = 0; i < strCount && returnCode == OK; i++) {
            int space1 = findSymbol((*nameStrings)[i], ' ');
            int space2 = rFindSymbol((*nameStrings)[i], ' ');
            if (space1 == -1 || space2 == -1 || space1 == space2)
                returnCode = INPUT_ERROR;
        }
    }

    if (returnCode == OK) {
        for (int i = 0; i < strCount && returnCode == OK; i++) {
            int space2 = rFindSymbol((*nameStrings)[i], ' ');
            int p = rFindStr((*nameStrings)[i], *whatToChange);
            if (p > space2 && (*nameStrings)[i][p - 1] != ' ' && (*nameStrings)[i][p + strSize(*whatToChange)] == '\0') {
                (*nameStrings)[i] = replaceStr((*nameStrings)[i], p, *changeToStr);
            }
        }
    }

    return returnCode;
}

void output(programCodes code, char** strArray, int strCount) {
    if(code == OK)
        for(int i = 0; i < strCount; i++)
            printStr(strArray[i]);
    else if(code == MEMORY_ERROR)
        printf("Memory error");
    else
        printf("Incorrect input");
}

int main() {
    programCodes result = OK;
    int strCount = 0;

    char** nameStrings = NULL;
    char* whatToChange = NULL;
    char* changeToStr = NULL;

    int inputResult = numInput(&strCount);

    if (!inputResult || strCount <= 0)
        result = INPUT_ERROR;
    else {
        int c = getchar(); (void)c;
        result = processStrings(&nameStrings, &whatToChange, &changeToStr, strCount);
    }

    output(result, nameStrings, strCount);

    freeStr(whatToChange);
    freeStr(changeToStr);
    freeStrArray(nameStrings, strCount);

    return result;
}