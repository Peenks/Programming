#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 20


typedef struct {
    int productID;
    char productName[50];
    int productQty;
    float productPrice;
} Product;


Product newProduct(int id, char* name, int qty, float price);
void addProduct(Product *list,int *count, Product p);
void displayProductsLessThan(Product* list, float amount, int count);

int main() {
    Product prodList[20];
    int count=0;

    addProduct(prodList,&count, newProduct(1, "Converse Chuck", 5, 5000));
    addProduct(prodList,&count, newProduct(2, "Nyke Water Force 1s", 1, 6000));
    addProduct(prodList,&count, newProduct(3, "AirPods",23 ,9500));
    addProduct(prodList,&count, newProduct(4, "Marshmallows",23 ,150));
    addProduct(prodList,&count, newProduct(5, "Netflix Giftcard",23 ,500));
    addProduct(prodList,&count, newProduct(6, "Speakers",5 ,2000));
    addProduct(prodList,&count, newProduct(7, "Alarm Clock",6 ,1500));
    addProduct(prodList,&count, newProduct(8, "Backpack",8 ,1000));
    addProduct(prodList,&count, newProduct(9, "Smart Watch",9 ,7000));
    addProduct(prodList,&count, newProduct(10,"Self-Help Book",23 ,300));
    
    
    displayProductsLessThan(prodList,2000,count);

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



void addProduct(Product *list,int *count, Product p) {
   if(*count < MAX_PRODUCTS){
       list[(*count)++] = p;
   }
}

void displayProductsLessThan(Product* list, float amount, int count) {
   for(int i = 0; i < count; i++){
       if(list[i].productPrice < amount){
           printf("%d - %s - Php %.2f\n", list[i].productID, list[i].productName, list[i].productPrice);
       }
   }
}