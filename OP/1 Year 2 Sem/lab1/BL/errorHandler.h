#pragma once

#include "conversionTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int errorID;
    const char* message;
} ErrorMessagesStruct;

typedef enum {
    ERROR_EMPTY_INPUT,
    ERROR_FOUR_BYTE_LIMIT,
    ERROR_FOUR_BYTE_NEGATIVE_LIMIT,
    ERROR_HEX_INCORRECT_INPUT,
    ERROR_DEC_INCORRECT_INPUT,
    ERROR_BIN_INCORRECT_INPUT,
    ERROR_PARSING,
    ERROR_FORMATTING,
    ERROR_MEMORY,
    ERROR_UNKNOWN
} errorID;

const char* getErrorMessage(errorID messageID);

void setErrorMessage(ConversionResult* result, const char* message);

void setErrorMessageById(ConversionResult* result, errorID messageID);

#ifdef __cplusplus
}
#endif
