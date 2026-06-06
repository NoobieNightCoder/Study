#include "numberParser.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

enum {
    HEX_DIGITS_PER_BYTE = 2,
    BASE_PREFIX_LENGTH = 2
};

#define MAX_HEX_DIGITS_COUNT    ((size_t)(sizeof(uint32_t) * HEX_DIGITS_PER_BYTE))
#define MAX_BINARY_DIGITS_COUNT ((size_t)(sizeof(uint32_t) * CHAR_BIT))

typedef struct {
    unsigned long maxUnsignedInt32;
    unsigned long maxNegativeMagnitude;
} HexParseLimits;

typedef struct {
    uint32_t maxNegativeMagnitude;
} BinaryParseLimits;

static int parseDecimal(const char* text, int32_t* outputValue, errorID* errorCode) {
    int parseStatus = 0;
    char* endPointer = NULL;
    long long parsedValue = 0;

    if (!text || *text == '\0') {
        parseStatus = -1;
        *errorCode = ERROR_EMPTY_INPUT;
    }

    if (parseStatus == 0) {
        errno = 0;
        parsedValue = strtoll(text, &endPointer, BASE_DEC);

        if (errno == ERANGE || parsedValue < INT32_MIN || parsedValue > INT32_MAX) {
            parseStatus = -1;
            *errorCode = ERROR_FOUR_BYTE_LIMIT;
        }
    }

    if (parseStatus == 0) {
        while (*endPointer && isspace((unsigned char)*endPointer)) endPointer++;

        if (*endPointer != '\0') {
            parseStatus = -1;
            *errorCode = ERROR_DEC_INCORRECT_INPUT;
        }
    }

    if (parseStatus == 0)
        *outputValue = (int32_t)parsedValue;

    return parseStatus;
}

static int parseHexadecimal(const char* text, int32_t* outputValue, errorID* errorCode) {
    int parseStatus = 0;
    const char* cursor = text;
    int isNegative = 0;
    size_t digitCount = 0;
    unsigned long parsedValue = 0;
    HexParseLimits limits = { (unsigned long)UINT32_MAX, (unsigned long)INT32_MAX + 1 };

    if (!text || *text == '\0') {
        parseStatus = -1;
        *errorCode = ERROR_EMPTY_INPUT;
    }

    if (parseStatus == 0) {
        if (*cursor == '+' || *cursor == '-') {
            if (*cursor == '-') isNegative = 1;
            cursor++;
        }
    }

    if (parseStatus == 0) {
        if (cursor[0] == '0' && (cursor[1] == 'x' || cursor[1] == 'X'))
            cursor += BASE_PREFIX_LENGTH;

        if (*cursor == '\0') {
            parseStatus = -1;
            *errorCode = ERROR_EMPTY_INPUT;
        }
    }

    if (parseStatus == 0) {
        const char* checker = cursor;

        while (*checker && parseStatus == 0) {
            if (!isxdigit((unsigned char)*checker)) {
                parseStatus = -1;
                *errorCode = ERROR_HEX_INCORRECT_INPUT;
            } else {
                digitCount++;
                checker++;
            }
        }

        if (parseStatus == 0 && digitCount > MAX_HEX_DIGITS_COUNT) {
            parseStatus = -1;
            *errorCode = ERROR_FOUR_BYTE_LIMIT;
        }
    }

    if (parseStatus == 0) {
        parsedValue = strtoul(cursor, NULL, BASE_HEX);

        if (parsedValue > limits.maxUnsignedInt32) {
            parseStatus = -1;
            *errorCode = ERROR_FOUR_BYTE_LIMIT;
        }
    }

    if (parseStatus == 0) {
        if (isNegative) {
            if (parsedValue > limits.maxNegativeMagnitude) {
                parseStatus = -1;
                *errorCode = ERROR_FOUR_BYTE_NEGATIVE_LIMIT;
            } else *outputValue = -(int32_t)parsedValue;
        } else *outputValue = (uint32_t)parsedValue;
    }

    return parseStatus;
}

static int parseBinary(const char* text, int32_t* outputValue, errorID* errorCode) {
    int parseStatus = 0;
    const char* cursor = text;
    int isNegative = 0;
    size_t digitCount = 0;
    uint32_t accumulator = 0;
    BinaryParseLimits limits = { (uint32_t)INT32_MAX + 1 };

    if (!text || *text == '\0') {
        parseStatus = -1;
        *errorCode = ERROR_EMPTY_INPUT;
    }

    if (parseStatus == 0) {
        if (*cursor == '+' || *cursor == '-') {
            if (*cursor == '-') isNegative = 1;
            cursor++;
        }
    }

    if (parseStatus == 0) {
        if (cursor[0] == '0' &&
            (cursor[1] == 'b' || cursor[1] == 'B')) {
            cursor += BASE_PREFIX_LENGTH;
        }

        if (*cursor == '\0') {
            parseStatus = -1;
            *errorCode = ERROR_EMPTY_INPUT;
        }
    }

    if (parseStatus == 0) {
        while (*cursor && parseStatus == 0) {
            if (*cursor != '0' && *cursor != '1') {
                parseStatus = -1;
                *errorCode = ERROR_BIN_INCORRECT_INPUT;
            } else {
                accumulator = (accumulator << 1) | (uint32_t)(*cursor - '0');
                digitCount++;
                cursor++;
            }
        }

        if (parseStatus == 0 && digitCount > MAX_BINARY_DIGITS_COUNT) {
            parseStatus = -1;
            *errorCode = ERROR_FOUR_BYTE_LIMIT;
        }
    }

    if (parseStatus == 0) {
        if (isNegative) {
            if (accumulator > limits.maxNegativeMagnitude) {
                parseStatus = -1;
                *errorCode = ERROR_FOUR_BYTE_NEGATIVE_LIMIT;
            } else *outputValue = -(int32_t)accumulator;
        } else *outputValue = (int32_t)accumulator;
    }

    return parseStatus;
}

int parseNumber(const char* text, Base inputBase, int32_t* outputValue, errorID* errorCode) {
    int parseStatus = 0;

    if (!outputValue || !errorCode) {
        parseStatus = -1;
    }

    if (parseStatus == 0) {
        if      (inputBase == BASE_DEC) parseStatus = parseDecimal(text, outputValue, errorCode);
        else if (inputBase == BASE_HEX) parseStatus = parseHexadecimal(text, outputValue, errorCode);
        else if (inputBase == BASE_BIN) parseStatus = parseBinary(text, outputValue, errorCode);
        else {
            parseStatus = -1;
            *errorCode = ERROR_PARSING;
        }
    }

    return parseStatus;
}
