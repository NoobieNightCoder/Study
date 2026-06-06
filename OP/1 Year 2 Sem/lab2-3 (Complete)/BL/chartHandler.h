#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "mainStructures.h"
#include "errorHandler.h"

typedef struct ChartMetrics {
    int minYear;
    int maxYear;
    double minValue;
    double medianValue;
    double maxValue;
} ChartMetrics;

typedef struct ChartPoint {
    int year;
    double value;
} ChartPoint;

AppStatus calcChartMetrics(tableData* table, int column, ChartMetrics* result);
AppStatus buildMedianChartPoints(tableData* table, int column, ChartMetrics* result, ChartPoint** points, int* pointCount);

#ifdef __cplusplus
}
#endif
