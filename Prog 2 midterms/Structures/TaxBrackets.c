#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define bracket1Rate 0.10
#define bracket2Rate 0.15
#define bracket3Rate 0.20

typedef struct{
    char fName[20];
    char lName[20];
    char MI;
}name;

typedef struct{
    name empName;
    int idNum;
    int grossSalary;
    int rate;
    int hrsWorked;
    float takeHomeSalary;
}employeeInfo;

typedef struct{
    employeeInfo *employees;
    //employeeInfo employees[MAX]; //Can use statically allocated array instead of above.
    // Do note only efficiently allocated arrays will be given full marks. e.g: An array that will contain 5 items, should only be allocated memory to accomodate those 5 items.
    int count;
}employeeRecord;

typedef struct{
    employeeRecord employeeList;
    employeeRecord bracket1; //Transfer all Employees who earn a grossSalary of 0-14,999, Tax rate = 10%, calculate takeHomeSalary here
    employeeRecord bracket2; //Transfer all Employees who earn a grossSalary of 15,000-25,999, Tax rate = 15%, calculate takeHomeSalary here
    employeeRecord bracket3; //Transfer all Employees who earn a grossSalary of 26,000 or higher, Tax rate = 20%, calculate takeHomeSalary here
}companyRecord;

void display(companyRecord);
employeeRecord populate(int);
employeeInfo newEmployee(int,int,int,name);
name addName(char [],char[],char);
void taxBracketSeparation(companyRecord *);

int main(){
    companyRecord companyLists;
    int i=0;
    int employeeInitialCount=0;


    printf("Input how many employees: ");
    scanf("%d",&employeeInitialCount);

    companyLists.employeeList=populate(employeeInitialCount);

    taxBracketSeparation(&companyLists);
    
	display(companyLists);


}


void taxBracketSeparation(companyRecord *companyList){
    /* This function will separate all employees from the employeeList and add them into 
    their appropriate Tax Bracket based on their Gross Pay. After which calculate their 
    Take Home pay based on their tax bracket rate. The function will take in a 
    companyRecord pointer and will not return anything. */


    	//WRITE CODE TO SEPARATE EMPLOYEE LIST INTO PROPER TAX BRACKETS AND THEN
        //CALCULATE THEIR TAKE HOME PAY
        
        
        companyList->bracket1.count = 0;
        companyList->bracket2.count = 0;
        companyList->bracket3.count = 0;
        int j = 0;
        
        
        companyList->bracket1.employees = malloc(sizeof(employeeInfo) * companyList->employeeList.count);
        companyList->bracket2.employees = malloc(sizeof(employeeInfo) * companyList->employeeList.count);
        companyList->bracket3.employees = malloc(sizeof(employeeInfo) * companyList->employeeList.count);
        
        for(int i = 0; i < companyList->employeeList.count; i++){
            if (companyList->employeeList.employees[i].grossSalary > 0 && companyList->employeeList.employees[i].grossSalary <= 14999){
                companyList->bracket1.employees[companyList->bracket1.count] = companyList->employeeList.employees[i];
                companyList->bracket1.employees[companyList->bracket1.count++].takeHomeSalary = companyList->employeeList.employees[i].grossSalary * (1 - bracket1Rate);
            } else if (companyList->employeeList.employees[i].grossSalary >= 15000 && companyList->employeeList.employees[i].grossSalary <= 25999){
                companyList->bracket2.employees[companyList->bracket2.count] = companyList->employeeList.employees[i];
                companyList->bracket2.employees[companyList->bracket2.count++].takeHomeSalary = companyList->employeeList.employees[i].grossSalary * (1 - bracket2Rate);
            } else if (companyList->employeeList.employees[i].grossSalary > 26000){
                companyList->bracket3.employees[companyList->bracket3.count] = companyList->employeeList.employees[i];
                companyList->bracket3.employees[companyList->bracket3.count++].takeHomeSalary = companyList->employeeList.employees[i].grossSalary * (1 - bracket3Rate);
            }
        } 
        
        
}


employeeRecord populate(int count){

    /* This function will take in a count of how many employees to add, and return an employeeRecord */

    employeeRecord list;

	//Statement to allocate memory for an Array of Employees.
    list.employees=malloc(sizeof(employeeInfo)*count);
    list.count = 0;
    int i=0;
    int idNum;
    int rate;
    int hrsWorked;
    char fName[20];
    char lName[20];
    char MI;

    for(i=0;i<count;i++){
    	printf("\n\n===EMPLOYEE %d===\n\n",i+1);

        //Write Code to Ask users for Input
        printf("Input First Name: ");
        scanf(" %s", fName);
        printf("Input Last Name: ");
        scanf(" %s", lName);
        printf("Input Middle Initial: ");
        scanf(" %c", &MI);
        printf("Input Id Number: ");
        scanf(" %d", &idNum);
        printf("Input Rate: ");
        scanf(" %d", &rate);
        printf("Input Hours Worked: ");
        scanf(" %d", &hrsWorked);


    	list.employees[i]=newEmployee(idNum,rate,hrsWorked,addName(fName, lName, MI));
    	list.count++;

    	if(i==count-1){
    		printf("\n===============\n\n");
		}
	}

    return list;

}
employeeInfo newEmployee(int idNum,int rate,int hrsWorked,name employeeName){
    employeeInfo newEmp;

    newEmp.empName=employeeName;
    newEmp.idNum=idNum;
    newEmp.rate=rate;
    newEmp.hrsWorked=hrsWorked;

    //Write Code to Calculate grossSalary;
    newEmp.grossSalary = (rate * hrsWorked);
   



    return newEmp;

}
name addName(char fName[],char lName[],char MI){

    /* This function takes in 2 Strings and a Character, it will then populate a new name structure variable based on the parameters passed towards this function and aim to return it back to the calling function */

    name employeeName;

    strcpy(employeeName.fName,fName);
    strcpy(employeeName.lName,lName);
    employeeName.MI=MI;

    return employeeName;

}