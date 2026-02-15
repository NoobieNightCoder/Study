#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "memory.h"
#include "strProccessFunctions.h"

void outputError(programmCodes code) {
    if (code == INPUT_ERROR) printf("Incorrect input");
    if (code == MEMORY_ERROR) printf("Memory error");
}

int main() {
    programmCodes endCode = OK;
    wchar_t* text = getLine();

    int width = 0;
    if (text) {
        int inputResult = wscanf(L"%d", &width);
        if (!inputResult || width <= 0)
            endCode = INPUT_ERROR;
    } else
        endCode = INPUT_ERROR;

    int wordCount = 0;
    wchar_t** words = NULL;

    if (endCode == OK)
        words = splitIntoWords(text, &wordCount, &endCode);

    if (endCode == OK)
        formatText(words, wordCount, width);
    
    if (endCode != OK) outputError(endCode);

    if(words)
        freeWords(words, wordCount);
    freeMemory(text);

    return endCode;
}