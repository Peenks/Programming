#include <stdio.h>
#include <stdlib.h>

int* getInRange(int* arr, int n, int low, int high, int* rangeCount){
    for(int i = 0; i < n; i++){
        if(arr[i] >= low && arr[i] <= high){
            (*rangeCount)++;
        }
    }
    
    
    int* destin = malloc(sizeof(int) * (*rangeCount));
    
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= low && arr[i] <= high){
            destin[j++] = arr[i];
        }
    }
    
    return destin;
}



int main() {
    int arr[] = {1, 15, 25, 30, 50, 65, 70, 80};
    int n = 8;
    int low, high;
    int rangeCount = 0;
    
    printf("Input Low Range: ");
    scanf("%d", &low);
    
    printf("Input High Range: ");
    scanf("%d", &high);
    
    int* range = getInRange(arr,n,low,high,&rangeCount);
    
    if(rangeCount == 0){
        printf("No elements in range [%d,%d]", low, high);
    } else {
         printf("Elements in range [%d, %d]: ", low, high);
        for(int j = 0; j < rangeCount; j++){
        printf("%d ", range[j]);
        }
    }
    
   
    
    
    return 0; 
}