#include <stdlib.h>
#include <stdio.h>

int* reverse(int*,int);

int main() {
   int size;
   
   printf("Enter size of the array: ");
   scanf("%d", &size);
   
   int arr[size];
   
   printf("Enter elements of the array: ");
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
   
   int* reversed = reverse(arr,size);
   
   printf("Reversed Array [");
   for(int j = 0; j < size; j++){
       printf("%d", reversed[j]);
       if(j < size - 1){
           printf(", ");
       } else {
           printf("]\n");
       }
   }
   
   
    return 0;
}

int* reverse(int arr[], int size){
    
    int* reversedArr = malloc(sizeof(int) * size);
    
 
    for(int j = 0; j < size; j++){
        reversedArr[j] = arr[size - j - 1];
    }
    
    
    
    return reversedArr;
}






