#include "stringUtils.h"

#include <stdlib.h>
#include <string.h>

void* allocateMemory(int size, int byteSize) {
    return calloc(size, byteSize);
}

char* duplicateString(const char* source) {
    char* buffer = NULL;
    size_t length = 0;

    if (source != NULL) {
        length = strlen(source);
        buffer = allocateMemory(length + 1, sizeof(char));
        if (buffer != NULL) {
            memcpy(buffer, source, length);
            buffer[length] = '\0';
        }
    } else {
        buffer = allocateMemory(1, sizeof(char));
        if (buffer != NULL) {
            buffer[0] = '\0';
        }
    }

    return buffer;
}

char* allocateAndCopyBuffer(const char* sourceBuffer, int sourceLength) {
    char* copiedBuffer = NULL;

    if (sourceLength >= 0) {
        copiedBuffer = allocateMemory(sourceLength + 1, sizeof(char));

        if (copiedBuffer) {
            memcpy(copiedBuffer, sourceBuffer, (size_t)sourceLength);
        }
    }

    return copiedBuffer;
}

void freeConversionResult(ConversionResult* conversionResult) {
    if(conversionResult) {
        if (conversionResult->result) {
            free(conversionResult->result);
            conversionResult->result = NULL;
        }

        if (conversionResult->error) {
            free(conversionResult->error);
            conversionResult->error = NULL;
        }
        free(conversionResult);
    }
}
