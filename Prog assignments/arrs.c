#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 5
#define FULL 20
#define DELI -100


int *getPositive(int arr[]);
void display(int arr[]);
int *getFactors(int arr[], int factor);
int *combineArr(int arr1[],int arr2[]);
int getArraySize(int arr[]);
int isUnique(int arr[], int num, int size);

int main() {
    int arr[MAX] = {5, -1, 7, 8, DELI}; 
    int factor = 5;
    
    printf("Original List: ");
    display(arr);
    
    int *pos = getPositive(arr);
    printf("Positive List: ");display(pos);
    
    int *fac = getFactors(arr,factor);
    printf("Factors: ");display(fac);
    
    // int sizePos = getArraySize(pos); no need
    // int sizeFac = getArraySize(fac); no need
    
    int *comb = combineArr(pos,fac);
    printf("Combined arrays (Positive array, and Factor array)[UNIQUE]: ");display(comb);
    
    

    return 0;
}

void display(int arr[]){
    printf("{");
    for(int i = 0; arr[i] != DELI; ++i){
        printf("%d", arr[i]);
        if(arr[i + 1] != DELI){
            printf(", ");
        }
    }
    printf("}\n");
}

int *getPositive(int arr[]){
    
    int temp[MAX];
    int size = 0;
    for(int i = 0; arr[i] != DELI; ++i){
        if(arr[i] > 0){
            temp[size++] = arr[i];
        }
    }
    
    temp[size++] = DELI;
    
    int *pElements = malloc(sizeof(int) * size);
    memcpy(pElements,temp,sizeof(int) * size);
    
    
    return pElements;
    
}

int *getFactors(int arr[], int factor){
    int temp[MAX];
    int total = 0;
    for(int i = 0; arr[i] != DELI ; ++i){
        if(arr[i] % factor == 0){
            temp[total++] = arr[i];
        }
    }
    
    temp[total++] = DELI;
    
    int *factorNum = malloc(sizeof(int) * total);
    memcpy(factorNum,temp,sizeof(int) * total);
    
    return factorNum;
}

int *combineArr(int arr1[], int arr2[]){
    int temp[FULL];
    int size = 0;
    for(int i = 0; arr1[i] != DELI; ++i){
        if(size >= FULL - 1){
            break;
        }
        if(isUnique(temp, arr1[i], size)){
            temp[size++] = arr1[i];
        }
    }
    
    for(int i = 0; arr2[i] != DELI ; ++i){
        if(size >= FULL - 1){
            break;
        }
        if(isUnique(temp, arr2[i], size)){
            temp[size++] = arr2[i];
        }
    }
    
    temp[size++] = DELI;
    int *combinedList = malloc(sizeof(int) * size);
    memcpy(combinedList,temp,sizeof(int) * size);
    
    return combinedList;
}

int getArraySize(int arr[]){
   int size = 0;
   while(arr[size] != DELI){
       size++;
   }
   
   return size;
}

int isUnique(int arr[], int num, int size){
    for(int i = 0; i < size; ++i){
        if(arr[i] == num){
            return 0;
        }
    }
    
    return 1;
}