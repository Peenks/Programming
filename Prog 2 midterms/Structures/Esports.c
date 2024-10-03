#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

typedef struct{
	char fname[20];
	char lname[20];
}name;

typedef struct{
	char esport[30];
	int rank;
}sportInfo;

typedef struct{
	name studentName;
	sportInfo game;
	char school[20]; //SOE,SAS,SAFAD
}studentInfo;

typedef struct{
	studentInfo *schoolList;
	int schoolCount;
}schoolList;

typedef struct{
	studentInfo *teamMembers; // Players have to reach a minimum of 5 to join, while a maximum of 6.
							  //Team Composition is based soley on Rank, the highest ranked of a department and game will
							  //be added to the team.
	char game[20];
	char teamDepartment[20];
	int count;
}team;

/* addStudent creates a studentInfo structure and populates it using the given arguments after which the studentInfo structure is returned back to calling function.*/

studentInfo addStudent(name studentName,sportInfo game,char school[]);


/* addName creates a name structure and populates it using the given arguments after which the name structure is returned back to calling function*/

name addName(char fname[20],char lname[20]);

/* sportInfo creates a name structure and populates it using the given arguments after which the sportInfo structure is returned back to calling function. You might notice that here rank is char[] but in the structure it is int, this function is passed a String equivalent of the rank such as "Gold", and the function converts that String counterpart to its equivalent integer value (e.g Gold gets converted to 3) */

sportInfo addSport(char game[20],char rank[20]);


/* populateSchoolList creates a list of all students who are interested in joining the tournament, this populates the necessary fields such as the players name, game of choice, rank, and department */

void populateSchoolList(schoolList *totalList);

/* display aims to display the output in the proper format */

void display(team foundTeam);


/* The functions available are found in .h, although these functions are available does not mean,
they are needed to be used in the actual solution. Most functions are used during the initial population of the list and can be ignored, but again are available if you see fit. */

/* display() and populateSchoolList() is really the only required function you need to call in the actual solution */

team findTeam(char schoolInput[],char sportInput[],schoolList *totalList){
    team found;
    found.count = 0;
    strcpy(found.teamDepartment, schoolInput);
    strcpy(found.game, sportInput);
    studentInfo kenji[6];
    
    for(int i = 8; i > 0; i--){
        for(int j = 0; j < totalList->schoolCount; j++){
            if(strcmp(schoolInput, totalList->schoolList[j].school) == 0 && strcmp(sportInput, totalList->schoolList[j].game.esport) == 0 && found.count < 6 && totalList->schoolList[j].game.rank == i){
                kenji[found.count++] = totalList->schoolList[j];
            }
        }
    }
    
    found.teamMembers = malloc(sizeof(studentInfo)*found.count);
    memcpy(found.teamMembers, kenji, sizeof(studentInfo)*found.count);

    return found;
}

int main(){
	schoolList totalList; //Refers to the list of all students interested in
                          //joining the tournament

	team foundTeam; //Refers to the team found based on the given criteria of
                    //school and choice of game

    char schoolInput[20];
	char sportInput[20];

	populateSchoolList(&totalList);

	printf("===Find Teams!===");
	printf("\nInput School: ");
	scanf(" %s",schoolInput);
	printf("Input Sport: ");
	scanf(" %s",sportInput);


    /* Proper function call to findTeam */
    foundTeam = findTeam(schoolInput,sportInput,&totalList);


	display(foundTeam);
	return 0;
}