#include "logic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHAR_NUMS 48
#define CHAR_LETTERS 55

typedef enum {
    HEX_STATE = 1,
    DEC_STATE = 2,
    BIN_STATE = 3
} States;

typedef enum {
    HEX = 16,
    DEC = 10,
    BIN = 2
} Types;

void* allocateMemory(int size, int byte) {
    return calloc(size, byte);
}

void freeMemory(void* ptr) {
    free(ptr);
    ptr = NULL;
}

static char* converter(const char* from, int modeFrom, int modeTo) {
    char* result = NULL;
    int num = (int)strtol(from, NULL, modeFrom);
    int count = 0;
    for(int buffer = num; buffer > 0; buffer /= modeTo, count++);
    result = allocateMemory(count + 1, sizeof(char));
    for(int i = 0; num > 0; num /= modeTo, i++) {
        int charCode = num % modeTo;
        if(charCode < DEC) charCode += CHAR_NUMS;
        else charCode += CHAR_LETTERS;
        result[i] = (char)charCode;
    }
    result[count] = '\0';
    result = strrev(result);
    return result;
}

char* convertNum(const char* input, int modeFrom, int modeTo) {
    if(modeFrom == HEX_STATE) modeFrom = HEX;
    else if (modeFrom == DEC_STATE) modeFrom = DEC;
    else if (modeFrom == BIN_STATE) modeFrom = BIN;

    if(modeTo == HEX_STATE) modeTo = HEX;
    else if (modeTo == DEC_STATE) modeTo = DEC;
    else if (modeTo == BIN_STATE) modeTo = BIN;

    return converter(input, modeFrom, modeTo);
}