#include <stdio.h>
#include <stdlib.h>


int* transferOddIndexed(int* arr, int n, int* oddCount){
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 1){
            (*oddCount)++;
        }
    }
    
    
    int* oddArr = malloc(sizeof(int) * (*oddCount));
    
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 1){
            oddArr[j++] = arr[i];
        }
    }
    
    return oddArr;
}

int main() {
    int arr[] = {10, 21, 32, 43, 54, 65, 76};
    int n = 7;
    int oddCount = 0;
    
    int* oddArr = transferOddIndexed(arr,n,&oddCount);
    
    printf("Odd-indexed elements:");
    for(int i = 0; i < oddCount; i++){
        printf(" %d", oddArr[i]);
    }
}