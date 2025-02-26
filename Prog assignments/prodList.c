#include <string.h>
#include <stdio.h>
#define MAX 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int prodID;
    char prodName[20];
    int prodQty;
    float prodPrice;
    // Date prodExpDate;
} Prod;

typedef struct {
    Prod products[MAX];
    int size;
} prodList;

Date createDate(int day, int month, int year){
    Date newDate;
    newDate.day = day;
    newDate.month = month;
    newDate.year = year;
    
    return newDate;
}

Prod createProd(int id, char name[], int qty, float price){
    Prod newProd;
        newProd.prodID = id;
        strcpy(newProd.prodName, name);
        newProd.prodQty = qty;
        newProd.prodPrice = price;
        
        return newProd;
}

void insertSorted(prodList *list, Prod newProd){
    if(list->size >= MAX){
        printf("List is full!");
    }
    
    int i = 0;
    int pos = 0;
    
    while(pos < list->size && strcmp(list->products[pos].prodName, newProd.prodName) < 0){
        pos++;
    }
    
    for(i = list->size; i > pos; --i){
        list->products[i] = list->products[i - 1];
    }
    
    list->products[pos] = newProd;
    
    list->size++;
}

void initList(prodList *list){
    list->size = 0;
}

void displayProdList(prodList *list){
    printf("Product List: \n");
    for(int i = 0; i < list->size; ++i){
        printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f", 
        list->products[i].prodID,
        list->products[i].prodName,
        list->products[i].prodQty,
        list->products[i].prodPrice);
        printf("\n\n");
    }
 
}

void display(Prod product){ //print single
    printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f", product.prodID,product.prodName,product.prodQty,product.prodPrice);
}

Prod findProd(prodList *list, int id){
    Prod DUMMY = {3,"NotFOUND",3,3.33};
    for(int i = 0; i < list->size; ++i){
        if(list->products[i].prodID == id){
            for(int j = i; j < list->size - 1; ++j){
                list->products[j] = list->products[j + 1];
            }
            list->size--;
            return list->products[i];
        }
    }
    return DUMMY;
}

Prod delProd(prodList *list, char *name){
    Prod DUMMY = {3,"NotFOUND",3,3.33};
    for(int i = 0; i < list->size; ++i){
        if(strcmp(list->products[i].prodName, name) == 0){
            return list->products[i];
        }
    }
    return DUMMY;
}

int main() {
    prodList prodList;
    initList(&prodList);
   
    insertSorted(&prodList, createProd(3,"Mouse",15,25.00));
    insertSorted(&prodList, createProd(5,"Keyboard",10,50.00));
    insertSorted(&prodList, createProd(1,"Monitor",5,150.00));
    insertSorted(&prodList, createProd(6,"Laptop",15,25.00));
    
    displayProdList(&prodList);
    
    printf("==FOUND==\n");
    Prod FOUND = findProd(&prodList,1);
    display(FOUND);
    printf("\n\n");
    
    printf("==DELETED==\n");
    Prod DELETED = delProd(&prodList,"Mouse");
    display(DELETED);
    printf("\n\nUpdated List\n\n");
    displayProdList(&prodList);
   
    return 0;
}
