#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"


void display(int arr[], int count){
    printf("Array: {");
    for(int i = 0; i < count; ++i){
        printf("%d", arr[i]);
        if(i < count - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

bool insertFront(int arr[], int *count, int item){
    if(*count < LENGTH){
        for(int i = *count; i > 0; --i){
            arr[i] = arr[i - 1];
        }
        arr[0] = item;
        (*count)++;
        return true;
    }
    return false;
}

bool insertRear(int arr[], int *count, int item){
    if(*count < LENGTH){
        arr[(*count)++] = item;
        return true;
    }
    return false;
}
bool insertAt(int arr[], int *count, int item, int pos){
    int i;
    if(*count < LENGTH){
        for(i = *count; i < pos; --i){
            arr[i] = arr[i - 1];
        }
        arr[pos] = item;
        (*count)++;
        return true;
    }
    
    return false;
}
bool insertSorted(int arr[], int *count, int item){     //not finished
    if(*count < LENGTH){
        for(int i = *count; i > 0; --i){
            if(item > arr[i]){
                arr[i] = arr[i + 1];
            } else {
                arr[i] = item;
                (*count)++;
                return true;
            }
        }
    }
     return false;
}
bool deleteFront(int arr[], int *count){
    if(*count < LENGTH){
        for(int i = 0; i < *count; ++i){
            arr[i] = arr[i + 1];
        }
        (*count)--;
        return true;
    }
    return false;
}

bool deleteRear(int arr[], int *count){
    if(*count > 0){
        (*count)--;
        return true;
    }
    return false;
}

bool deleteItem(int arr[], int *count, int item){         //not finished
    if(*count < LENGTH){
        for(int i = 0; i < *count; ++i){
            if(arr[i] == item){
                arr[i - 1] = arr[i];
                (*count)--;
                return true;
            }
        }
    }
    return false;
}
// bool deleteAllItem(int arr[], int *count, int item);
bool searchItem(int arr[], int count, int item){
    if(count < LENGTH){
        for(int i = 0; i < count; ++i){
            if(arr[i] == item){
                return true;
            }
        }
    }
    return false;
}