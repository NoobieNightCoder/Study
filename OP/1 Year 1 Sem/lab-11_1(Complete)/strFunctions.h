#ifndef STRFUNCTIONS_H
#define STRFUNCTIONS_H

#include <stdio.h>

#define NUM_BUFFER 16

char* readLine();


int isStrEmpty(char* str);
int appendChar(char** line, size_t* len, char ch);
int pushLine(char*** lines, int* numLines, char* line);
void removeLine(char** lines, int* numLines, int index);
void intToStr(int value, char* str);
void indexLines(char** lines, int numLines);


void printLines(char** lines, int numLines);

#endif