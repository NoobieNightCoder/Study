#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileTools.h"
#include "baseFunctions.h"

programmCode findAndDeleteBooks(char* filename, char authorToDelete[LEN], int* totalBooks) {
    programmCode result = OK;

    Book tempBook;
    for(int i = 0; i < *totalBooks; i++) {
        tempBook = loadBook(filename, i, &result);
        if(result == OK) {
            if(!strcmp(tempBook.Author, authorToDelete)) {
                result = deleteBook(filename, i, *totalBooks);
                (*totalBooks)--;
                i--;
            }
        }
    }

    return result;
}

programmCode menuDeleteBooks(char* filename, int* totalBooks) {
    programmCode status = OK;

    char authorToDelete[LEN];
    getLine(authorToDelete);

    status = findAndDeleteBooks(filename, authorToDelete, totalBooks);

    if(status == OK)
        printf("Books have been deleted!\n");

    return status;
}

programmCode menuSortBooks(char* filename, int totalBooks) {
    programmCode status = OK;

    status = sortBooks(filename, totalBooks);
    if(status == OK)
        printf("Books sorted!\n");
    
    return status;
}

int main() {
    programmCode endCode = OK;
    char* filename = "Books.bin";
    int totalBooks;

    int menuChoise = 0;
    int exitFlag = 0;

    endCode = readBooks(filename);

    while(!exitFlag) {
        endCode = OK;
        totalBooks = getTotalBooks(filename, &endCode);

        printf("3. Delete Books By Author\n4. Sort Books\n5. Exit programm\n");
        
        int inputResult = numInput(&menuChoise);

        if(!inputResult)
            endCode = INPUT_ERROR;
        
        if(endCode == OK) {
            if(menuChoise == MENU_DELETE_BOOKS)
                endCode = menuDeleteBooks(filename, &totalBooks);
            else if(menuChoise == MENU_SORT_BOOKS)
                endCode = menuSortBooks(filename, totalBooks);
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