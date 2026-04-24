#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "mainStructures.h"
#include "memoryHandler.h"

#define COLUMNS 7

tableData* readTable(const char* filename);
tableData* filterTable(tableData* table, const char* region);

#ifdef __cplusplus
}
#endif
