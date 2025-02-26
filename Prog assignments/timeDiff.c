#include <stdlib.h>
#include <stdio.h>

typedef struct THISTIME{
    int hrs;
    int mins;
} TIME;

TIME createTime(int hours, int minutes){
    TIME newTime;
    
    newTime.hrs = hours;
    newTime.mins = minutes;
    
    return newTime;
}

void displayMil(TIME timE){
    if(timE.hrs >= 10){
        printf("Military Time: %d:%d", timE.hrs, timE.mins);
    } else {
        printf("Military Time: 0%d:%d", timE.hrs, timE.mins);
    }
}

void displayStndrd(TIME timE){
    if(timE.hrs >= 12){
        printf("Standard Time: %d:%d", (timE.hrs - 12),timE.mins);
    } else {
        printf("Standard Time: %d:%d", timE.hrs,timE.mins);
    }
}

int getDiffMins(TIME time1, TIME time2){
    int mins1 = time1.hrs * 60 + time1.mins;
    int mins2 = time2.hrs * 60 + time2.mins;
    int total = mins1 - mins2;
    
    return abs(total);
}

TIME getDiff(TIME time1, TIME time2){
    TIME diff;
    int mins1 = time1.hrs * 60 + time1.mins;
    int mins2 = time2.hrs * 60 + time2.mins;
    int total = abs(mins1 - mins2);
    
    diff.hrs = total / 60;
    diff.mins = total % 60;
    
    return diff;
}

int main() {
    TIME timE;
    
    TIME timeToday = createTime(13,59);
    TIME another = createTime(7,30);
    displayMil(timeToday);
    printf("\n");
    displayStndrd(timeToday);
    
    int DIFFMINS = getDiffMins(timeToday,another);
    printf("\n\nDifference in minutes is: %d", DIFFMINS);
    
    TIME DIFF = getDiff(timeToday,another);
    printf("\n\nDifference total is %d hours and %d minutes", DIFF.hrs, DIFF.mins);
    
    return 0;
}
