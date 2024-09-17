#include <stdio.h>
#include <stdlib.h>


int* isPos(int* arr, int n, int* posCount){
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            (*posCount)++;
        }
    }
    
    int* posArr = malloc(sizeof(int) * (*posCount));
    
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            posArr[j++] = arr[i];
        }
    }
    
    return posArr;
}

int* isNeg(int* arr, int n, int*negCount){
     for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            (*negCount)++;
        }
    }
    
    int* negArr = malloc(sizeof(int) * (*negCount));
    
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            negArr[j++] = arr[i];
        }
    }
    
    return negArr;
}

int main() {
    int arr[] = {-5, 10, -20, 15, -30, 25, 40};
    int n = 7;
    int posCount = 0, negCount = 0;
    
    int* posArr = isPos(arr,n,&posCount);
    int* negArr = isNeg(arr,n,&negCount);
    
    printf("Positive numbers: ");
    for(int j = 0; j < posCount; j++){
        printf("%d ", posArr[j]);
    }
    printf("\n");
    
    printf("Negative numbers: ");
    for(int j = 0; j < negCount; j++){
        printf("%d ", negArr[j]);
    }
}