#ifndef LOGIC_H
#define LOGIC_H

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

ConversionResult* logic_convert(const char *input, Base in_base, Base out_base);

void freeConversionResult(ConversionResult *r);

int logic_swap(char **input_ptr, Base *in_base, char **output_ptr, Base *out_base, char **error_out);

#ifdef __cplusplus
}
#endif

#endif