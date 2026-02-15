#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>

void* allocateMemory(int size, int byteSize);
void* resizeMemory(void* ptr, size_t size);
void* freePtr(void* ptr);
void* freeLines(char** lines, int numLines);

#endif