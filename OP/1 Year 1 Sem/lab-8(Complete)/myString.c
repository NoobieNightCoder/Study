#include <stdio.h>
#include <stdlib.h>
#include "myString.h"

#define PUNCTS ",.?!;:()-"

static int isPunct(char c) {
    const char* puncts = PUNCTS;
    int is = 0;
    size_t i = 0;
    while (!is && puncts[i] != '\0') {
        if (puncts[i] == c) is = 1;
        i++;
    }
    return is;
}

void* createStr(void* ptr, size_t newSize) {
    void* result = NULL;
    if (newSize > 0)
        result = realloc(ptr, newSize);
    return result;
}

void freeStr(char* str) {
    free(str);
}

void freeStrArray(char** strArr, int strCount) {
    if (strArr != NULL) {
        for (int i = 0; i < strCount; i++)
            freeStr(strArr[i]);
        free(strArr);
    }
}

char* strCopy(const char* str) {
    char* result = NULL;
    size_t len = 0;
    if (str != NULL) {
        len = strSize(str);
        result = createStr(NULL, len + 1);
        if (result != NULL) {
            for (size_t i = 0; i < len; ++i) result[i] = str[i];
            result[len] = '\0';
        }
    }
    return result;
}

char* strConcat(char* base, const char* tail) {
    char* result = base;
    if (tail != NULL) {
        size_t baseLen = strSize(base);
        size_t tailLen = strSize(tail);
        size_t newSize = baseLen + tailLen + 1;
        char* buffer = createStr(result, newSize);
        if (buffer != NULL) {
            result = buffer;
            for (size_t i = 0; i < tailLen; ++i) result[baseLen + i] = tail[i];
            result[baseLen + tailLen] = '\0';
        } else {
            freeStr(base);
        }
    }
    return result;
}

char* getLine() {
    char* result = NULL;
    size_t size = 0;
    int done = 0;
    while (!done) {
        char ch = getchar();
        if (ch == EOF || ch == '\n') {
            done = 1;
        } else {
            char* buffer = createStr(result, size + 2);
            if (buffer == NULL) {
                freeStr(result);
                result = NULL;
                done = 1;
            } else {
                result = buffer;
                result[size++] = ch;
            }
        }
    }
    if (result != NULL) result[size] = '\0';
    return result;
}

size_t strSize(const char* str) {
    size_t len = 0;
    if (str != NULL) {
        while (str[len] != '\0') ++len;
    }
    return len;
}

int findSymbol(const char* str, char target) {
    int index = -1;
    if (str != NULL) {
        size_t i = 0;
        while (str[i] != '\0' && index == -1) {
            if (str[i] == target) index = (int)i;
            ++i;
        }
    }
    return index;
}

int rFindSymbol(const char* str, char target) {
    int index = -1;
    if (str != NULL) {
        size_t len = strSize(str);
        if (len > 0) {
            for (int i = (int)len - 1; i >= 0 && index == -1; --i) {
                if (str[i] == target) index = i;
            }
        }
    }
    return index;
}

int findStr(const char* str, const char* target) {
    int index = -1;
    if (str != NULL && target != NULL) {
        size_t start = 0;
        size_t targetLen = strSize(target);
        if (targetLen == 0) {
            index = 0;
        } else {
            while (str[start] != '\0' && index == -1) {
                size_t i = 0;
                while (target[i] != '\0' && str[start + i] != '\0' && str[start + i] == target[i]) i++;
                if (i == targetLen) index = (int)start;
                start++;
            }
        }
    }
    return index;
}

int rFindStr(const char* str, const char* target) {
    int index = -1;
    if (str != NULL && target != NULL) {
        size_t strLen = strSize(str);
        size_t targetLen = strSize(target);
        if (targetLen == 0) {
            index = strLen == 0 ? 0 : (int)strLen - 1;
        } else if (strLen >= targetLen) {
            for (int start = (int)(strLen - targetLen); start >= 0 && index == -1; --start) {
                size_t i = 0;
                while (i < targetLen && str[start + i] == target[i]) ++i;
                if (i == targetLen) index = start;
            }
        }
    }
    return index;
}

char* cutStr(char* str, int start, int end) {
    char* result = str;
    if (str != NULL && start >= 0 && end >= start) {
        int size = (int)strSize(str);
        if (size > 0) {
            if (end >= size) end = size - 1;
            int j = 0;
            for (int i = start; i <= end; i++) {
                str[j++] = str[i];
            }
            str[j] = '\0';
            char* buffer = createStr(str, (size_t)j + 1);
            if (buffer != NULL) result = buffer;
        }
    }
    return result;
}

char* deleteSymbol(char* str, int index) {
    char* result = str;
    if (str != NULL && index >= 0) {
        int size = (int)strSize(str);
        if (index < size) {
            for (int i = index; i < size; i++) str[i] = str[i + 1];
            char* buffer = createStr(str, (size_t)size);
            result = buffer;
        }
    }
    return result;
}

char* replaceStr(char* s, int index, const char* subs) {
    char* result = s;
    if (s != NULL && index >= 0 && subs != NULL) {
        int keepUntil = index - 1;
        result = cutStr(result, 0, keepUntil);
        if (result != NULL)
            result = strConcat(result, subs);
    }
    return result;
}

char* formatStr(char* str) {
    char* result = str;
    if (result != NULL) {
        while (result[0] == ' ') result = deleteSymbol(result, 0);
        size_t i = 0;
        while (result[i] != '\0') {
            if (result[i] == ' ') {
                while (result[i + 1] == ' ') result = deleteSymbol(result, (int)i);
                if (isPunct(result[i + 1])) result = deleteSymbol(result, (int)i);
            }
            i++;
        }
        size_t size = strSize(result);
        while (size > 0 && result[size - 1] == ' ') {
            result = deleteSymbol(result, (int)size - 1);
            size = strSize(result);
        }
    }
    return result;
}

void printStr(const char* str) {
    printf("%s\n", str);
}