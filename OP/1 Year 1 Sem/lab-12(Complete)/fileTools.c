#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include "fileTools.h"
#include "baseFunctions.h"

static long getFileSize(char* filename, programmCode* code) {
    long size = 0;

    FILE* file = fopen(filename, "rb");

    if (!file)
        *code = FILE_OPEN_ERROR;
    else {
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        fclose(file);
    }

    return size;
}

static int truncateFile(char* filename, long newSize) {
    int result = OK;
    FILE* file = fopen(filename, "rb+");

    if (!file)
        result = FILE_OPEN_ERROR;
    else {
        int fd = _fileno(file);
        result = _chsize_s(fd, newSize);

        fclose(file);
    }
    return result == OK;
}

static void swapBooks(char* filename, int bookIndexA, int bookIndexB, programmCode* code) {
    FILE* file = fopen(filename, "rb+");
    if (!file)
        *code = FILE_OPEN_ERROR;
    else {
        Book tempBookA, tempBookB;

        fseek(file, bookIndexA * bookSize, SEEK_SET);
        fread(&tempBookA, bookSize, 1, file);
        fseek(file, bookIndexB * bookSize, SEEK_SET);
        fread(&tempBookB, bookSize, 1, file);

        fseek(file, bookIndexB * bookSize, SEEK_SET);
        fwrite(&tempBookA, bookSize, 1, file);
        fseek(file, bookIndexA * bookSize, SEEK_SET);
        fwrite(&tempBookB, bookSize, 1, file);

        fclose(file);
    }
}

int getTotalBooks(char* filename, programmCode* code) {
    int result = 0;

    long fileSize = getFileSize(filename, code);
    if(*code == OK)
        result = fileSize / bookSize;

    return result;
}

programmCode saveBook(char* filename, Book book) {
    programmCode result = OK;
    FILE* file = fopen(filename, "ab");
    if (file == NULL)
        result = FILE_OPEN_ERROR;
    else {
        fwrite(&book, bookSize, 1, file);
        fclose(file);
    }
    return result;
}

Book loadBook(char* filename, int index, programmCode* code) {
    Book readBook = {"", "", 0, 0};

    FILE* file = fopen(filename, "rb");
    if (!file)
        *code = FILE_OPEN_ERROR;
    else {
        long offset = (long)index * bookSize;
        if (fseek(file, offset, SEEK_SET) != 0 || fread(&readBook, bookSize, 1, file) != 1) {
            *code = BOOK_LOAD_ERROR;
        }
        fclose(file);
    }

    return readBook;
}

programmCode readBooks(char* filename) {
    programmCode result = OK;

    FILE* file = fopen(filename, "rb");
    if (file == NULL)
        result = FILE_OPEN_ERROR;
    else {
        Book readbook;
        while (fread(&readbook, bookSize, 1, file) == 1)
            printBook(readbook);
        fclose(file);
    }

    return result;
}

programmCode deleteBook(char* filename, int index, int totalBooks) {
    programmCode result = OK;

    FILE* file = fopen(filename, "rb+");
    if (!file)
        result = FILE_OPEN_ERROR;
    else {
        long delOffset = (long)index * bookSize;
        for(long offset = delOffset + bookSize; offset < (long)(totalBooks * bookSize); offset += bookSize) {
            Book tempBook;
            fseek(file, offset, SEEK_SET);
            fread(&tempBook, bookSize, 1, file);
            fseek(file, offset - bookSize, SEEK_SET);
            fwrite(&tempBook, bookSize, 1, file);
        }

        fclose(file);

        if(!truncateFile(filename, (totalBooks - 1) * bookSize))
            result = FILE_SAVE_ERROR;
    }
    return result;
}

programmCode sortBooks(char* filename, int totalBooks) {
    programmCode result = OK;

    for (int i = 0; i < totalBooks - 1 && result == OK; i++) {
        for (int j = 1; j < totalBooks - i && result == OK; j++) {

            Book prevBook = loadBook(filename, j - 1, &result);
            Book curBook = loadBook(filename, j, &result);

            if (result == OK)
                if (prevBook.Rank > curBook.Rank || (prevBook.Rank == curBook.Rank && strcmp(prevBook.Name, curBook.Name) > 0))
                    swapBooks(filename, j - 1, j, &result);
        }
    }

    return result;
}


Book inputBook(programmCode* code) {
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