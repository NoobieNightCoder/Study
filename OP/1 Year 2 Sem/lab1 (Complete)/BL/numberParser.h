#pragma once

#include "conversionTypes.h"
#include "errorHandler.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int parseNumber(const char* text, Base inputBase, int32_t* outputValue, errorID* errorCode);

#ifdef __cplusplus
}
#endif