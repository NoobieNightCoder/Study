#include "stringUtils.h"

#include <stdlib.h>
#include <string.h>

char* duplicateString(const char* source) {
    char* buffer = NULL;
    size_t length = 0;

    if (source != NULL) {
        length = strlen(source);
        buffer = (char*)malloc(length + 1);
        if (buffer != NULL) {
            memcpy(buffer, source, length);
            buffer[length] = '\0';
        }
    } else {
        buffer = (char*)malloc(1);
        if (buffer != NULL) {
            buffer[0] = '\0';
        }
    }

    return buffer;
}
