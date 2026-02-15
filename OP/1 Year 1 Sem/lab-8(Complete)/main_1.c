#include <stdio.h>
#include <stdlib.h>
#include "myString.h"

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} programmCodes;

void printString(char* str) {
    printf("|%s|\n", str);
}

int main() {
    programmCodes endCode = OK;

    char* myStr = getLine();

    if(myStr) {
        printString(myStr);
        myStr = formatStr(myStr);
        printString(myStr);
    } else {
        printf("Incorrect input");
        endCode = INPUT_ERROR;
    }

    free(myStr);
    return endCode;
}