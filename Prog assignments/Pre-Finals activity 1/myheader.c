#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

void initList(List *list){
    list->count = 0;
}

List createList(){
    List list;
    list.count = 0;
    
    return list;
}

bool insertSorted(List *list, int item){
    if(list->count >= 10){
        return 0;
    } 
    
    list->arr[list->count++] = item;
    return 1;
}

void displayList(const List list){
    printf("{");
    for(int i = 0; i < list.count; ++i){
        printf("%d", list.arr[i]);
        if(i < list.count - 1){
            printf(", ");
        }
    }
    printf("}");
}

List getPrimeNum(List *list){
    List removed; 
    removed.count = 0;
    
    int newCount = 0;
    
    for(int i = 0; i < list->count; ++i){
        if(isPrime(list->arr[i])){
            removed.arr[removed.count++] = list->arr[i];
        } else {
            list->arr[newCount++] = list->arr[i];
        }
    }
    list->count = newCount;
    
    return removed;
}

int isPrime(int num){
    if(num < 2){
        return 0;
    }
    for(int i = 2; i * i <= num; ++i){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}
