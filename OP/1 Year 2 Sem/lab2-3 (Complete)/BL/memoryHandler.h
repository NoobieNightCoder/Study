#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "mainStructures.h"

typedef struct ChartPoint ChartPoint;

void* allocateMemory(int size, int byteSize);
int resizeMemory(void** ptr, int size);
char* duplicateString(const char* source);
void freeRowsArray(rowData* rows, int size);
void freeHeadersArray(char** headers, int headerCount);
void freeTable(tableData* table);
void freeChartPoints(ChartPoint* points);

#ifdef __cplusplus
}
#endif
