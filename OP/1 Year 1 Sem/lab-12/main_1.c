#include <stdio.h>
#include <stdlib.h>
#include "fileTools.h"
#include "baseFunctions.h"

programmCode menuSaveBook(char* filename) {
    programmCode status = OK;

    Book newBook = inputBook(&status);

    if(status == OK)
        status = saveBook(filename, newBook);
    
    if(status == OK)
        printf("Book saved!\n");

    return status;
}

programmCode menuPrintBooks(char* filename) {
    programmCode status = OK;

    status = readBooks(filename);

    return status;
}

int main() {
    programmCode endCode = OK;
    char* filename = "Books.bin";

    int menuChoise = 0;
    int exitFlag = 0;
    
    while(!exitFlag) {
        endCode = OK;

        printf("1. Add Book\n2. Print All Books\n5. Exit programm\n");

        int inputResult = numInput(&menuChoise);

        if(!inputResult)
            endCode = INPUT_ERROR;
        
        if(endCode == OK) {
            if(menuChoise == MENU_ADD_BOOK)
                endCode = menuSaveBook(filename);
            else if(menuChoise == MENU_PRINT_BOOKS)
                endCode = menuPrintBooks(filename);
            else if(menuChoise == MENU_EXIT_PROGRAMM)
                exitFlag = 1;
            else
                endCode = INPUT_ERROR;
        }
        
        if(endCode != OK)
            outputError(endCode);
    }

    return endCode;
}