#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

void initList(ArrayList *list, int length){
    list->arr = malloc(sizeof(int) * length);
    list->count = 0;
    list->length = length;  
}

ArrayList createList(int length){
    ArrayList newList;
    newList.arr = malloc(sizeof(int) * length);
    newList.count = 0;
    newList.length = length;
    
    return newList;
}

void displayList(const ArrayList list){
    printf("{");
    for(int i = 0; i < list.count; ++i){
        printf("%d", list.arr[i]);
        if(i < list.count - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

bool addItem(ArrayList *list, int item){
    if(isFull(*list)){
        int newLength = list->length * 2;
        int *newArr = realloc(list->arr, sizeof(int) * newLength);
        list->arr = newArr;
        list->length = newLength;
    }
    
    for(int i = list->count; i > 0; --i){
        list->arr[i] = list->arr[i - 1];
    }
    list->arr[0] = item;
    list->count++;
    return 1;
}

bool removeItem(ArrayList *list, int item){
    if(isEmpty(*list)){
        return 0;
    }
    int index = -1;
    for(int i = 0; i < list->count; ++i){
        if(list->arr[i] == item){
            index = i;
            break;
        }
    }
    
    if(index == -1){
        return 0;
    }
    
    for(int i = index; i < list->count - 1; ++i){
        list->arr[i] = list->arr[i + 1];
    }
    
    list->count--;
    return 1;
}

bool isEmpty(const ArrayList list){
    if(list.count <= 0){
        return 1;
    }
    return 0;
}

bool isFull(const ArrayList list){
    if(list.count >= list.length){
        return 1;
    }
    return 0;
}

ArrayList getAllPrimeFactors(ArrayList *list, int value) {
    ArrayList factors = createList(10);
    
    int i = 0;
    while (i < list->count) {
        if (isPrime(list->arr[i]) && value % list->arr[i] == 0) {
            addItem(&factors, list->arr[i]); 
            while (value % list->arr[i] == 0) {
                value /= list->arr[i];
            }
            removeItem(list, list->arr[i]);
        } else {
            i++;
        }
    }
    
    return factors;
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





