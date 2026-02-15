#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void* allocateMemory(int size, int byteSize) {
    return calloc(size, byteSize);
}

void* reallocateMemory(void* ptr, int newSize) {
    void* result = NULL;
    if (newSize > 0)
        result = realloc(ptr, newSize);
    return result;
}
void freeMemory(void* ptr) {
    free(ptr);
}