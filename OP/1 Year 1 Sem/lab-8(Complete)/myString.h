#ifndef MYSTRING_H
#define MYSTRING_H

void* createStr(void* ptr, size_t newSize);
void freeStr(char* str);
void freeStrArray(char** strArray, int strCount);

char* getLine();
size_t strSize(const char* str);
char* strCopy(const char* str);
char* strConcat(char* base, const char* tail);

int findSymbol(const char* str, char target);
int rFindSymbol(const char* str, char target);
int findStr(const char* str, const char* target);
int rFindStr(const char* str, const char* target);
char* replaceStr(char* s, int index, const char* subs);
char* deleteSymbol(char* str, int index);
char* cutStr(char* str, int start, int end);
char* formatStr(char* str);

void printStr(const char* str);

#endif