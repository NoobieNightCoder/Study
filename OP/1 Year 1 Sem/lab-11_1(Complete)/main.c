#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "memory.h"
#include "strFunctions.h"
#include "fileFunctions.h"

#define TWO 2
#define THREE 3
#define TEN 10

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR,
    FILE_OPEN_ERROR,
    FILE_READ_ERROR,
    FILE_SAVE_ERROR
} programmCodes;

void deleteEmptyLines(char** lines, int* numLines) {
    for (int i = *numLines - 1; i >= 0; i--)
        if (isStrEmpty(lines[i]))
            removeLine(lines, numLines, i);
}

void outputError(programmCodes code) {
         if(code == INPUT_ERROR)     printf("Incorrect input");
    else if(code == MEMORY_ERROR)    printf("Memory error");
    else if(code == FILE_OPEN_ERROR) printf("Error openning file");
    else if(code == FILE_READ_ERROR) printf("Error reading file");
    else if(code == FILE_SAVE_ERROR) printf("Error saving file");
}

int main() {
    programmCodes code = OK;

    int numLines = 0;

    char* filename = "aboba.txt";
    char* fileSaveToName = readLine();

    char** lines = NULL;

    if (!fileSaveToName)
        code = INPUT_ERROR;

    if (code == OK) {
        lines = readFile(filename, &numLines);
        if (!lines)
            code = FILE_READ_ERROR;
    }

    if (code == OK) {
        deleteEmptyLines(lines, &numLines);
        indexLines(lines, numLines);
        code = saveFile(fileSaveToName, lines, numLines);
        printLines(lines, numLines);
    } else
        outputError(code);

    freePtr(fileSaveToName);
    freeLines(lines, numLines);
    return code;
}