#include <stdio.h>
#include <stdlib.h>

int* findEvenIntersections(int* arr1, int* arr2, int size1, int size2, int* count) {
    *count = 0;
   for(int i = 0; i < size1; i++){
       for(int j = 0; j < size2; j++){
           if(arr2[j] % 2 == 0 && arr2[j] == arr1[i]){
               (*count)++;
               break;
           } 
       }
   }
    
    int* intersect = malloc(sizeof(int) * (*count));
    
    int k = 0;
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(arr2[j] % 2 == 0 && arr2[j] == arr1[i]){
                intersect[k++] = arr2[j];
            } 
        }
    }
    
    return intersect;
}

int main() {
    int size1, size2;
    int arr1[100];
    int arr2[100];
    int count;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    
    printf("Enter %d elements for the first array: \n", size1);
    for(int i = 0; i < size1; i++){
        scanf("%d", &arr1[i]);
    }
    
     printf("Enter %d elements for the second array: \n", size2);
    for(int i = 0; i < size2; i++){
        scanf("%d", &arr2[i]);
    }

    
    int* intersected = findEvenIntersections(arr1,arr2,size1,size2, &count);
    
    if(count > 0){
        printf("Even number intersection: ");
        for(int k = 0; k < count; k++){
            printf("%d ", intersected[k]);
        }
    } else {
        printf("No even number intersections found.");
    }
    
    return 0;
}