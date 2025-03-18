#ifndef MYHEADER_H 
#define MYHEADER_H
#include <stdbool.h>



typedef struct {
    int *arr;
    int count;
    int length;
} ArrayList;

void initList(ArrayList *list, int length);
ArrayList createList(int length);
void displayList(const ArrayList list);
bool addItem(ArrayList *list, int item); //insert front
bool removeItem(ArrayList *list, int item);
bool isEmpty(const ArrayList list);
bool isFull(const ArrayList list);
ArrayList getAllPrimeFactors(ArrayList *list, int value);
int isPrime(int num);

#endif