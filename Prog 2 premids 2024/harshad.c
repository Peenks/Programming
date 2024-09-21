#include <stdio.h>
#include <stdlib.h>

int* moveHarshadNumbers(int arr[], int size, int* harshadCount) {
    *harshadCount = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int sum = 0; 
    
    for(int i = 0; i < size; i++){
        z = arr[i] % 10;
        y = (arr[i] % 100) / 10;
        x = (arr[i] % 1000) / 100;
        
        sum  = x + y + z;
        
        if(arr[i] % sum == 0){
            (*harshadCount)++;
        }
    }
    
    int* harshad = malloc(sizeof(int) * (*harshadCount));
   
    int j = 0;
    for(int i = 0; i < size; i++){
        z = arr[i] % 10;
        y = (arr[i] % 100) / 10;
        x = (arr[i] % 1000) / 100;
        
        sum  = x + y + z;
        
        if(arr[i] % sum == 0){
            harshad[j++] = arr[i];
        }
    }
    
    return harshad;
}

int main() {
    int size = 0;
    int harshadCount;
    
    printf("Input Size of Array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Populate the Array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    
    int *result = moveHarshadNumbers(arr, size, &harshadCount);
    
   
    printf("Harshad numbers: ");
    for(int i = 0; i < harshadCount; i++){
        printf("%d ", result[i]);
    }
    
    return 0;
}