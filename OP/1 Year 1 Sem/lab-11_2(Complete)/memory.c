#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void* allocateMemory(int size, int byteSize) {
    return calloc(size, byteSize);
}

void* freePtr(void* ptr) {
    free(ptr);
    ptr = NULL;

    return ptr;
}