#include <stdio.h>

void bubbleSort(int*,int);

int main() {
   int size;
   
   printf("Enter size of the array: ");
   scanf("%d", &size);
   
   int arr[size];
   printf("Enter the %d elements: ", size);
   for(int i = 0; i < size; i++){
       scanf("%d", &arr[i]);
   }
   
   printf("Array Unsorted [");
   for(int i = 0; i < size; i++){
       printf("%d", arr[i]);
       if(i < size - 1){
           printf(", ");
       } else {
           printf("]\n");
       }
   }
   
   bubbleSort(arr,size);
   
   printf("Array Sorted [");
   for(int i = 0; i < size; i++){
       printf("%d", arr[i]);
       if(i < size - 1){
           printf(", ");
       } else {
           printf("]\n");
       }
   }

    return 0;
}

void bubbleSort(int arr[],int size){
    int i;
    int j;
    int temp;
    
    
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}