#include <stdio.h>
#include <stdlib.h>

int* isEven(int*,int,int*);
int* isOdd(int*,int,int*);

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
       if(i < size - 1){
           printf(", ");
       } else {
           printf("]\n");
       }
   }
   
   int evenSize = 0;
   int* evenNum = isEven(arr,size,&evenSize);
   
    printf("Even Array [");
   for(int j = 0; j < evenSize; j++){
       printf("%d", evenNum[j]);
       if(j < evenSize - 1){
           printf(", ");
       } else {
           printf("]\n");
       }
   }
   
   int oddSize = 0;
   int* oddNum = isOdd(arr,size,&oddSize);
   
    printf("Odd Array [");
   for(int j = 0; j < oddSize; j++){
       printf("%d", oddNum[j]);
       if(j < oddSize - 1){
           printf(", ");
       } else {
           printf("]\n");
       }
   }
    
    return 0;
}

int* isEven(int arr[], int size, int* evenCount){
    *evenCount = 0;
    
    int i = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            (*evenCount)++;
        }
    }
    
    int* evenArr = malloc(sizeof(int) * (*evenCount));
    
    int j = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            evenArr[j] = arr[i];
            j++;
        }
    }
    
    return evenArr;
}

int* isOdd(int arr[],int size,int* oddCount){
    *oddCount = 0;
    
    int i = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 1){
            (*oddCount)++;
        }
    }
    
    int* oddArr = malloc(sizeof(int) * (*oddCount));
    
    int j = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 1){
            oddArr[j] = arr[i];
            j++;
        }
    }
    
    return oddArr;
}