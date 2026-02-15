#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void* allocateMemory(int size, int byteSize) {
    return calloc(size, byteSize);
}

void* resizeMemory(void* ptr, size_t size) {
    void* result = NULL;
    if (size > 0)
        result = realloc(ptr, size);
    return result;
}

void* freePtr(void* ptr) {
    free(ptr);
    ptr = NULL;

    return ptr;
}

void* freeLines(char** lines, int numLines) {
    for (int i = 0; i < numLines; i++)
        freePtr(lines[i]);
    freePtr(lines);
    lines = NULL;
    return lines;
}