#pragma once

#include "conversionTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

ConversionResult* logicConvert(const char* inputText, Base inputBase, Base outputBase);

int logicSwap(char** inputText, Base* inputBase, char** outputText, Base* outputBase, char** errorMessage);

#ifdef __cplusplus
}
#endif
