#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10


typedef struct{
    char fName[50];
    char lName[50];
    char middleInitial;
}name;

typedef struct{
    name studentName;
    int idNum;
    int studentGrades[3];
}studentDetail;

typedef struct{
    studentDetail student[MAX];
    int count;
}classRecord;

typedef struct{
	classRecord classList;
	classRecord examRetake[3];
}classResults;

void populate(classRecord *,int);
studentDetail addStudent(char *fName,char *lName,char mi,int idNum,int grades[5]);
void checkExams(classResults *results);


int main(){
	int i=0;
	int classCount;
    classResults results;
    results.classList.count=0;
    classRecord record;
   
    results.examRetake[0].count=0;
    results.examRetake[1].count=0;
    results.examRetake[2].count=0;
    
    printf("Input Number of Students in Class:" );
    scanf("%d",&classCount);
    
      /*CODE TO FIRST CHECK IF CLASS SIZE IS CORRECT*/
    if(classCount > 10){
        printf("Maximum Number of Students per Class is only 10");
    } else {
        /*FUNCTION CALL TO POPULATE THE ARRAY*/
        //results.classList = record;
        populate(&results.classList,classCount);
        
        
        /*FUNCTION CALL TO CHECK WHO NEEDS TO RETAKE WHICH EXAMS*/
        checkExams(&results);
        
        /*DISPLAY*/
        for(int j = 0; j < 3; j++) {
                printf("Retakers Needed for Exam %d:",j + 1);
                if(results.examRetake[j].count == 0){
                    printf("No Retakers for Exam %d", j + 1);
                } else if(results.examRetake[j].count == classCount){
                    printf("All Students Have to Retake Exam %d", j+1);
                } else {
                    for(int i = 0; i < results.examRetake[j].count; i++){
                        printf("%s ",results.examRetake[j].student[i].studentName.fName);
                    }
                }
                printf("\n\n");
        }
        
    }
    
}

void checkExams(classResults *results){
//WRITE CODE TO CHECK WHO NEEDS TO RETAKE WHICH EXAMS
    for(int i = 0; i < results->classList.count; i++){
        for(int j = 0; j < 3; j++){
            if(results->classList.student[i].studentGrades[j] < 60){
                results->examRetake[j].student[results->examRetake[j].count++] = results->classList.student[i];
            }
        }
    }
}

void populate(classRecord *record,int classCount){
	int i=0;
	int x=0;
	char fName[50];
	char lName[50];
	char MI;
	int idNum;
	int grades[3];
	for(i=0;i<classCount;i++){
    	printf("===STUDENT %d===\n\n",i+1);
    
        printf("Input First Name: ");
        scanf(" %s", &fName);
        printf("Input Last Name: ");
        scanf(" %s", &lName);
        printf("Input Middle Initial: ");
        scanf(" %c", &MI);
        printf("Input ID Number: ");
        scanf(" %d", &idNum);
        printf("Input Exam Score 1: ");
        scanf(" %d", &grades[0]);
        printf("Input Exam Score 2: ");
        scanf(" %d", &grades[1]);
        printf("Input Exam Score 3: ");
        scanf(" %d", &grades[2]);
        //CONTINUE CODE TO POPULATE STUDENTS HERE
    	
    	record->student[i]=addStudent(fName,lName,MI,idNum,grades);
    	record->count++;
	}

	
}

studentDetail addStudent(char *fName,char *lName,char mi,int idNum,int grades[3]){
	int i=0;
	
    studentDetail details;

    details.studentName.middleInitial=mi;
    strcpy(details.studentName.fName,fName);
    strcpy(details.studentName.lName,lName);   

    details.idNum=idNum;

	for(i=0;i<3;i++){
		 details.studentGrades[i]=grades[i];
	}
   
    return details;
}