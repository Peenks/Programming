#ifndef MYHEADER_H 
#define MYHEADER_H
#include <stdbool.h>
#define LEN 10



typedef struct {
    int arr[LEN];
    int count;
} List;

void initList(List *list);
List createList();
bool insertSorted(List *list, int item);
void displayList(const List list);
List getPrimeNum(List *list);
int isPrime(int num);

#endif