#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"

int main(){
    int choice;
    int item = 0;
    int arr[10];
    int count = 0;
    int pos;
    String menuChoices[10] = {"Insert Front", 
                             "Insert Rear",
                             "Insert At",
                             "Insert Sorted",
                             "Delete Front",
                             "Delete Rear",
                             "Delete Item",
                             "Delete ALL Item",
                             "Search Item"
    };
    

    do {
        printf("\nMENU\n");
        for(int i = 0; i < 10; ++i){
            printf("[%d] %s\n", i + 1, menuChoices[i]);
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nInsert Front Chosen\n");
                printf("Enter an item to insert front: ");
                scanf("%d", &item);
                insertFront(arr,&count,item);
                display(arr,count);
                break;
            case 2:
                printf("\nInsert Rear Chosen\n");
                printf("Enter an item to insert rear: ");
                scanf("%d", &item);
                insertRear(arr,&count,item);
                display(arr,count);
                break;
            case 3:
                printf("\nInsert At Chosen\n");
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter an item to insert at a chosen spot: ");
                scanf("%d", &item);
                insertAt(arr,&count,item,pos);
                display(arr,count);
                break;
            case 4: 
                printf("\nInsert Sorted Chosen\n");
                printf("Enter an item to insert sorted: ");
                scanf("%d", &item);
                insertSorted(arr,&count,item);
                display(arr,count);
                break;
            case 5:
                printf("\nDelete Front Chosen\n");
                deleteFront(arr,&count);
                display(arr,count);
                break;
            case 6: 
                printf("\nDelete Rear Chosen\n");
                deleteRear(arr,&count);
                display(arr,count);
                break;
            case 7:
                printf("\nDelete Item Chosen\n");
                break;
            case 8:
                printf("\nDelete ALL Item Chosen\n");
                break;
            case 9:
                printf("\nSearch Item Chosen\n");
                break;
            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 0);



    return 0;
}