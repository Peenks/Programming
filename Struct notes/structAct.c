#include <stdio.h>
#include <string.h>

typedef struct {
    char fName[20];
    char lName[20];
} Name;

typedef struct {
    char program[20];
    int year;
} Program;

typedef struct {
    char course[20];
    float gwa;
    int courseStatus;   // 0 - failed, 1 - passed
} Course;

// Holds all student related information
typedef struct {
    Name name;
    Program program;
    Course course;
    char studentId[10];
} Student;

// Holds all the count information of the students
typedef struct {
    int totalStudents;
    int failedStudentsCount;
} StudentCount;

// Holds all information about the class and its students.
typedef struct {
    Student students[10];
    Student failedStudents[10];
    StudentCount studentCount;
} Class;


void initClass(Class* A){
    A->studentCount.totalStudents = 0;
    A->studentCount.failedStudentsCount = 0;
}

void populate(Class* A){
    Student db[10] = {
        { {"Achille", "Lanutan"}, {"BSIT", 3}, {"DSA", 2.2, 1}, "22103514" },
        { {"Andrei", "Go"},       {"BSCS", 2}, {"PROG1", 3.5, 0}, "22103515" },
        { {"Simone", "Montañez"}, {"BSIS", 1}, {"PROG2", 4.0, 0}, "22103516" },
        { {"Edouard", "Ybañez"}, {"BSIT", 4}, {"DSA", 1.5, 1}, "22103517" },
        { {"Benjiro", "Bahinting"},{"BSCS", 2}, {"PROG1", 3.0, 1}, "22103518" },
        { {"Shiori", "Morisaka"}, {"BSIT", 1}, {"PROG2", 2.8, 1}, "22103519" },
        { {"Joshua", "Collamat"}, {"BSIS", 3}, {"DSA", 3.9, 0}, "22103520" },
        { {"Sean", "Garcines"},   {"BSCS", 4}, {"PROG1", 2.5, 1}, "22103521" },
        { {"Matthew", "Calaycay"},{"BSIT", 2}, {"PROG2", 3.2, 0}, "22103522" },
        { {"Sarah", "Palabrica"}, {"BSIS", 3}, {"DSA", 3.7, 0}, "22103523" }
    };
  
    int j = 0;
    for(int i = 0; i < 10; i++){
        A->students[i] = db[j++]; 
        A->studentCount.totalStudents++;
    }
}

char* getStatusString(int status){
    // Start writing your code here.
    if(status == 0){
        return "FAILED";
    } else {
        return "PASSED";
    }
}

void displayAllStudents(Class A){
    printf("\nTotal Students: %d", A.studentCount.totalStudents);
    printf("\n%-15s%-15s%-15s%-10s%-7s%-10s%-7s%-7s",
        "Student ID",
        "First Name",
        "Last Name",
        "Program",
        "Year",
        "Course",
        "GWA",
        "Status"
    );
    printf("\n");
    for(int i = 0; i < A.studentCount.totalStudents; i++){
        printf("%-15s%-15s%-15s%-10s%-7d%-10s%-7.2f%-7s\n",
            A.students[i].studentId,
            A.students[i].name.fName,
            A.students[i].name.lName,
            A.students[i].program.program,
            A.students[i].program.year,
            A.students[i].course.course,
            A.students[i].course.gwa,
            getStatusString(A.students[i].course.courseStatus)
        );
    }
}

void displayFailedStudents(Class A){
    printf("\nTotal Failed Students: %d", A.studentCount.failedStudentsCount);
    printf("\n%-15s%-15s%-15s%-10s%-7s%-10s%-7s%-7s",
        "Student ID",
        "First Name",
        "Last Name",
        "Program",
        "Year",
        "Course",
        "GWA",
        "Status"
    );
    printf("\n");
    for(int i = 0; i < A.studentCount.failedStudentsCount; i++){
        printf("%-15s%-15s%-15s%-10s%-7d%-10s%-7.2f%-7s\n",
            A.failedStudents[i].studentId,
            A.failedStudents[i].name.fName,
            A.failedStudents[i].name.lName,
            A.failedStudents[i].program.program,
            A.failedStudents[i].program.year,
            A.failedStudents[i].course.course,
            A.failedStudents[i].course.gwa,
            getStatusString(A.failedStudents[i].course.courseStatus)
        );
    }
}

int separateFailedStudents(Class* A){
    
    int j = 0;
    for(int i = 0; i < A->studentCount.totalStudents; i++){
        if(A->students[i].course.courseStatus == 0){
            A->failedStudents[j] = A->students[i];
            j++;
        }
    }
    A->studentCount.failedStudentsCount = j;
    printf("\nSuccessfully separated failed students.");
    return j;
}

char* deleteStudent(Class* A, char* deleteId){
    for(int i = 0; i < A->studentCount.totalStudents; i++){
        if(strcmp(A->students[i].studentId, deleteId) == 0){
            for(int j = i; j < A->studentCount.totalStudents - 1; j++){
                A->students[j] = A->students[j + 1];
            }
            A->studentCount.totalStudents--;
            return deleteId;
        }
    }
    return "XXXXX";
}


int main(){
    
    Class group2;
    
    initClass(&group2);
    
    populate(&group2);
   
    displayAllStudents(group2);

   
    printf("\n\nTotal Failed: %d", separateFailedStudents(&group2));
   
    displayFailedStudents(group2);

    
    printf("\nDeleted Student: %s", deleteStudent(&group2, "22103514"));
    printf("\nDeleted Student: %s", deleteStudent(&group2, "22103519"));
    printf("\nDeleted Student: %s", deleteStudent(&group2, "12345678"));// This should return "XXXXX"
    
    displayAllStudents(group2);

    return 0;
}