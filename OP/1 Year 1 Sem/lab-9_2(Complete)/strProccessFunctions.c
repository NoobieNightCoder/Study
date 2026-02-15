#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "strProccessFunctions.h"
#include "memory.h"

#define DEFAULT_CAPACITY_SIZE 16

// LOCAL FUNCTIONS //

static wchar_t* skipSpaces(wchar_t* ptr) {
    while (*ptr == L' ' || *ptr == L'\t') ptr++;
    return ptr;
}

static int getWordLength(wchar_t* ptr) {
    int len = 0;
    while (*ptr && *ptr != L' ' && *ptr != L'\n') {
        len++;
        ptr++;
    }
    return len;
}

static void addWordToArray(wchar_t*** words, int* used, int* capacity, wchar_t* start, int wordLen, programmCodes* status) {
    if (*used >= *capacity) {
        int newCapacity;
        if(*capacity == 0)
            newCapacity = DEFAULT_CAPACITY_SIZE;
        else
            newCapacity = *capacity * 2;
        wchar_t** temp = reallocateMemory(*words, newCapacity * sizeof(wchar_t*));
        if (!temp)
            *status = MEMORY_ERROR;
        else {
            *words = temp;
            *capacity = newCapacity;
        }
    }
    if (*status == OK) {
        (*words)[*used] = allocateMemory(wordLen + 1, sizeof(wchar_t));
        if (!(*words)[*used])
            *status = MEMORY_ERROR;
        else {
            for (int i = 0; i < wordLen; i++) (*words)[*used][i] = start[i];
            (*words)[*used][wordLen] = L'\0';
            (*used)++;
        }
    }
}

// MAIN FUNCITONS //

void freeWords(wchar_t** words, int count) {
    for (int i = 0; i < count; i++) freeMemory(words[i]);
    freeMemory(words);
}

wchar_t* getLine() {
    wchar_t* result = NULL;
    size_t size = 0;
    int done = 0;
    while (!done) {
        wchar_t ch = fgetwc(stdin);
        if (ch == WEOF || ch == L'\n') {
            done = 1;
        } else {
            wchar_t* buffer = reallocateMemory(result, (size + 2) * sizeof(wchar_t));
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
    if (result != NULL) result[size] = L'\0';
    return result;
}

wchar_t** splitIntoWords(wchar_t* text, int* wordCount, programmCodes* status) {
    wchar_t** words = NULL;

    int used = 0, capacity = 0;
    wchar_t* ptr = text;

    int flag = 1;
    while (*ptr && *status == OK && flag) {
        ptr = skipSpaces(ptr);
        if (!*ptr) flag = 0;

        wchar_t* start = NULL;
        int wordLen = 0;
        if (flag) {
            start = ptr;
            wordLen = getWordLength(ptr);
            ptr += wordLen;
        }

        if (wordLen > 0) addWordToArray(&words, &used, &capacity, start, wordLen, status);
    }

    if (*status == OK) *wordCount = used;
    return words;
}


void formatText(wchar_t** words, int wordCount, int width) {
    int i = 0;
    while (i < wordCount) {
        int lineStart = i;
        int lineLen = (int)wcslen(words[i]);
        i++;

        while (i < wordCount && lineLen + 1 + (int)wcslen(words[i]) <= width) {
            lineLen += 1 + (int)wcslen(words[i]);
            i++;
        }

        int isLastLine = i >= wordCount;
        printAlignedLine(words, lineStart, i - 1, width, isLastLine);
    }
}

void printAlignedLine(wchar_t** words, int start, int end, int width, int isLast) {
    int totalChars = 0;
    int gaps = end - start;
    for (int i = start; i <= end; i++) totalChars += wcslen(words[i]);

    if (isLast || gaps == 0) {
        for (int i = start; i <= end; i++) {
            wprintf(L"%ls", words[i]);
            if (i < end) wprintf(L" ");
        }
        wprintf(L"\n");

    } else {
        int spacesNeeded = width - totalChars;
        if (spacesNeeded < 0) spacesNeeded = 0;

        int baseSpace = spacesNeeded / gaps;
        int extraSpace = spacesNeeded % gaps;

        for (int i = start; i <= end; i++) {
            wprintf(L"%ls", words[i]);
            if (i < end) {
                int space = baseSpace + (int)(extraSpace > 0);
                if (extraSpace > 0) extraSpace--;
                for (int j = 0; j < space; j++) wprintf(L" ");
            }
        }
        wprintf(L"\n");
    }
}