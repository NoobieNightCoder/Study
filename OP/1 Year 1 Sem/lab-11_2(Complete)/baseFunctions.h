#ifndef BASEFUNCTIONS_H
#define BASEFUNCTIONS_H

#include "fileFunctions.h"

#define LEN 255

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR,
    FILE_OPEN_ERROR,
    FILE_READ_ERROR,
    FILE_LOAD_ERROR,
    FILE_SAVE_ERROR,
    FILE_TEMP_ERROR
} programmCodes;

typedef enum {
    MENU_ADD_BOOK = 1,
    MENU_PRINT_BOOKS = 2,
    MENU_DELETE_BOOKS = 3,
    MENU_SORT_BOOKS = 4,
    MENU_EXIT_PROGRAMM = 5
} menuCodes;

int numInput(int* num);
void getLine(char str[LEN]);

Book inputBook(programmCodes* code);

void printBook(Book book);
void outputError(programmCodes code);

#endif