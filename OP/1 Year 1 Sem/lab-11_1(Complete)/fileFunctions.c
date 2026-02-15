#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "strFunctions.h"
#include "fileFunctions.h"

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR,
    FILE_OPEN_ERROR,
    FILE_READ_ERROR,
    FILE_SAVE_ERROR
} programmCodes;

char* readOneLine(FILE* file, int* status) {
    char buffer[BUFFER];
    char* line = NULL;
    size_t len = 0;
    int done = 0;

    while (!done && *status && fgets(buffer, sizeof(buffer), file)) {
        size_t i = 0;

        while (buffer[i] && !done && *status) {
            *status = appendChar(&line, &len, buffer[i]);
            if (buffer[i] == '\n')
                done = 1;
            i++;
        }
    }

    if (len == 0 && feof(file))
        line = freePtr(line);

    return line;
}

char** readFile(char* filename, int* numLines) {
    FILE* file = fopen(filename, "r");
    char** lines = NULL;
    int status = (file != NULL);

    *numLines = 0;

    while (status) {
        char* line = readOneLine(file, &status);

        if (line)
            status = pushLine(&lines, numLines, line);
        else
            status = 0;
    }

    if (!file || !lines) {
        lines = freeLines(lines, *numLines);
        *numLines = 0;
    }

    if (file)
        fclose(file);

    return lines;
}

int saveFile(char* filename, char** lines, int numLines) {
    int code = FILE_SAVE_ERROR;
    FILE* file = fopen(filename, "w");

    if (file) {
        for (int i = 0; i < numLines; i++)
            fputs(lines[i], file);
        fclose(file);
        code = OK;
    }
    return code;
}