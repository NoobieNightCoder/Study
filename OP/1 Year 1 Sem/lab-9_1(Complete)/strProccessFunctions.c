#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "strProccessFunctions.h"
#include "memory.h"

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} programmCodes;

char* getLine() {
    char* result = NULL;
    int size = 0;
    int done = 0;
    while (!done) {
        char ch = getchar();
        if (ch == EOF || ch == '\n') {
            done = 1;
        } else {
            char* buffer = reallocateMemory(result, size + 2);
            if (buffer == NULL) {
                freeMemory(result);
                result = NULL;
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

int findWord(WordEntry* dict, int total, char* word) {
    int result = -1;

    int i = 0;
    while (i < total && result == -1) {
        if (strcmp(dict[i].word, word) == 0)
            result = i;
        i++;
    }

    return result;
}

void sortWords(WordEntry* dict, int total) {
    int i = 0;
    while (i < total - 1) {
        int j = i + 1;
        while (j < total) {
            if ((dict[j].count > dict[i].count) ||
               ((dict[j].count == dict[i].count) && (dict[j].order < dict[i].order))) {
                WordEntry temp = dict[i];
                dict[i] = dict[j];
                dict[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int addWord(WordEntry** dict, int* total, char* word, int* order) {
    int result = OK;
    int index = findWord(*dict, *total, word);
    if (index >= 0) {
        (*dict)[index].count++;
    } else {
        WordEntry* tmp = reallocateMemory(*dict, (*total + 1) * sizeof(WordEntry));
        if (tmp != NULL) {
            *dict = tmp;
            (*dict)[*total].word = allocateMemory(strlen(word) + 1, sizeof(char));
            if ((*dict)[*total].word != NULL) {
                strcpy((*dict)[*total].word, word);
                (*dict)[*total].count = 1;
                (*dict)[*total].order = *order;
                (*order)++;
                (*total)++;
            } else 
                result = MEMORY_ERROR;
        } else
            result = MEMORY_ERROR;
    }
    return result;
}

int proccessText(char* text, WordEntry** dict, int* total) {
    int result = OK;
    char* word = NULL;
    int wlen = 0;
    int order = 0;
    int i = 0;
    int flag = 1;

    while(flag && result == OK) {
        char c = text[i];
        int is_letter = isalpha(c);

        if (is_letter) {
            char *tmp = reallocateMemory(word, wlen + 2);
            if (tmp != NULL) {
                word = tmp;
                word[wlen] = tolower(c);
                wlen++;
                word[wlen] = '\0';
            } else
                result = MEMORY_ERROR;
        } else {
            if (wlen > 0) {
                result = addWord(dict, total, word, &order);
                freeMemory(word);
                word = NULL;
                wlen = 0;
            }
            if (c == '\0')
                flag = 0;
        }
        i++;
    }
    return result;
}