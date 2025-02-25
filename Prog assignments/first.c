#include <stdbool.h>
#include <stdio.h>
#define MAX 5

bool addElementFirst(int myArr[], int *count, int val);
void display(int myArr[], int count);
bool addElementLast(int myArr[], int *count, int val);
bool deleteFirst(int myArr[], int *count);
bool addElementAt(int myArr[], int *count, int val, int pos);
void sortArr(int myArr[], int count);

int main() {
    int myArr[MAX];
    int count = 0;
    
    display(myArr,count);
    addElementFirst(myArr,&count,5);
    display(myArr,count);
    addElementFirst(myArr,&count,6);
    display(myArr,count);
    addElementFirst(myArr,&count,10);
    display(myArr,count);
    addElementLast(myArr,&count,15);
    display(myArr,count);
    deleteFirst(myArr,&count);
    display(myArr,count);
    addElementAt(myArr,&count,21,2);
    display(myArr,count);
    sortArr(myArr,count);
    printf("Sorted "); display(myArr,count);
    
    return 0;
}

void sortArr(int myArr[], int count){
    int i;
    for(i = 0; i < count; i++){
        if(myArr[i] > myArr[i + 1]){
            int temp;
            temp = myArr[i];
            myArr[i] = myArr[i + 1];
            myArr[i + 1] = temp;
        }
        i++;
    }
}

bool addElementAt(int myArr[], int *count, int val, int pos){
    if(*count >= MAX || pos < 0 || pos > *count){
        return false;
    }
    
    for(int i = *count; i < pos; --i){
        myArr[i] = myArr[i - 1];
    }
    myArr[pos] = val;
    (*count)++;
    return true;
}

bool deleteFirst(int myArr[], int *count){
    if(*count > 0){
        for(int i = 0; i < *count - 1; ++i){
            myArr[i] = myArr[i + 1];
        }
        (*count)--;
        return true;
    }
    
    return false;
    
}

bool addElementLast(int myArr[], int *count, int val){
    if(*count < MAX){
        myArr[*count] = val;
        (*count)++;
        return true;
    }
    return false;
}

bool addElementFirst(int myArr[], int *count, int val){
    if(*count >= MAX){
        return false;
    } 
    for(int i = *count; i > 0; --i){
        myArr[i] = myArr[i - 1];
    }
    myArr[0] = val;
    (*count)++;
    return true;
}

void display(int myArr[], int count){
    int i;
    printf("Array: {");
    for(i = 0; i < count; ++i){
        printf("%d", myArr[i]);
        if(i < count - 1){
        printf(", ");
    }
    }
    printf("}\n");
}