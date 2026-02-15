#include "logic.h"

int state = 0;

const char* get_new_text(void)
{
    const char* sugoma = "Sugoma";
    const char* amogus = "Amogus";

    if(state) {
        state = 0;
        return sugoma;
    } else {
        state = 1;
        return amogus;
    }
}
