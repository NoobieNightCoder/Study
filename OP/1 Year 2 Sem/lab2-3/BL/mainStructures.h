#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_DATA_LENGTH 5

typedef struct {
    int year;
    char* region;
    double numData[NUM_DATA_LENGTH];
} rowData;

typedef struct {
    char** headers;
    int headerCount;

    rowData* table;
    int tableSize;
} tableData;

#ifdef __cplusplus
}
#endif
