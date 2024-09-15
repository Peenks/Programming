#include <stdio.h>
#include <stdlib.h>

int input();
void display(int*, int*);
void insertFirst(int**, int*);
void deleteFirst(int*, int*);
void insertLast(int**, int*);
void deleteLast(int*, int*);

int main(){
    int size;
    int choice;
    

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int count = size;

    int* arr = malloc(sizeof(int) * size);

    for(int i = 0; i < count; i++){
        scanf("%d", &arr[i]);
    }

    printf("Array [");
    for(int i = 0; i < count; i++){
        printf("%d", *(arr + i));
        if(i < count - 1){
            printf(", ");
        } 
    }
 
    printf("]\n");
    
    printf("=====This is a menu=====\n");
    printf("1. Insert element to first index\n");
    printf("2. Insert element to last index\n");
    printf("3. Delete first element\n");
    printf("4. Delete Last element\n");
    printf("5. Exit\n");
    printf("========================\n");
    printf("Enter your choice: ");
    
    choice = input();
    
    switch (choice){
        case 1: {
            insertFirst(&arr, &count);
            display(arr, &count);
            break;
        }
        case 2: {
            insertLast(&arr, &count);
            display(arr, &count);
            break;
        }
        case 3: {
            deleteFirst(arr, &count);
            display(arr, &count);
            break;
        }
        case 4: {
            deleteLast(arr, &count);
            display(arr, &count);
            break;
        }
        case 5: {
            printf("Program Exited");
            return 0;
        }
        default: 
            printf("Enter a valid choice");
            return 0;
    }


    //This is only for VScode, dont mind
    int temp;
    scanf("%d", &temp);
    return 0;
}



void display(int* arr, int* count){
    printf("New array: [");
    for(int i = 0; i < *count; i++){
        printf("%d", *(arr + i));
        if(i != *count - 1){
            printf(", ");
        } 
    }
    printf("]\n");
}

void insertFirst(int** arr, int* count){
    
    *arr = realloc(*arr, sizeof(int) * (*count + 1));
    int i;
    for(i = (*count); i >= 0; i--){
        (*arr)[i] = (*arr)[i - 1];
    }
    printf("Enter element to insert first: ");
    scanf("%d", *arr);
    (*count)++;
}

void deleteFirst(int* arr, int* count){
    if(*count > 0){
        int i;
        for(int i = 0; i < *count - 1; i++){
            arr[i] = arr[i + 1];
        }
        (*count)--;
        printf("---DELETED FIRST ELEMENT---\n");
    }
}

void insertLast(int** arr, int* count){
    
   
    *arr = realloc(*arr, sizeof(int) * (*count + 1));
    printf("Enter the element to insert last: ");
    scanf("%d", &(*arr)[*count]);
    (*count)++;
}

void deleteLast(int* arr, int* count){
    if(*count > 0){
        (*count)--;
    }
    printf("---DELETED LAST ELEMENT---\n");
}

int input(){
    int n;
    scanf("%d", &n);
    
    return n;
}



