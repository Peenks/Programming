#include <stdio.h>
#include <stdlib.h>
#define STRING_MAX 50
#define LIST_MAX 10

typedef struct{
	int month;
	int year;
}currentDate;
typedef struct{
	int hireMonth;
	int hireYear;
}hiringDetails;

typedef struct{
	char fName[STRING_MAX];
}empDetails;

typedef struct{
	hiringDetails dateOfHire;
	empDetails employeeInfo;
}employee;

typedef struct{
	employee employeeList[LIST_MAX];
	int count;
}employeeRecords;

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate,int employeeCount);
void display(employee *loyalList,int loyalListCount);

int main(){
	employeeRecords record;
	int employeeCount;
	int loyalListCount=0;
	record.count=0;
	employee *loyalList;
	currentDate date={07,2023};
	
	int i=0;
	printf("Input Number of Employees:" );
    scanf("%d",&employeeCount);
    
    printf("\nInput Details for Employees: \n");
    for(i=0;i<employeeCount;i++){
    	printf("\n\n===Employee %d===\n",i+1);
    	printf("Input First Name: ");
    	scanf("%s", &record.employeeList[i].employeeInfo.fName);
    	printf("Input Month of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireMonth);
    	printf("Input Year of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireYear);
	}
	
	loyalList=getLoyalList(record,&loyalListCount,date,employeeCount);
	
	display(loyalList,loyalListCount);
	
	return 0;
}

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate,int employeeCount){
    
    for(int i = 0; i < employeeCount; i++){
        int diff = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        if(diff > 5){
            (*loyalListCount)++;
        } else if(diff == 5 && record.employeeList[i].dateOfHire.hireMonth <= 7){
            (*loyalListCount)++;
        }
    }
    
    employee *loyalList = malloc(sizeof(int) * (*loyalListCount));
    
     int j = 0;
   for(int i = 0; i < employeeCount; i++){
        int diff = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        if(diff > 5){
            loyalList[j++] = record.employeeList[i];
        } else if(diff == 5 && record.employeeList[i].dateOfHire.hireMonth <= 7){
            loyalList[j++] = record.employeeList[i];
        }
    }
    
    return loyalList;
}

void display(employee *loyalList,int loyalListCount){
   
    
    if(loyalListCount > 0){
         printf("Loyal List: \n\n");
            for(int i = 0; i < loyalListCount; i++){
                
                printf("Name: %s -- Hire Date:%d-%d\n", 
                loyalList[i].employeeInfo.fName, 
                loyalList[i].dateOfHire.hireMonth,
                loyalList[i].dateOfHire.hireYear);
        }
    } else {
        printf("There are currently no Employees who are eligible for the reward.");
    }
}