#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#define BUFFER 128

char* readOneLine(FILE* file, int* status);
char** readFile(char* filename, int* numLines);
int saveFile(char* filename, char** lines, int numLines);

#endif