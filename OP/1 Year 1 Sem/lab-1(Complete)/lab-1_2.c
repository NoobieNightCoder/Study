#include <stdio.h>
#include <math.h>

#define REQ_INPUT 2
#define EPS 0.000001

// STATUS CODES //
typedef enum {
    INPUT_ERROR = 0,
    REG1    = 1,
    REG2    = 2,
    REG3    = 3,
    REG4    = 4,
    REG5    = 5,
    REG6    = 6,
    REG7    = 7,
    LINE1   = 8,
    LINE2   = 9,
    LINE3   = 10,
    LINE12  = 11,
    LINE13  = 12,
    LINE23  = 13
} lineCodes;

typedef enum {
    OK = 0,
    PROGRAMM_ERROR = 1
} programmCodes;

int input(float* x, float* y) {
    printf("Line equations:\ny = 2x + 2\ny = -x + 2\ny = 0.5x - 1\nPlease insert coordinates of the point: ");
    
    int result = scanf("%f %f", x, y);
    return result;
}

int above(float dot, float line) {
    int result = (dot > line + EPS);
    return result;
}

int on(float dot, float line) {
    int result = (fabs(line - dot) <= EPS);
    return result;
}

int below(float dot, float line) {
    int result = (dot < line - EPS);
    return result;
}

int check(float dotX, float dotY) {
    lineCodes result;

    float lineY1 = (2 * dotX) + 2;
    float lineY2 = (0.5 * dotX) - 1;
    float lineY3 = -dotX + 2;
    
    // REGIONS //
    if     (below(dotY, lineY1) && above(dotY, lineY2) && above(dotY, lineY3)) result = REG1;
    else if(below(dotY, lineY2) && above(dotY, lineY3))                        result = REG2;
    else if(below(dotY, lineY1) && below(dotY, lineY2) && below(dotY, lineY3)) result = REG3;
    else if(above(dotY, lineY1) && below(dotY, lineY2))                        result = REG4;
    else if(above(dotY, lineY1) && above(dotY, lineY2) && below(dotY, lineY3)) result = REG5;
    else if(above(dotY, lineY1) && above(dotY, lineY3))                        result = REG6;
    else if(below(dotY, lineY1) && above(dotY, lineY2) && below(dotY, lineY3)) result = REG7;
   
    // LINES //
    else {
        int line1 = on(dotY, lineY1), 
            line2 = on(dotY, lineY2), 
            line3 = on(dotY, lineY3);

        if(line1 && !line2 && !line3) result = LINE1;
        else if(!line1 && line2 && !line3) result = LINE2;
        else if(!line1 && !line2 && line3) result = LINE3;
        else if(line1 && line2 && !line3) result = LINE12;
        else if(line1 && !line2 && line3) result = LINE13;
        else result = LINE23;
    }
    return result;
}

void output(lineCodes statusCode) {
    if (statusCode == INPUT_ERROR) 
        printf("Result: Incorrect input");
    else if(statusCode >= REG1 && statusCode <= REG7)
        printf("Point placed in region %d", statusCode);
    else if(statusCode >= LINE1 && statusCode <= LINE3)
        printf("Point placed on line %d", statusCode - REG7);
    else if(statusCode == LINE12)
        printf("Point placed on lines 1 and 2");
    else if(statusCode == LINE13)
        printf("Point placed on lines 1 and 3");
    else if(statusCode == LINE23)
        printf("Point placed on lines 2 and 3");
}

int main() {
    float x, y;
    int inputStatus;
    programmCodes endProgramm = OK;
    lineCodes statusCode;

    inputStatus = input(&x, &y);
    if(inputStatus != REQ_INPUT) {
        statusCode = INPUT_ERROR;
        endProgramm = PROGRAMM_ERROR;
    } else {
        statusCode = check(x, y);
    }

    output(statusCode);
    return endProgramm;
}