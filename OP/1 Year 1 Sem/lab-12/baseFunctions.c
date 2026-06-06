#include <stdio.h>
#include <stdlib.h>
#include "baseFunctions.h"

int numInput(int* num) {
    int result = scanf("%d", num);
    getchar();

    return result;
}

void getLine(char str[LEN]) {
    int flag = 0;
    for(int index = 0; index < LEN && !flag; index++) {
        char letter = getchar();
        if(letter == '\n') {
            str[index] = '\0';
            flag = 1;
        } else
            str[index] = letter;
    }
    if(!flag)
        str[LEN - 1] = '\0';
}



int ascending(int a, int b)  {
    return a < b;
}

int descending(int a, int b) {
    return a > b;
}



void outputError(programmCode code) {
    if(code == INPUT_ERROR) printf("Incorrect input\n");
    else if(code == FILE_OPEN_ERROR) printf("Error opening file\n");
    else if(code == FILE_SAVE_ERROR) printf("Error saving file\n");
    else if(code == BOOK_LOAD_ERROR) printf("Index out of range or read error\n");
}