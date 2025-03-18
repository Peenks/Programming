#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

int main(){
    
    ArrayList list = createList(10);
     addItem(&list, 2);
    addItem(&list, 7);
    addItem(&list, 8);
    addItem(&list, 6);
    addItem(&list, 4);
    addItem(&list, 5);
    addItem(&list, 3);
    
    printf("Original List: ");
    displayList(list);
   
    
    ArrayList primeFactors = getAllPrimeFactors(&list, 28);
    
    printf("Removed prime factors: ");
    displayList(primeFactors);
    
    
    printf("New List: ");
    displayList(list);

    
    return 0;
}