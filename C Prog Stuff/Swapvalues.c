#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* swap(int*,int,int);

int main() {
    int size;
    
    printf("Enter size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Array [");
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
        if(arr[i] < size){
            printf(", ");
        } else {
            printf("]\n");
        }
    }
    
    int k; 
    
    printf("Enter the flag number: ");
    scanf("%d", &k);
    
    int* swapped = swap(arr,size,k);
     printf("Swapped Array [");
    for(int i = 0; i < size; i++){
        printf("%d", swapped[i]);
        if(i < size - 1){
            printf(", ");
        } else {
            printf("]\n");
        }
    }
    
    
    return 0;
}

int* swap(int arr[], int size, int k){
    
    int* newArr = malloc(sizeof(int) * size);
    
   memcpy(newArr, arr + k, sizeof(int) * (size - k));
   memcpy(newArr + (size - k), arr, sizeof(int) * (size - k));
    
    return newArr;
}