#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "errorHandler.h"
#include "mainStructures.h"

typedef struct {
    double minValue;
    double medianValue;
    double maxValue;
} CalcResult;

AppStatus calcTableStats(tableData* table, int column, CalcResult* result);

#ifdef __cplusplus
}
#endif
