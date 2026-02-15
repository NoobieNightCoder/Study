#ifndef MEMORY_H
#define MEMORY_H

void* allocateMemory(int size, int byteSize);
void* reallocateMemory(void* ptr, int newSize);
void freeMemory(void* ptr);

#endif