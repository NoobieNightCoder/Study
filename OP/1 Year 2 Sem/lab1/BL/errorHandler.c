#include "errorHandler.h"

#include "stringUtils.h"

#include <stdlib.h>

static const ErrorMessagesStruct errorMessages[] = {
    { ERROR_EMPTY_INPUT,                "Пустой ввод."                                      },
    { ERROR_FOUR_BYTE_LIMIT,            "Число выходит за пределы 4 байт."                  },
    { ERROR_FOUR_BYTE_NEGATIVE_LIMIT,   "Отрицательное число выходит за пределы 4 байт."    },
    { ERROR_HEX_INCORRECT_INPUT,        "HEX содержит недопустимые символы."                },
    { ERROR_DEC_INCORRECT_INPUT,        "DEC содержит недопустимые символы."                },
    { ERROR_BIN_INCORRECT_INPUT,        "BIN содержит недопустимые символы."                },
    { ERROR_PARSING,                    "Ошибка форматирования результата."                 },
    { ERROR_FORMATTING,                 "Ошибка форматирования результата."                 },
    { ERROR_MEMORY,                     "Ошибка памяти."                                    },
    { ERROR_UNKNOWN,                    "Неизвестная ошибка."                               }
};

const char* getErrorMessage(errorID messageID) {
    const char* errorMessage = errorMessages[ERROR_UNKNOWN].message;

    if (messageID >= ERROR_EMPTY_INPUT && messageID <= ERROR_UNKNOWN)
        errorMessage = errorMessages[messageID].message;

    return errorMessage;
}

void setErrorMessage(ConversionResult* result, const char* message) {
    if (result) {
        if (result->error) {
            free(result->error);
            result->error = NULL;
        }

        result->error = duplicateString(message);
    }
}

void setErrorMessageById(ConversionResult* result, errorID messageID) {
    setErrorMessage(result, getErrorMessage(messageID));
}
