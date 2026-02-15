#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "memory.h"
#include "strFunctions.h"

#define TWO 2
#define THREE 3
#define TEN 10

char* readLine() {
    char* result = NULL;
    size_t size = 0;
    int done = 0;
    while (!done) {
        char ch = getchar();
        if (ch == EOF || ch == '\n') {
            done = 1;
        } else {
            char* buffer = resizeMemory(result, size + TWO);
            if (buffer == NULL) {
                result = freePtr(result);
                done = 1;
            } else {
                result = buffer;
                result[size++] = ch;
            }
        }
    }
    if (result != NULL) result[size] = '\0';
    return result;
}

int isStrEmpty(char* str) {
    int empty = 1;
    if (str)
        while (*str && empty) {
            if (!isspace((char)*str))
                empty = 0;
            str++;
        }
    return empty;
}

int appendChar(char** line, size_t* len, char ch) {
    int result = 1;
    char* temp = resizeMemory(*line, *len + TWO);

    if (temp) {
        *line = temp;
        (*line)[(*len)++] = ch;
        (*line)[*len] = '\0';
    } else {
        *line = freePtr(*line);
        *len = 0;
        result = 0;
    }
    return result;
}

int pushLine(char*** lines, int* numLines, char* line) {
    int result = 1;
    char** temp = resizeMemory(*lines, (*numLines + 1) * sizeof(char*));

    if (temp) {
        *lines = temp;
        (*lines)[*numLines] = line;
        (*numLines)++;
    } else {
        freePtr(line);
        result = 0;
    }
    return result;
}

void removeLine(char** lines, int* numLines, int index) {
    if (index >= 0 && index < *numLines) {
        freePtr(lines[index]);
        for (int i = index; i + 1 < *numLines; i++)
            lines[i] = lines[i + 1];
        (*numLines)--;
    }
}

void intToStr(int value, char* str) {
    int index = 0;
    int temp = value;

    if (value == 0)
        str[index++] = '0';

    while (temp > 0) {
        str[index++] = (char)('0' + temp % TEN);
        temp /= TEN;
    }

    for (int nextIndex = 0; nextIndex < index / TWO; nextIndex++) {
        char ch = str[nextIndex];
        str[nextIndex] = str[index - nextIndex - 1];
        str[index - nextIndex - 1] = ch;
    }

    str[index] = '\0';
}

void indexLines(char** lines, int numLines) {
    int lineIndex = 0;
    while (lineIndex < numLines) {
        char num[NUM_BUFFER];
        char* oldStr = lines[lineIndex];
        size_t oldLen = strlen(oldStr);
        size_t numLen;

        intToStr(lineIndex + 1, num);
        numLen = strlen(num);

        lines[lineIndex] = allocateMemory(oldLen + numLen + THREE, sizeof(char));

        if (lines[lineIndex]) {
            size_t charIndex = 0;

            while (charIndex < numLen) {
                lines[lineIndex][charIndex] = num[charIndex];
                charIndex++;
            }
            lines[lineIndex][charIndex++] = '.';
            lines[lineIndex][charIndex++] = ' ';

            size_t i = 0;
            while (i <= oldLen) {
                lines[lineIndex][charIndex + i] = oldStr[i];
                i++;
            }
            freePtr(oldStr);
        } else
            lines[lineIndex] = oldStr;
        lineIndex++;
    }
}


void printLines(char** lines, int numLines) {
    for (int i = 0; i < numLines; i++)
        printf("%s", lines[i]);
}