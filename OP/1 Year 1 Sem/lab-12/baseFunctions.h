#ifndef BASEFUNCTIONS_H
#define BASEFUNCTIONS_H

#define LEN 255

typedef enum {
    OK,
    INPUT_ERROR,
    FILE_OPEN_ERROR,
    FILE_SAVE_ERROR,
    BOOK_LOAD_ERROR,
} programmCode;

typedef enum {
    MENU_ADD_BOOK = 1,
    MENU_PRINT_BOOKS = 2,
    MENU_DELETE_BOOKS = 3,
    MENU_SORT_BOOKS = 4,
    MENU_EXIT_PROGRAMM = 5
} menuCodes;

int numInput(int* num);
void getLine(char str[LEN]);

int ascending(int a, int b);
int descending(int a, int b);

void outputError(programmCode code);

#endif