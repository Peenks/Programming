#include <stdio.h>

typedef struct{
    int day;
    int month;
    int year;
}DATE;

const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

DATE createDate(int day, int month, int year){
    DATE newDate;
    newDate.day = day;
    newDate.month = month;
    newDate.year = year;
    
    return newDate;
}

int isLeapYear(int year){
    return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void display(DATE date){
    printf("%s - %d - %d\n", months[date.month - 1], date.day, date.year);
}

int countDays(DATE date){
    
    int days = date.day + date.year * 365 + date.year / 4 - date.year / 100 + date.year / 400;
    
    for(int i = 0; i < date.month - 1; ++i){
        days += 1;
    }
    
    return days;
}

int dateDiff(DATE today, DATE another){
    return countDays(today) - countDays(another);
}

int main() {
    DATE today = createDate(30, 3, 2025);
    DATE another = createDate(15, 2, 2025);
    
    printf("First Date: ");
    display(today);
    printf("Second Date: ");
    display(another);
    
    
    int DIFF = dateDiff(today,another);
    printf("The difference of the 2 dates is: %d\n", DIFF);
    
    return 0;
}