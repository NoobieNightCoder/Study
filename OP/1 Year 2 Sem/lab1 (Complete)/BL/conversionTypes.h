#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    BASE_HEX = 16,
    BASE_DEC = 10,
    BASE_BIN = 2
} Base;

typedef struct {
    char *result;
    char *error;
} ConversionResult;

#ifdef __cplusplus
}
#endif