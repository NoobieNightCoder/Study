#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "memory.h"
#include "strProccessFunctions.h"

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} programmCodes;

void freeDict(WordEntry* dict, int total) {
    if(dict)
        for(int i = 0; i < total; i++)
            freeMemory(dict[i].word);
    freeMemory(dict);
}

void output(programmCodes code, WordEntry* dict, int total) {
    if(code == OK)
        for(int i = 0; i < total; i++)
            printf("%s: %d\n", dict[i].word, dict[i].count);
    else if(code == INPUT_ERROR)
        printf("Incorrect input");
    else if (code == MEMORY_ERROR)
        printf("Memory error");
}

int main() {
    programmCodes endCode = OK;
    WordEntry* dict = NULL;
    int total_words = 0;

    char *text = getLine();
    if (text != NULL) {
        endCode = proccessText(text, &dict, &total_words);
        freeMemory(text);
    } else
        endCode = INPUT_ERROR;

    if(endCode == OK)
        sortWords(dict, total_words);

    output(endCode, dict, total_words);

    freeDict(dict, total_words);
    return endCode;
}