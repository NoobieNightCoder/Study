#ifndef STUDENTTOOLS_H
#define STUDENTTOOLS_H

// DEFINES //

#define NAME_LEN 20
#define GRADES 4
#define GRADE_OFFSET 2

typedef enum {
    OK,
    INPUT_ERROR,
    MEMORY_ERROR
} programmCode;

typedef enum {
    A = 5,
    B = 4,
    C = 3,
    D = 2
} studentType;

typedef struct {
    int grade[GRADES];
    studentType type;
    float averageGrade;
    char surname[NAME_LEN];
} Student;


// FUNCTIONS //

void swapStudents(Student* studentA, Student* studentB);

programmCode inputStudents(Student** students, int numOfStudents);
Student* deleteStudent(Student* students, int studentIndex, int* numOfStudents);
void sortStudents(Student* students, int numOfStudents);
void groupStudents(Student** students, int numOfStudents, int counter[GRADES]);
void defineAvgGradeOfStudents(Student** students, int numOfStudents);
void expulsionBadStudents(Student** students, int* numOfStudents);

void printStudent(Student student);

#endif