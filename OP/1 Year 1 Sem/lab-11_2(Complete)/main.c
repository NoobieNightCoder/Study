#include <stdio.h>
#include <stdlib.h>

#include "fileFunctions.h"
#include "baseFunctions.h"

programmCodes menuAddBook(char* filename) {
    programmCodes status = OK;

    Book book = inputBook(&status);
    if(status == OK)
        status = writeBookToFile(filename, &book);
    
    if(status == OK)
        printf("Book saved!\n");

    return status;
}

programmCodes menuDeleteBooks(char* filename) {
    programmCodes status = OK;

    char authorToDelete[LEN];
    getLine(authorToDelete);

    status = deleteBooksByAuthor(filename, authorToDelete);
    if(status == OK)
        printf("Books have been deleted!\n");

    return status;
}

programmCodes menuSortBooks(char* filename) {
    programmCodes status = OK;

    status = sortBooksByRank(filename);

    if(status == OK)
        printf("Books sorted!\n");

    return status;
}

int main() {
    programmCodes endCode = OK;

    char* filename = "books.txt";

    int menuChoise = 0;
    int exitFlag = 0;
    while(!exitFlag) {
        endCode = OK;

        printf("1. Add Book\n2. Print All Books\n3. Delete Books By Author\n4. Sort Books By Rank\n5. Exit programm\n");

        int inputResult = numInput(&menuChoise);
        if(!inputResult)
            endCode = INPUT_ERROR;
        
        if(endCode == OK) {
            if(menuChoise == MENU_ADD_BOOK)
                menuAddBook(filename);
            else if(menuChoise == MENU_PRINT_BOOKS)
                readBooksFromFile(filename);
            else if(menuChoise == MENU_DELETE_BOOKS)
                menuDeleteBooks(filename);
            else if(menuChoise == MENU_SORT_BOOKS)
                menuSortBooks(filename);
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