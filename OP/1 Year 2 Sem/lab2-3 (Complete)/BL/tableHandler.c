#include "tableHandler.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "memoryHandler.h"

#define LINE_START_SIZE 64

static const char* separator = ",";
static const char* emptyString = "";

static int isTrimChar(char symbol) {
    int result = 0;
    if (symbol == ' ' || symbol == '\t' || symbol == '\n' || symbol == '\r')
        result = 1;
    return result;
}

static char* trimValue(char* text) {
    char* result = text;
    char* end = NULL;

    if (result) {
        while (*result && isTrimChar(*result))
            result++;

        end = result + strlen(result);
        while (end > result && isTrimChar(*(end - 1)))
            end--;
        *end = '\0';
    }

    return result;
}

static void clearRow(rowData* row) {
    if (row) {
        row->year = 0;
        row->region = NULL;
        for (int i = 0; i < NUM_DATA_LENGTH; i++)
            row->numData[i] = 0;
    }
}

static int readChar(FILE* file, char* symbol) {
    int result = 0;
    int value = EOF;

    if (file && symbol) {
        value = fgetc(file);
        if (value != EOF) {
            *symbol = (char)value;
            result = 1;
        }
    }

    return result;
}

static int appendChar(char** line, int* length, int* allocatedMemory, char symbol) {
    int result = 0;
    int requiredSize = 0;

    if (line && length && allocatedMemory) {
        requiredSize = *length + 2;
        if (requiredSize > *allocatedMemory) {
            *allocatedMemory *= 2;
            result = resizeMemory((void**)line, *allocatedMemory * sizeof(char));
        } else
            result = 1;

        if (result) {
            (*line)[*length] = symbol;
            (*length)++;
        }
    }

    return result;
}

static char* buildLine(char* line, int length, int hasData) {
    char* result = NULL;

    if (line && hasData) {
        line[length] = '\0';
        result = line;
    } else
        free(line);

    return result;
}

static char* readLine(FILE* file, int* status) {
    char* result = NULL;
    char* line = NULL;
    char symbol = '\0';
    int allocatedMemory = LINE_START_SIZE;
    int length = 0;
    int hasData = 0;
    int canRead = 0;

    if (status)
        *status = 0;

    line = allocateMemory(allocatedMemory, sizeof(char));
    canRead = line != NULL;

    while (canRead && readChar(file, &symbol) && symbol != '\n') {
        hasData = 1;
        canRead = appendChar(&line, &length, &allocatedMemory, symbol);
    }

    if (canRead)
        result = buildLine(line, length, hasData);
    else
        free(line);

    if (status) {
        if (!canRead)
            *status = -1;
        else if (hasData)
            *status = 1;
    }

    return result;
}

static int appendHeader(char*** headers, int* headerCount, int* allocatedMemory, char* token) {
    int result = 0;
    char* copy = NULL;

    if (*headerCount >= *allocatedMemory) {
        *allocatedMemory *= 2;
        result = resizeMemory((void**)headers, *allocatedMemory * sizeof(char*));
    } else
        result = 1;

    if (result) {
        copy = duplicateString(token);
        result = copy != NULL;
        if (result) {
            (*headers)[*headerCount] = copy;
            (*headerCount)++;
        }
    }

    return result;
}

static int parseHeaders(char* line, char*** headers, int* headerCount) {
    int result = 0;
    int allocatedMemory = 1;
    int canParse = 0;
    char* token = NULL;

    if (line && headers && headerCount) {
        *headerCount = 0;
        *headers = allocateMemory(allocatedMemory, sizeof(char*));
        canParse = *headers != NULL;
        token = strtok(line, separator);

        while (token && canParse) {
            token = trimValue(token);
            canParse = appendHeader(headers, headerCount, &allocatedMemory, token);
            token = strtok(NULL, separator);
        }

        if (canParse) {
            if (*headerCount > 0)
                canParse = resizeMemory((void**)headers, *headerCount * sizeof(char*));
            result = canParse;
        } else {
            freeHeadersArray(*headers, *headerCount);
            *headers = NULL;
            *headerCount = 0;
        }
    }

    return result;
}

static int parseRow(char* line, rowData* row) {
    int result = 0;
    char* token = NULL;
    char* regionText = NULL;

    if (line && row) {
        clearRow(row);
        token = strtok(line, separator);
        if (token)
            row->year = atoi(trimValue(token));

        token = strtok(NULL, separator);
        if (token)
            regionText = trimValue(token);
        else
            regionText = (char*)emptyString;

        row->region = duplicateString(regionText);
        result = row->region != NULL;

        for (int i = 0; i < NUM_DATA_LENGTH; i++) {
            token = strtok(NULL, separator);
            if (token)
                row->numData[i] = atof(trimValue(token));
        }
    }

    return result;
}

static int appendRow(rowData** rows, int* size, int* allocatedMemory, char* line) {
    int result = 0;

    if (*size >= *allocatedMemory) {
        *allocatedMemory *= 2;
        result = resizeMemory((void**)rows, *allocatedMemory * sizeof(rowData));
    } else
        result = 1;

    if (result) {
        result = parseRow(line, &((*rows)[*size]));
        if (result)
            (*size)++;
    }

    return result;
}

