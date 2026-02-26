#include "logic.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

static char* allocateAndCopyString(const char* source) {
    if (!source)
        return (char*)calloc(1, 1);

    size_t length = strlen(source);

    char* buffer = (char*)calloc(length + 1, 1);
    if (!buffer)
        return NULL;

    memcpy(buffer, source, length);
    return buffer;
}

static void setErrorMessage(ConversionResult* result, const char* message) {
    if (!result)
        return;

    if (result->error)
        free(result->error);

    result->error = allocateAndCopyString(message);
}

void freeConversionResult(ConversionResult* result) {
    if (!result)
        return;

    if (result->result)
        free(result->result);

    if (result->error)
        free(result->error);

    free(result);
}

static int parseDecimal(const char* text, int32_t* outputValue, char** errorMessage) {
    if (!text || *text == '\0') {
        *errorMessage = allocateAndCopyString("Пустой ввод.");
        return -1;
    }

    char* endPtr = NULL;
    errno = 0;

    long long value = strtoll(text, &endPtr, 10);

    if (errno == ERANGE || value < INT32_MIN || value > INT32_MAX) {
        *errorMessage = allocateAndCopyString("Число выходит за пределы 4 байт.");
        return -1;
    }

    while (isspace((unsigned char)*endPtr))
        endPtr++;

    if (*endPtr != '\0') {
        *errorMessage = allocateAndCopyString("DEC содержит недопустимые символы.");
        return -1;
    }

    *outputValue = (int32_t)value;
    return 0;
}

static int parseHexadecimal(const char* text, int32_t* outputValue, char** errorMessage) {
    if (!text || *text == '\0') {
        *errorMessage = allocateAndCopyString("Пустой ввод.");
        return -1;
    }

    const char* cursor = text;
    int isNegative = 0;

    if (*cursor == '+' || *cursor == '-') {
        if (*cursor == '-')
            isNegative = 1;
        cursor++;
    }

    if (cursor[0] == '0' && (cursor[1] == 'x' || cursor[1] == 'X')) {
        cursor += 2;
    }

    if (*cursor == '\0') {
        *errorMessage = allocateAndCopyString("HEX не содержит цифр.");
        return -1;
    }

    size_t digitCount = 0;
    const char* check = cursor;

    while (*check) {
        if (!isxdigit((unsigned char)*check)) {
            *errorMessage = allocateAndCopyString("HEX содержит недопустимые символы.");
            return -1;
        }
        digitCount++;
        check++;
    }

    if (digitCount > 8) {
        *errorMessage =
            allocateAndCopyString("HEX слишком длинный (макс. 8 символов).");
        return -1;
    }

    unsigned long parsedValue = strtoul(cursor, NULL, 16);

    if (parsedValue > 0xFFFFFFFFUL) {
        *errorMessage = allocateAndCopyString("HEX выходит за 4 байта.");
        return -1;
    }

    if (isNegative) {
        if (parsedValue > (unsigned long)INT32_MAX + 1UL) {
            *errorMessage = allocateAndCopyString("Отрицательное значение вне диапазона.");
            return -1;
        }

        *outputValue = -(int32_t)parsedValue;
    }
    else {
        *outputValue = (int32_t)((uint32_t)parsedValue);
    }

    return 0;
}

static int parseBinary(const char* text, int32_t* outputValue, char** errorMessage) {
    if (!text || *text == '\0') {
        *errorMessage = allocateAndCopyString("Пустой ввод.");
        return -1;
    }

    const char* cursor = text;
    int isNegative = 0;

    if (*cursor == '+' || *cursor == '-') {
        if (*cursor == '-')
            isNegative = 1;
        cursor++;
    }

    if (cursor[0] == '0' && (cursor[1] == 'b' || cursor[1] == 'B')) {
        cursor += 2;
    }

    if (*cursor == '\0') {
        *errorMessage = allocateAndCopyString("BIN не содержит цифр.");
        return -1;
    }

    size_t digitCount = 0;
    uint32_t accumulator = 0;

    while (*cursor) {
        if (*cursor != '0' && *cursor != '1') {
            *errorMessage = allocateAndCopyString("BIN содержит недопустимые символы.");
            return -1;
        }

        accumulator = (accumulator << 1) | (*cursor - '0');
        digitCount++;
        cursor++;
    }

    if (digitCount > 32) {
        *errorMessage = allocateAndCopyString("BIN слишком длинный (макс 32 цифры).");
        return -1;
    }

    if (isNegative) {
        if (accumulator > (uint32_t)INT32_MAX + 1U) {
            *errorMessage = allocateAndCopyString("Отрицательное значение вне диапазона.");
            return -1;
        }

        *outputValue = -(int32_t)accumulator;
    }
    else {
        *outputValue = (int32_t)accumulator;
    }

    return 0;
}

static char* formatResult(int32_t value, Base outputBase) {
    if (outputBase == BASE_DEC) {
        char buffer[64];
        int length = snprintf(buffer, sizeof(buffer), "%d", value);

        char* result = (char*)calloc(length + 1, 1);

        memcpy(result, buffer, length);
        return result;
    }

    if (outputBase == BASE_HEX) {
        char buffer[16];
        uint32_t unsignedValue = (uint32_t)value;

        int length = snprintf(buffer, sizeof(buffer), "%08X", unsignedValue);

        char* result = (char*)calloc(length + 1, 1);

        memcpy(result, buffer, length);
        return result;
    }

    if (outputBase == BASE_BIN) {
        char* result = (char*)calloc(33, 1);

        uint32_t unsignedValue = (uint32_t)value;

        for (int bit = 31; bit >= 0; --bit) {
            result[31 - bit] = ((unsignedValue >> bit) & 1U) + '0';
        }

        return result;
    }

    return NULL;
}

ConversionResult* logic_convert(const char* inputText, Base inputBase, Base outputBase) {
    ConversionResult* result = (ConversionResult*)calloc(1, sizeof(ConversionResult));

    if (!result)
        return NULL;

    if (!inputText || inputText[0] == '\0') {
        setErrorMessage(result, "Пустой ввод.");
        return result;
    }

    int32_t parsedValue = 0;
    char* parseError = NULL;
    int parseStatus = -1;

    if (inputBase == BASE_DEC)
        parseStatus = parseDecimal(inputText, &parsedValue, &parseError);
    else if (inputBase == BASE_HEX)
        parseStatus = parseHexadecimal(inputText, &parsedValue, &parseError);
    else if (inputBase == BASE_BIN)
        parseStatus = parseBinary(inputText, &parsedValue, &parseError);

    if (parseStatus != 0) {
        setErrorMessage(result, parseError ? parseError : "Ошибка разбора числа.");

        if (parseError)
            free(parseError);

        return result;
    }

    result->result = formatResult(parsedValue, outputBase);

    if (!result->result)
        setErrorMessage(result, "Ошибка форматирования результата.");

    return result;
}

int logic_swap(char** inputText, Base* inputBase, char** outputText, Base* outputBase, char** errorMessage) {
    if (errorMessage)
        *errorMessage = NULL;

    char* newInput = allocateAndCopyString(*outputText);

    char* newOutput = allocateAndCopyString(*inputText);

    if (!newInput || !newOutput) {
        if (errorMessage)
            *errorMessage = allocateAndCopyString("Ошибка памяти при перестановке значений.");

        if (newInput) free(newInput);
        if (newOutput) free(newOutput);
        return -1;
    }

    free(*inputText);
    free(*outputText);

    *inputText = newInput;
    *outputText = newOutput;

    Base temp = *inputBase;
    *inputBase = *outputBase;
    *outputBase = temp;

    return 0;
}