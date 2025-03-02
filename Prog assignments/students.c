#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct THISSTUDENT {
    char studName[50];
    char studProgram[10];
    char studSex;
    float *grades;
} student;


student inputStudent(char name[], char program[], char sex, float grades[]) {
    student newStud;

    strcpy(newStud.studName, name);
    strcpy(newStud.studProgram, program);
    newStud.studSex = sex;

    newStud.grades = malloc(sizeof(float) * 5);

    for (int i = 0; i < 5; ++i) {
        newStud.grades[i] = grades[i];
    }

    return newStud;
}


float computeStudAvg(student s) {
    float sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += s.grades[i];
    }
    return sum / 5;  
}


void display(student stud[], int count) {
    printf("\n%-15s%-10s%-5s%-30s%-10s\n", "NAME", "PROGRAM", "SEX", "GRADES", "AVG");
    printf("------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; ++i) {
        printf("%-15s%-10s%-5c", stud[i].studName, stud[i].studProgram, stud[i].studSex);

        for (int j = 0; j < 5; ++j) {
            printf("%6.2f", stud[i].grades[j]);
            if (j < 4) {
                printf(", ");
            }
        }
        printf("  | %6.2f", computeStudAvg(stud[i]));  
        printf("\n");
    }
}


student getStudHighestAvgProgram(student stud[], int count, char program[]) {
    student *highestStud = NULL;
    float highestAvg = 0;

    for (int i = 0; i < count; ++i) {
        if (strcmp(stud[i].studProgram, program) == 0) { 
            float currentAvg = computeStudAvg(stud[i]);
            if (highestStud == NULL || currentAvg > highestAvg) {
                highestStud = &stud[i];
                highestAvg = currentAvg;
            }
        }
    }

    
        return *highestStud;
}


student getStudByName(student stud[], int count, char searchKey[]) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(stud[i].studName, searchKey) == 0) {
            return stud[i];
        }
    }

    printf("\nStudent named %s not found.\n", searchKey);
   
}


student getStudentHighestGrade(student stud[], int count) {
    int highestIndex = 0;
    float highestGrade = stud[0].grades[0];

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (stud[i].grades[j] > highestGrade) {
                highestGrade = stud[i].grades[j];
                highestIndex = i;
            }
        }
    }

    return stud[highestIndex];
}


student getStudHighestAvg(student stud[], int count) {
    int highestIndex = 0;
    float highestAvg = computeStudAvg(stud[0]);

    for (int i = 1; i < count; ++i) {
        float currentAvg = computeStudAvg(stud[i]);
        if (currentAvg > highestAvg) {
            highestAvg = currentAvg;
            highestIndex = i;
        }
    }

    return stud[highestIndex];
}

int main() {
    int count = 5;
    student stud[5];

   
    stud[0] = inputStudent("Justin", "BSCS", 'M', (float[]){88.5, 85.9, 92.3, 91.00, 95.00});
    stud[1] = inputStudent("Emily", "BSIT", 'F', (float[]){91.0, 84.5, 88.0, 79.5, 92.3});
    stud[2] = inputStudent("Alex", "BSIS", 'M', (float[]){78.5, 85.0, 90.0, 82.5, 87.0});
    stud[3] = inputStudent("Sophia", "BSCS", 'F', (float[]){92.5, 89.0, 95.5, 91.0, 93.5});
    stud[4] = inputStudent("Daniel", "BSIT", 'M', (float[]){80.0, 75.5, 88.5, 84.0, 79.5});

    
    display(stud, count);

   
    student highest = getStudHighestAvg(stud, count);
    printf("\nThe student with the highest average is: %s with an avg of %.2f\n",
           highest.studName, computeStudAvg(highest));

    
    student highestBSCS = getStudHighestAvgProgram(stud, count, "BSCS");
    printf("\nThe highest average in BSCS program is: %s with an avg of %.2f\n",
           highestBSCS.studName, computeStudAvg(highestBSCS));

   
    student foundStudent = getStudByName(stud, count, "Emily");
    printf("\nFound Student: %s from %s program\n", foundStudent.studName, foundStudent.studProgram);

    
    student highestGradeStud = getStudentHighestGrade(stud, count);
    printf("\nThe student with the highest single grade is: %s\n", highestGradeStud.studName);

  
    return 0;
}
