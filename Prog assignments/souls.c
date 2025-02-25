#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
#define INT_MIN -2147483648
#define INT_MAX 214748364

void display(int arr[]);
int *sorting_souls(int arr[]);

int main() {
    int list[MAX_SIZE];

    printf("Enter number of souls: ");
    scanf(" %d", &list[0]);

    printf("Enter soul scores: ");
    for(int i = 1; i <= list[0]; ++i) {
        scanf(" %d", &list[i]);
    }

    printf("Initial soul list: ");
    display(list);

    
    printf("Sorted soul list: ");
    int *SORTED = sorting_souls(list);
    display(SORTED);
    
    return 0;
}

void display(int arr[]) {
    printf("[");
    for(int i = 1; i <= arr[0]; ++i) {
        printf("%d", arr[i]);
        if(i < arr[0]) {
            printf("|");
        }
    }
    printf("], SOUL COUNT: %d\n", arr[0]);
}

int *sorting_souls(int arr[]) {
    int  MAX = INT_MAX;
    int LOW = INT_MIN;
    int count = arr[0];
    
    for(int i = 1; i <= count; ++i){
        if(arr[i] > MAX){
            LOW = MAX;
            MAX = arr[i];
        } else if(arr[i] > LOW && arr[i] < MAX){
            LOW = arr[i];
        }
    }
    
    int start = 1;
    while(start <= count && arr[start] != LOW){
        start++;
    }
    
    int size = count - start + 1;
    int *sorted = malloc(sizeof(int) * (size + 1));
    
    sorted[0] = size;
    for(int i = 1; start <= count; ++i, ++start){
        sorted[i] = arr[start];
    }
    
    return sorted;
}