static int readHeaders(FILE* file, char*** headers, int* headerCount) {
    int result = 0;
    char* line = NULL;
    int lineStatus = 0;

    if (file) {
        line = readLine(file, &lineStatus);
        if (line) {
            result = parseHeaders(line, headers, headerCount);
            free(line);
        }
    }

    return result;
}

static int readRows(FILE* file, rowData** rows, int* size) {
    int result = 0;
    int allocatedMemory = 1;
    int canRead = 0;
    char* line = NULL;
    int lineStatus = 0;

    if (file && rows && size) {
        *size = 0;
        *rows = allocateMemory(allocatedMemory, sizeof(rowData));
        canRead = *rows != NULL;

        while (canRead) {
            line = readLine(file, &lineStatus);
            if (line) {
                canRead = appendRow(rows, size, &allocatedMemory, line);
                free(line);
            } else if (lineStatus == 0)
                break;
            else
                canRead = 0;
        }

        if (canRead) {
            if (*size > 0)
                canRead = resizeMemory((void**)rows, *size * sizeof(rowData));
            result = canRead;
        } else {
            freeRowsArray(*rows, *size);
            *rows = NULL;
            *size = 0;
        }
    }

    return result;
}

static tableData* buildTable(char** headers, int headerCount, rowData* rows, int size) {
    tableData* result = NULL;

    if (headers && headerCount > 0) {
        result = allocateMemory(1, sizeof(tableData));
        if (result) {
            result->headers = headers;
            result->headerCount = headerCount;
            result->table = rows;
            result->tableSize = size;
        }
    }

    return result;
}

static int copyRow(rowData* destination, const rowData* source) {
    int result = 0;

    if (destination && source) {
        clearRow(destination);
        destination->year = source->year;
        destination->region = duplicateString(source->region);
        result = destination->region != NULL;
        if (result) {
            for (int i = 0; i < NUM_DATA_LENGTH; i++)
                destination->numData[i] = source->numData[i];
        }
    }

    return result;
}

static rowData* collectRows(tableData* table, const char* region, int* size, int* status) {
    rowData* result = NULL;
    int found = 0;
    int allocatedMemory = 1;
    int canCollect = 0;

    if (status)
        *status = 0;

    if (table && region && size) {
        *size = 0;
        result = allocateMemory(allocatedMemory, sizeof(rowData));
        canCollect = result != NULL;

        for (int i = 0; i < table->tableSize && canCollect; i++) {
            rowData* tablePtr = table->table;
            if (strstr(tablePtr[i].region, region) != NULL) {
                if (found >= allocatedMemory) {
                    allocatedMemory *= 2;
                    canCollect = resizeMemory((void**)&result, allocatedMemory * sizeof(rowData));
                }
                if (canCollect) {
                    canCollect = copyRow(&result[found], &tablePtr[i]);
                    if (canCollect)
                        found++;
                }
            }
        }

        if (canCollect) {
            if (found > 0)
                canCollect = resizeMemory((void**)&result, found * sizeof(rowData));
            *size = found;
        } else {
            freeRowsArray(result, found);
            result = NULL;
            *size = 0;
        }

        if (status)
            *status = canCollect;
    }

    return result;
}

static char** cloneHeaders(tableData* table) {
    char** headers = NULL;
    int canClone = 0;
    int copiedHeaders = 0;

    if (table && table->headerCount > 0) {
        headers = allocateMemory(table->headerCount, sizeof(char*));
        canClone = headers != NULL;

        while (copiedHeaders < table->headerCount && canClone) {
            headers[copiedHeaders] = duplicateString(table->headers[copiedHeaders]);
            canClone = headers[copiedHeaders] != NULL;
            if (canClone)
                copiedHeaders++;
        }

        if (!canClone) {
            freeHeadersArray(headers, copiedHeaders);
            headers = NULL;
        }
    }

    return headers;
}

static tableData* buildFilteredTable(tableData* table, rowData* rows, int size) {
    tableData* result = NULL;
    char** headers = NULL;

    if (table) {
        headers = cloneHeaders(table);
        if (headers) {
            result = allocateMemory(1, sizeof(tableData));
            if (result) {
                result->headers = headers;
                result->headerCount = table->headerCount;
                result->table = rows;
                result->tableSize = size;
            } else
                freeHeadersArray(headers, table->headerCount);
        }
    }

    return result;
}

tableData* readTable(const char* filename) {
    tableData* result = NULL;
    FILE* file = NULL;
    char** headers = NULL;
    int headerCount = 0;
    rowData* rows = NULL;
    int size = 0;
    int canRead = 0;

    if (filename)
        file = fopen(filename, "r");

    if (file) {
        canRead = readHeaders(file, &headers, &headerCount);
        if (canRead)
            canRead = readRows(file, &rows, &size);

        if (canRead) {
            result = buildTable(headers, headerCount, rows, size);
            canRead = result != NULL;
        }

        if (!canRead) {
            freeHeadersArray(headers, headerCount);
            freeRowsArray(rows, size);
        }

        fclose(file);
    }

    return result;
}

tableData* filterTable(tableData* table, const char* region) {
    tableData* result = NULL;
    rowData* rows = NULL;
    int size = 0;
    int collected = 0;

    if (table && region) {
        rows = collectRows(table, region, &size, &collected);
        if (collected) {
            result = buildFilteredTable(table, rows, size);
            if (!result)
                freeRowsArray(rows, size);
        }
    }

    return result;
}
