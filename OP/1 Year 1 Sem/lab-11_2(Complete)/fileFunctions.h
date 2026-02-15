#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#define LEN 255

typedef struct {
    char Name[LEN];
    char Author[LEN];
    int PageCount;
    int Rank;
} Book;

int loadBook(char* filename, int index, Book* result);
void readBooksFromFile(char* filename);
int writeBookToFile(char* filename, Book* book);

int deleteBooksByAuthor(char* filename, char* authorToDelete);
int sortBooksByRank(char* filename);

#endif