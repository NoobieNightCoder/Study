#ifndef FILETOOLS_H
#define FILETOOLS_H

#include "baseFunctions.h"

typedef struct {
    char Name[LEN];
    char Author[LEN];
    int PageCount;
    int Rank;
} Book;

#define bookSize sizeof(Book)

int getTotalBooks(char* filename, programmCode* code);

programmCode saveBook(char* filename, Book book);
Book loadBook(char* filename, int index, programmCode* code);
programmCode readBooks(char* filename);
programmCode deleteBook(char* filename, int index, int totalBooks);

programmCode sortBooks(char* filename, int totalBooks);

Book inputBook(programmCode* code);
void printBook(Book book);


#endif