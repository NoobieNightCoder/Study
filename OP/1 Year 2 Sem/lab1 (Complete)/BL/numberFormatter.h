#pragma once

#include "conversionTypes.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

char* formatNumber(int32_t value, Base outputBase);

#ifdef __cplusplus
}
#endif