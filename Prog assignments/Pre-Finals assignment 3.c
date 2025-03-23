#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hours;
    int mins;
} Time;

typedef struct {
    Time arr[10];
    int count;
} TimeArr;

Time referenceTime;


int timeToMins(Time t){
    int newTime = t.hours * 60 + t.mins;
    
    return newTime; 
}

int timeDifference(Time t1, Time reference) {
    return abs(timeToMins(t1) - timeToMins(reference));
}


TimeArr sortTimes(TimeArr list) {
    for (int i = 0; i < list.count - 1; ++i) {
        for (int j = 0; j < list.count - i - 1; ++j) {
            if (timeDifference(list.arr[j], referenceTime) > timeDifference(list.arr[j + 1], referenceTime)) {
                
                Time temp = list.arr[j];
                list.arr[j] = list.arr[j + 1];
                list.arr[j + 1] = temp;
            }
        }
    }
    return list;
}


void display(TimeArr list) {
    for (int i = 0; i < list.count; ++i) {
        printf("Time %i: %02d:%02d\n", i + 1, list.arr[i].hours, list.arr[i].mins);
    }
}


void printTime(Time t) {
    printf("%02d:%02d", t.hours, t.mins);
}

int main() {
    TimeArr list = {
        .arr = {
            {7, 30},
            {18, 20},
            {15, 12},
            {2, 30},
            {6, 30}
        },
        .count = 5
    };
    
    referenceTime = (Time){18, 0}; 
    
    printf("Original times:\n");
    display(list);
    
    
    list = sortTimes(list);
    
    printf("\nSorted times based on proximity to ");
    printTime(referenceTime);
    printf(":\n");
    display(list);
    
    return 0;
}
