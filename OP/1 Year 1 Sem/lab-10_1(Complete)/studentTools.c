#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentTools.h"

// MAIN FUNCTIONS //

static int numInput(int* num) {
    return scanf("%d", num);
}

void swapStudents(Student* studentA, Student* studentB) {
    Student studentTemp = *studentA;
    *studentA = *studentB;
    *studentB = studentTemp;
}

// FUNCTIONS //

programmCode inputStudents(Student** students, int numOfStudents) {
    programmCode result = OK;

    for(int index = 0; index < numOfStudents && result == OK; index++) {
        char ch = ' ';
        getchar();
        for(int i = 0; i < NAME_LEN && ch != '\n'; i++) {
            ch = getchar();
            if(ch != '\n')
                (*students)[index].surname[i] = ch;
            else
                (*students)[index].surname[i] = '\0';
        }

        if((*students)[index].surname[0] == '\0')
            result = INPUT_ERROR;

        for(int i = 0; i < GRADES && result == OK; i++) {
            int grade = 0;
            int gradeInput = numInput(&grade);
            if(gradeInput && grade >= D && grade <= A)
                (*students)[index].grade[i] = grade;
            else
                result = INPUT_ERROR;
        }
    }

    return result;
}

void sortStudents(Student* students, int numOfStudents) {
    for (int iteration = 0; iteration < numOfStudents; iteration++) {
        for (int index = 1; index < numOfStudents; index++) {
            int compareResult = strcmp(students[index - 1].surname, students[index].surname);
            if (compareResult == 1)
                swapStudents(&students[index - 1], &students[index]);
        }
    }
}

void groupStudents(Student** students, int numOfStudents, int counter[GRADES]) {
    for(int index = 0; index < numOfStudents; index++) {
        int smallestGrade = (*students)[index].grade[0];
        for(int i = 1; i < GRADES; i++) {
            if(smallestGrade > (*students)[index].grade[i])
                smallestGrade = (*students)[index].grade[i];
        }
        (*students)[index].type = (studentType)smallestGrade;
        counter[smallestGrade - GRADE_OFFSET] += 1;
    }
}

// OUTPUT //

void printStudent(Student student) {
    printf("%s\n", student.surname);
    for(int index = 0; index < GRADES; index++)
        printf("%d ", student.grade[index]);
    printf("\n");
}