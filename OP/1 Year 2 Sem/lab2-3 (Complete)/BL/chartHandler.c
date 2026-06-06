#include "chartHandler.h"

#include "memoryHandler.h"
#include <stdlib.h>

#define COLUMN_OFFSET 2

typedef struct {
    int year;
    double value;
} YearValue;

static int isValidTable(tableData* table) {
    int result = 0;
    if (table && table->table && table->tableSize > 0)
        result = 1;
    return result;
}

static int isValidColumn(int column) {
    int result = 0;
    if (column > COLUMN_OFFSET && column <= (NUM_DATA_LENGTH + COLUMN_OFFSET))
        result = 1;
    return result;
}

static int getColumnIndex(int column) {
    int result = column - COLUMN_OFFSET - 1;
    return result;
}

static int compareDouble(const void* left, const void* right) {
    int result = 0;
    double leftValue = *(const double*)left;
    double rightValue = *(const double*)right;

    if (leftValue > rightValue)
        result = 1;
    else if (leftValue < rightValue)
        result = -1;
    return result;
}

static int compareYearValue(const void* left, const void* right) {
    int result = 0;
    const YearValue* leftValue = (const YearValue*)left;
    const YearValue* rightValue = (const YearValue*)right;

    if (leftValue->year > rightValue->year)
        result = 1;
    else if (leftValue->year < rightValue->year)
        result = -1;
    else if (leftValue->value > rightValue->value)
        result = 1;
    else if (leftValue->value < rightValue->value)
        result = -1;
    return result;
}

static void clearChartMetrics(ChartMetrics* result) {
    if (result) {
        result->minYear = 0;
        result->maxYear = 0;
        result->minValue = 0;
        result->medianValue = 0;
        result->maxValue = 0;
    }
}

static double calcMedianValue(const double* array, int size) {
    double result = 0;
    if (size > 0) {
        size_t half = (size - 1) / 2;
        if (size % 2 == 0)
            result = (array[half] + array[half + 1]) / 2.0;
        else
            result = array[half];
    }
    return result;
}

static void fillYearValues(tableData* table, int columnIndex, YearValue* array) {
    for (int row = 0; row < table->tableSize; row++) {
        array[row].year = table->table[row].year;
        array[row].value = table->table[row].numData[columnIndex];
    }
}

static int getChartPointCount(const YearValue* array, int size) {
    int result = 0;

    if (array && size > 0) {
        result = 1;
        for (int i = 1; i < size; i++) {
            if (array[i].year != array[i - 1].year)
                result++;
        }
    }

    return result;
}

static double calcMedianValueFromYearRange(const YearValue* array, int start, int size) {
    double result = 0;
    if (array && size > 0) {
        int half = (size - 1) / 2;
        if (size % 2 == 0)
            result = (array[start + half].value + array[start + half + 1].value) / 2.0;
        else
            result = array[start + half].value;
    }
    return result;
}

static void fillChartPoints(const YearValue* array, int size, ChartPoint* points) {
    int pointIndex = 0;
    int start = 0;

    while (start < size) {
        int end = start + 1;
        while (end < size && array[end].year == array[start].year)
            end++;

        points[pointIndex].year = array[start].year;
        points[pointIndex].value = calcMedianValueFromYearRange(array, start, end - start);

        pointIndex++;
        start = end;
    }
}

static int fillChartMetricsFromPoints(const ChartPoint* points, int pointCount, ChartMetrics* result) {
    int status = 0;
    double* array = NULL;

    if (points && pointCount > 0 && result) {
        array = allocateMemory(pointCount, sizeof(double));

        if (array) {
            result->minYear = points[0].year;
            result->maxYear = points[pointCount - 1].year;
            result->minValue = points[0].value;
            result->maxValue = points[0].value;

            for (int i = 0; i < pointCount; i++) {
                double value = points[i].value;
                if (value > result->maxValue)
                    result->maxValue = value;
                else if (value < result->minValue)
                    result->minValue = value;

                array[i] = value;
            }

            qsort(array, pointCount, sizeof(double), compareDouble);
            result->medianValue = calcMedianValue(array, pointCount);
            free(array);
            status = 1;
        }
    }

    return status;
}

AppStatus buildMedianChartPoints(tableData* table, int column, ChartMetrics* result, ChartPoint** points, int* pointCount) {
    AppStatus status = NO_TABLE;
    int tableOk = isValidTable(table);
    int columnOk = isValidColumn(column);
    YearValue* array = NULL;
    ChartPoint* chartPoints = NULL;
    int chartPointCount = 0;

    clearChartMetrics(result);

    if (points)
        *points = NULL;
    if (pointCount)
        *pointCount = 0;

    if (tableOk && columnOk && result && points && pointCount) {
        int columnIndex = getColumnIndex(column);
        array = allocateMemory(table->tableSize, sizeof(YearValue));

        if (array) {
            fillYearValues(table, columnIndex, array);
            qsort(array, table->tableSize, sizeof(YearValue), compareYearValue);

            chartPointCount = getChartPointCount(array, table->tableSize);
            chartPoints = allocateMemory(chartPointCount, sizeof(ChartPoint));

            if (chartPoints) {
                fillChartPoints(array, table->tableSize, chartPoints);

                if (fillChartMetricsFromPoints(chartPoints, chartPointCount, result)) {
                    *points = chartPoints;
                    *pointCount = chartPointCount;
                    status = OK;
                } else
                    free(chartPoints);
            }

            free(array);
        }
    } else if (tableOk && !columnOk)
        status = INVALID_COLUMN;

    return status;
}

AppStatus calcChartMetrics(tableData* table, int column, ChartMetrics* result) {
    AppStatus status = NO_TABLE;
    ChartPoint* points = NULL;
    int pointCount = 0;

    status = buildMedianChartPoints(table, column, result, &points, &pointCount);
    freeChartPoints(points);
    return status;
}
