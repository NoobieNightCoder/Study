#ifndef STRPROCCESSFUNCTIONS_H
#define STRPROCCESSFUNCTIONS_H

#include <wchar.h>

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} programmCodes;

void freeWords(wchar_t** words, int count);

wchar_t* getLine();

wchar_t** splitIntoWords(wchar_t* text, int* wordCount, programmCodes* status);
void formatText(wchar_t** words, int wordCount, int width);

void printAlignedLine(wchar_t** words, int start, int end, int width, int isLast);

#endif