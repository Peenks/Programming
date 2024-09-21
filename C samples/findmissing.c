#include <stdlib.h>
#include <stdio.h>

int findMissing(int*,int);

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
   
  findMissing(arr,size);
  
    return 0;
}

int findMissing(int arr[], int size){
    int count = 1;
    int missing = 1;
    
    for(int i = 0; i < size; i++){
        if(arr[i] == missing++){
            count++;
        } else {
            break;
        }
        
    }
    
    printf("The missing element is: %d", count);
    
    return missing;
}
