#include <stdio.h>
#include <stdlib.h>
#include "studentTools.h"

void* allocateMemory(int size, int bytes) {
    return calloc(size, bytes);
}

void freeMemory(void* array) {
    free(array);
}

int numInput(int* num) {
    return scanf("%d", num);
}

void output(programmCode code, Student* students, int numOfStudents, int counter[GRADES]) {
    if(code == OK) {
        for(int grade = A; grade >= D; grade--) {
            if(grade == A && counter[A - GRADE_OFFSET] != 0)
                printf("\nA-students:\n");
            else if(grade == B  && counter[B - GRADE_OFFSET] != 0)
                printf("\nB-students:\n");
            else if(grade == C  && counter[C - GRADE_OFFSET] != 0)
                printf("\nC-students:\n");
            else if(grade == D && counter[D - GRADE_OFFSET] != 0)
                printf("\nD-students:\n");
            for(int index = 0; index < numOfStudents; index++) {
                if(students[index].type == (studentType)grade)
                    printStudent(students[index]);
            }
        }
    } else if(code == INPUT_ERROR)
        printf("Incorrect input");
    else
        printf("Memory error");
}


int main() {
    programmCode endCode = OK;

    int numOfStudents = 0;
    int inputResult = numInput(&numOfStudents);
    Student *students = NULL;

    int counter[GRADES] = {0, 0, 0, 0};

    if(inputResult && numOfStudents > 0) {
        students = allocateMemory(numOfStudents, sizeof(Student));
        if(!students)
            endCode = MEMORY_ERROR;
    } else
        endCode = INPUT_ERROR;

    if(endCode == OK)
        endCode = inputStudents(&students, numOfStudents);

    if(endCode == OK) {
        sortStudents(students, numOfStudents);
        groupStudents(&students, numOfStudents, counter);
    }

    output(endCode, students, numOfStudents, counter);       
    
    freeMemory(students);
    return endCode;
}