#include <stdio.h>
#include <stdlib.h>

#include "baseFunctions.h"
#include "fileFunctions.h"

int numInput(int* num) {
    int result = scanf("%d", num);
    getchar();

    return result;
}

void getLine(char str[LEN]) {
    int flag = 0;
    for(int index = 0; index < LEN && !flag; index++) {
        char letter = getchar();
        if(letter == '\n') {
            str[index] = '\0';
            flag = 1;
        } else
            str[index] = letter;
    }
    if(!flag)
        str[LEN - 1] = '\0';
}

Book inputBook(programmCodes* code) {
    Book newBook;
    getLine(newBook.Name);
    getLine(newBook.Author);
    int pageInput = numInput(&newBook.PageCount);
    int rankInput = numInput(&newBook.Rank);

    if(newBook.Name[0] == '\0' || newBook.Author[0] == '\0' || !pageInput || !rankInput)
        *code = INPUT_ERROR;

    return newBook;
}

void printBook(Book book) {
    printf("Name: %s\n", book.Name);
    printf("Author: %s\n", book.Author);
    printf("Pages: %d\n", book.PageCount);
    printf("Rank: %d\n", book.Rank);
    printf("------------------------\n");
}

void outputError(programmCodes code) {
         if(code == INPUT_ERROR)     printf("Incorrect input\n");
    else if(code == MEMORY_ERROR)    printf("Memory error\n");
    else if(code == FILE_OPEN_ERROR) printf("Error openning file\n");
    else if(code == FILE_READ_ERROR) printf("Error reading file\n");
    else if(code == FILE_LOAD_ERROR) printf("Error loading book: Book not found OR Index out of Range\n");
    else if(code == FILE_SAVE_ERROR) printf("Error saving file\n");
    else if(code == FILE_TEMP_ERROR) printf("Error creating Temp File\n");
}