#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

int main(){
    List list = createList();
    insertSorted(&list, 2);
    insertSorted(&list, 3);
    insertSorted(&list, 5);
    insertSorted(&list, 7);
    insertSorted(&list, 4);
    insertSorted(&list, 6);
    insertSorted(&list, 8);
    
    printf("Original List: ");
    displayList(list);
    printf("\n");
    
    List primes = getPrimeNum(&list);
    
    printf("Removed prime numbers: ");
    displayList(primes);
    printf("\n");
    
    printf("New List: ");
    displayList(list);
    printf("\n");
    
    return 0;
}








