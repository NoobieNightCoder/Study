#include "calculator.h"

#include "chartHandler.h"

static void clearCalcResult(CalcResult* result) {
    if (result) {
        result->minValue = 0;
        result->medianValue = 0;
        result->maxValue = 0;
    }
}

AppStatus calcTableStats(tableData* table, int column, CalcResult* result) {
    AppStatus status = NO_TABLE;
    ChartMetrics chartMetrics;

    clearCalcResult(result);
    status = calcChartMetrics(table, column, &chartMetrics);

    if (status == OK && result) {
        result->minValue = chartMetrics.minValue;
        result->medianValue = chartMetrics.medianValue;
        result->maxValue = chartMetrics.maxValue;
    }

    return status;
}
