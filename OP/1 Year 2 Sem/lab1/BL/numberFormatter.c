#include "numberFormatter.h"

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    DECIMAL_BUFFER_SIZE = 64,
    HEX_BUFFER_SIZE = 16,
    ZERO_BINARY_LENGTH = 1
};

#define HIGHEST_BIT_INDEX ((int)((sizeof(uint32_t) * CHAR_BIT) - 1U))
#define BINARY_DIGIT_ZERO ('0')
#define BINARY_DIGIT_ONE ('1')
#define HEX_FORMAT ("%X")
#define DECIMAL_FORMAT ("%d")

static char* allocateAndCopyBuffer(const char* sourceBuffer, int sourceLength) {
    char* copiedBuffer = NULL;

    if (sourceLength >= 0) {
        copiedBuffer = (char*)calloc((size_t)sourceLength + 1U, 1U);

        if (copiedBuffer) {
            memcpy(copiedBuffer, sourceBuffer, (size_t)sourceLength);
        }
    }

    return copiedBuffer;
}

char* formatNumber(int32_t value, Base outputBase) {
    char* formattedResult = NULL;

    if (outputBase == BASE_DEC) {
        char decimalBuffer[DECIMAL_BUFFER_SIZE];
        int decimalLength = snprintf(decimalBuffer, DECIMAL_BUFFER_SIZE, DECIMAL_FORMAT, value);

        formattedResult = allocateAndCopyBuffer(decimalBuffer, decimalLength);
    }

    if (!formattedResult && outputBase == BASE_HEX) {
        char hexBuffer[HEX_BUFFER_SIZE];
        uint32_t unsignedValue = (uint32_t)value;
        int hexLength = snprintf(hexBuffer, HEX_BUFFER_SIZE, HEX_FORMAT, unsignedValue);

        formattedResult = allocateAndCopyBuffer(hexBuffer, hexLength);
    }

    if (!formattedResult && outputBase == BASE_BIN) {
        uint32_t unsignedValue = (uint32_t)value;
        size_t binaryLength = ZERO_BINARY_LENGTH;
        int bitIndex = HIGHEST_BIT_INDEX;
        char* binaryResult = NULL;

        while (bitIndex >= 0 && unsignedValue != 0U && binaryLength == ZERO_BINARY_LENGTH) {
            if (((unsignedValue >> bitIndex) & 1U) == 1U) {
                binaryLength = (size_t)bitIndex + 1U;
            }
            bitIndex--;
        }

        binaryResult = (char*)calloc(binaryLength + 1U, 1U);

        if (binaryResult) {
            size_t writeIndex = 0U;
            int readBitIndex = (int)binaryLength - 1;

            while (readBitIndex >= 0) {
                binaryResult[writeIndex] =
                    (char)((((unsignedValue >> readBitIndex) & 1U) == 1U)
                               ? BINARY_DIGIT_ONE
                               : BINARY_DIGIT_ZERO);
                writeIndex++;
                readBitIndex--;
            }
        }

        formattedResult = binaryResult;
    }

    return formattedResult;
}
