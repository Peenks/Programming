#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>
#define LENGTH 10

typedef char String[20]; 

void display(int arr[], int count);
bool insertFront(int arr[], int *count, int item);
bool insertRear(int arr[], int *count, int item);
bool insertAt(int arr[], int *count, int item, int pos);
bool insertSorted(int arr[], int *count, int item);
bool deleteFront(int arr[], int *count);
bool deleteRear(int arr[], int *count);
bool deleteItem(int arr[], int *count, int item);
bool deleteAllItem(int arr[], int *count, int item);
bool searchItem(int arr[], int count, int item);



#endif