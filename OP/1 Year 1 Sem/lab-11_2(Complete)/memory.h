#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>

void* allocateMemory(int size, int byteSize);
void* freePtr(void* ptr);

#endif