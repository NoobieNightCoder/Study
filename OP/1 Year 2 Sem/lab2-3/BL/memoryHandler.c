#include "memoryHandler.h"

#include <stdlib.h>
#include <string.h>

void* allocateMemory(int size, int byteSize) {
    return calloc(size, byteSize);
}

static void* reallocateMemory(void* ptr, int size) {
    return realloc(ptr, size);
}

int resizeMemory(void** ptr, int size) {
    int result = 0;
    void* temp = NULL;

    if (ptr) {
        temp = reallocateMemory(*ptr, size);
        if (temp) {
            *ptr = temp;
            result = 1;
        }
    }

    return result;
}

char* duplicateString(const char* source) {
    char* result = NULL;
    int length = 0;

    if (source) {
        length = strlen(source) + 1;
        result = allocateMemory(length, sizeof(char));
        if (result)
            memcpy(result, source, length);
    }

    return result;
}

void freeRowsArray(rowData* rows, int size) {
    if (rows) {
        for (int i = 0; i < size; i++)
            free(rows[i].region);
        free(rows);
    }
}

void freeHeadersArray(char** headers, int headerCount) {
    if (headers) {
        for (int i = 0; i < headerCount; i++)
            free(headers[i]);
        free(headers);
    }
}

void freeTable(tableData* table) {
    if(table) {
        freeRowsArray(table->table, table->tableSize);
        freeHeadersArray(table->headers, table->headerCount);
        free(table);
        table = NULL;
    }
}

void freeChartPoints(ChartPoint* points) {
    free(points);
}
