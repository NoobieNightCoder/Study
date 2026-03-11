#pragma once

#include "conversionTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

void* allocateMemory(int size, int byteSize);
char* duplicateString(const char* source);
char* allocateAndCopyBuffer(const char* sourceBuffer, int sourceLength);
void freeConversionResult(ConversionResult* conversionResult);

#ifdef __cplusplus
}
#endif