#include "logic.h"
#include <string.h>

int state = 0;

const char* get_new_text(const char* input)
{
    const char* amogus = "Amogus";
    const char* sugoma = "Sugoma";

    const char* yo = "yes";
    if(strcmp(input, yo) == 0)
        return sugoma;
    else
        return amogus;
}
