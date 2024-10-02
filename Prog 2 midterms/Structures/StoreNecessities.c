#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int month;
    int year;
}date;

typedef struct{
    char productName[50];
    float price;
    date expiryDate;
    int quantity;
}productInfo;

typedef struct{
    productInfo *product;
    float inventoryCost;
    int inventoryCount;
}inventory;

typedef struct{
    inventory currentInventory;
    inventory expiredInventory;
}storeInventory;


void addInitialInventory(inventory*);
productInfo addProductInfo(char[],float,date,int);
date addDate(int,int);
void display(storeInventory,int);

int main(){
storeInventory store;
date currentDate;
store.expiredInventory.inventoryCount=0;
store.expiredInventory.inventoryCost=0;

printf("Input Current Month: ");
scanf("%d",&currentDate.month);
printf("Input Current Year: ");
scanf("%d",&currentDate.year);

addInitialInventory(&store.currentInventory);

display(store,1);

expiredProductRemoval(&store,expiryDate,currentDate,&expiredCount);

display(store,2);

}

void expiredProductRemoval(storeInventory *store,date expiryDate,date currentDate,int *expiredCount){
    
    int j = 0;
    for(int i = 0; i < store->currentInventory.inventoryCount; i++){
        date *itemExpiryDate = &store->currentInventory.product[i].expiryDate;
        
        if (currentDate.year > itemExpiryDate->year || (currentDate.year == itemExpiryDate->year && currentDate.month >= itemExpiryDate->month)) {
            productInfo temp = store->currentInventory.product[i];
            
            store->expiredInventory.product[j++] = temp;
            store->expiredInventory.inventoryCount++;
            
            memmove(store->currentInventory.product + i, store->currentInventory.product + i + 1, sizeof(productInfo) * (store->currentInventory.inventoryCount - (i + 1)));
            store->currentInventory.inventoryCount--;
            i--;
            
            
            store->currentInventory.inventoryCost -= temp.price * temp.quantity;
            store->expiredInventory.inventoryCost += temp.price * temp.quantity;
        }
    }
}