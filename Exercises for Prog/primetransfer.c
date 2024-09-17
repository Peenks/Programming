#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int* transferPrimes(int* arr, int n, int* primeCount){
    
    
    for(int i = 0; i < n; i++){
        int flag = 1;
        for(int j = 2; j <= arr[i]/2; j++){
            if(arr[i] % j == 0){
                flag = 0;
            }
        }
        if(flag == 1){
            (*primeCount)++;
        }
    }
    
    int* primeArr = malloc(sizeof(int) * (*primeCount));
    
    int k = 0;
    for(int i = 0; i < n; i++){
        int flag = 1;
         for(int j = 2; j <= arr[i]/2; j++){
             if(arr[i] % j == 0){
                 flag = 0;
             }
         }
         if(flag == 1){
              primeArr[k++] = arr[i];
         }
    }
    
    return primeArr;
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n = 10;
    int primeCount = 0;
    
    int* primeArr = transferPrimes(arr,n,&primeCount);
    
    printf("Prime numbers: ");
    for(int i = 0; i < primeCount; i++){
        printf("%d ", primeArr[i]);
    }
    
    return 0;
}