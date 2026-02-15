#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileFunctions.h"
#include "baseFunctions.h"
#include "memory.h"

static void bubbleSort(Book** books, int count) {
    for (int i = 1; i < count; i++) {
        Book tempBook = (*books)[i];
        int j = i - 1;

        while (j >= 0 && (*books)[j].Rank > tempBook.Rank) {
            (*books)[j + 1] = (*books)[j];
            j--;
        }
        (*books)[j + 1] = tempBook;
    }
}

static int clearFile(char* filename) {
    int status = OK;

    FILE* file = fopen(filename, "w");
    if (file)
        fclose(file);
    else
        status = FILE_OPEN_ERROR;
    
    return status;
}

int loadBook(char* filename, int index, Book* result) {
    int status = OK;

    FILE *file = fopen(filename, "r");
    if (!file) {
        status = FILE_OPEN_ERROR;
    } else {
        Book tempBook;
        int currentIndex = 0;
        int flag = 0;

        while (fgets(tempBook.Name, LEN, file) &&
            fgets(tempBook.Author, LEN, file) &&
            fscanf(file, "%d\n", &tempBook.PageCount) &&
            fscanf(file, "%d\n", &tempBook.Rank) &&
            !flag) {
            if (currentIndex == index) {
                tempBook.Name[strcspn(tempBook.Name, "\n")] = '\0';
                tempBook.Author[strcspn(tempBook.Author, "\n")] = '\0';
                *result = tempBook;
                flag = 1;
            }
            currentIndex++;
        }

        if(!flag)
            status = FILE_LOAD_ERROR;

        fclose(file);
    }

    return status;
}

void readBooksFromFile(char* filename) {
    Book book;
    int i = 0;
    while(loadBook(filename, i, &book) == OK) {
        printBook(book);
        i++;
    }
}

int writeBookToFile(char* filename, Book* book) {
    int status = OK;

    FILE* file = fopen(filename, "a");

    if (!file)
        status = FILE_OPEN_ERROR;
    else {
        fprintf(file, "%s\n", book->Name);
        fprintf(file, "%s\n", book->Author);
        fprintf(file, "%d\n", book->PageCount);
        fprintf(file, "%d\n", book->Rank);

        fclose(file);
    }

    return status;
}

int deleteBooksByAuthor(char* filename, char* authorToDelete) {
    int status = OK;

    FILE* tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL)
        status = FILE_TEMP_ERROR;
    else {
        Book book;
        int i = 0;

        while (loadBook(filename, i, &book) == OK) {
            book.Author[strcspn(book.Author, "\n")] = '\0';

            if (strcmp(book.Author, authorToDelete) != 0) {
                fprintf(tempFile, "%s", book.Name);
                fprintf(tempFile, "%s\n", book.Author);
                fprintf(tempFile, "%d\n", book.PageCount);
                fprintf(tempFile, "%d\n", book.Rank);
            }
            i++;
        }
        fclose(tempFile);

        remove(filename);
        rename("temp.txt", filename);
    }
    return status;
}

int getBooksCount(char* filename) {
    int result = 0;

    Book tempBook;
    while (loadBook(filename, result, &tempBook) == OK)
        result++;

    return result;
}

int sortBooksByRank(char* filename) {
    int status = OK;

    Book* books = NULL;
    int count = getBooksCount(filename);

    if(count == 0)
        status = FILE_LOAD_ERROR;

    if(status == OK) {
        books = allocateMemory(count, sizeof(Book));
        if (!books)
            status = MEMORY_ERROR;
    }

    for (int i = 0; i < count && status == OK; i++) {
        status = loadBook(filename, i, &books[i]);
        if (status != OK)
            books = freePtr(books);
    }

    if(status == OK)
        bubbleSort(&books, count);
    
    status = clearFile(filename);

    for (int i = 0; i < count && status == OK; i++) {
        status = writeBookToFile(filename, &books[i]);
        if (status != OK)
            books = freePtr(books);
    }

    freePtr(books);

    return status;
}