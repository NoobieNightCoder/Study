#ifndef ARRAYTOOLS_H
#define ARRAYTOOLS_H

void* createArray(int, int);
void arrayFree(void*);
int sizeCheck(int);
int numInput(int*);
int sizeInput(int*);
int arrayInput(int, int*);
void swapElements(int*, int, int);
void printArray(int, int*);

#endif