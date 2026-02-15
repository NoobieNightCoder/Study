#ifndef STRPROCCESSFUNCTIONS_H
#define STRPROCCESSFUNCTIONS_H

typedef struct {
    char *word;
    int count;
    int order;
} WordEntry;

char* getLine();
int findWord(WordEntry* dict, int total, char* word);
void sortWords(WordEntry* dict, int total);
int addWord(WordEntry** dict, int* total, char* word, int* order);
int proccessText(char* text, WordEntry** dict, int* total);

#endif