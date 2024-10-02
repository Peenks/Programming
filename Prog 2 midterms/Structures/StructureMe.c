#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 20

// to do structure for Product
typedef struct{
    int productID;
    char productName[50];
    int productQty;
    float productPrice;
} Product;

typedef struct{
    Product prodList[20];
    int count;
} ProductList;

// to do structure for ProductList

Product newProduct(int id, char* name, int qty, float price);
ProductList newProductList();
void addProduct(ProductList *list, Product p);
void displayProductsLessThan(ProductList list, float amount);

int main() {

    ProductList storeDisplay = newProductList();
    
    

    addProduct(&storeDisplay, newProduct(1, "Converse Chuck", 0, 5000));
    addProduct(&storeDisplay, newProduct(2, "Nyke Water Force 1s", 6000, 5000));
    addProduct(&storeDisplay, newProduct(3, "Airpods", 6000,9500 ));
    addProduct(&storeDisplay, newProduct(4, "Marshmallows", 6000,150 ));
    addProduct(&storeDisplay, newProduct(5, "Netflix Giftcard", 6000, 500));
    addProduct(&storeDisplay, newProduct(6, "Speakers", 6000,2500 ));
    addProduct(&storeDisplay, newProduct(7, "Alarm Clock", 6000, 1500));
    addProduct(&storeDisplay, newProduct(8, "Backpack", 6000,1000 ));
    addProduct(&storeDisplay, newProduct(9, "Smart Watch", 6000, 7000));
    addProduct(&storeDisplay, newProduct(10, "Self-Help Book", 6000,300 ));
    // add the rest of the addProduct()

    // make a call of the display product with 2000 as the amount value
    displayProductsLessThan(storeDisplay,2000);
    
    return 0;
}

Product newProduct(int id, char* name, int qty, float price) {
    Product p;

    p.productID = id;
    strcpy(p.productName, name);
    p.productQty = qty;
    p.productPrice = price;
    
    return p;
}

ProductList newProductList() {
    ProductList list;

    list.count = 0;

    return list;
}

void addProduct(ProductList *list, Product p) {
     if(list->count < MAX_PRODUCTS) {
         list->prodList[(list->count)++] = p;
     } 
}

void displayProductsLessThan(ProductList list, float amount) {
    for(int i = 0; i < 10; i++){
        if(list.prodList[i].productPrice < amount){
            printf("%d - %s - Php %.2f\n", list.prodList[i].productID, list.prodList[i].productName, list.prodList[i].productPrice);
        }
    }
}