#include "conversionMain.h"

#include "errorHandler.h"
#include "numberFormatter.h"
#include "numberParser.h"
#include "stringUtils.h"

#include <stdint.h>
#include <stdlib.h>

ConversionResult* logicConvert(const char* inputText, Base inputBase, Base outputBase) {
    ConversionResult* conversionResult = allocateMemory(1, sizeof(ConversionResult));
    int conversionStatus = 0;
    int32_t parsedValue = 0;
    errorID parseErrorId = ERROR_PARSING;

    if(!conversionResult)
        conversionStatus = -1;

    if (!inputText || inputText[0] == '\0') {
        setErrorMessageById(conversionResult, ERROR_EMPTY_INPUT);
        conversionStatus = -1;
    }

    if (!conversionStatus) {
        conversionStatus = parseNumber(inputText, inputBase, &parsedValue, &parseErrorId);

        if (conversionStatus)
            setErrorMessageById(conversionResult, parseErrorId);
    }

    if (!conversionStatus) {
        conversionResult->result = formatNumber(parsedValue, outputBase);

        if (!conversionResult->result) {
            conversionStatus = -1;
            setErrorMessageById(conversionResult, ERROR_FORMATTING);
        }
    }

    return conversionResult;
}

int logicSwap(char** inputText, Base* inputBase, char** outputText, Base* outputBase, char** errorMessage) {
    int swapStatus = 0;
    char* swappedInputText = NULL;
    char* swappedOutputText = NULL;

    if (errorMessage)
        *errorMessage = NULL;

    if (!inputText || !outputText || !inputBase || !outputBase) {
        swapStatus = -1;
        if (errorMessage)
            *errorMessage = duplicateString(getErrorMessage(ERROR_PARSING));
    }

    if (swapStatus == 0) {
        swappedInputText = duplicateString(*outputText);
        swappedOutputText = duplicateString(*inputText);

        if (!swappedInputText || !swappedOutputText) {
            swapStatus = -1;
            if (errorMessage)
                *errorMessage = duplicateString(getErrorMessage(ERROR_MEMORY));
        }
    }

    if (swapStatus == 0) {
        Base temporaryBase = *inputBase;

        free(*inputText);
        free(*outputText);

        *inputText = swappedInputText;
        *outputText = swappedOutputText;
        *inputBase = *outputBase;
        *outputBase = temporaryBase;
    }

    if (swapStatus != 0) {
        if (swappedInputText)
            free(swappedInputText);
        if (swappedOutputText)
            free(swappedOutputText);
    }

    return swapStatus;
}
