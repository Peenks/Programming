#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLOCKERS 10
#define WEIGHTLIMIT 5

typedef struct {
	char studID[9];
	char studName[65];
	char course[5];
} Student;

typedef struct {
	char itemName[33];
	float weight;
} ItemDets;

typedef struct ItemNode {
	ItemDets item;
	struct ItemNode* nextItem;
} ItemNode, *ItemList;

typedef struct {
	Student owner;
	ItemList IL;
	int lockerStat;
	float totWeight;
} Locker;

ItemNode* createItemNode(ItemDets item) {
	ItemNode* newNode = (ItemNode*)malloc(sizeof(ItemNode));
	newNode->item = item;
	newNode->nextItem = NULL;
	return newNode;
}

void depositItem(Locker* L, char studID[], ItemDets newItem) {
	if (strcmp(L->owner.studID, studID) != 0) {
		printf("Student ID does not match locker owner.\n");
		return;
	}
	if (L->totWeight + newItem.weight > WEIGHTLIMIT) {
		printf("Item too heavy to store. Locker limit exceeded.\n");
		return;
	}
	
	ItemNode* newNode = createItemNode(newItem);

	ItemNode** trav = &(L->IL);
	while (*trav != NULL && (*trav)->item.weight < newItem.weight) {
		trav = &((*trav)->nextItem);
	}
	newNode->nextItem = *trav;
	*trav = newNode;

	L->totWeight += newItem.weight;
}

ItemList getHeavyItems(Locker* L, float limit) {
	ItemList heavyList = NULL;
	ItemNode** trav = &(L->IL);

	while (*trav != NULL) {
		if ((*trav)->item.weight > limit) {
			ItemNode* toRemove = *trav;
			*trav = toRemove->nextItem;
			L->totWeight -= toRemove->item.weight;
			toRemove->nextItem = heavyList;
			heavyList = toRemove;
		} else {
			trav = &((*trav)->nextItem);
		}
	}
	return heavyList;
}

void displayItemList(ItemList L) {
	ItemList trav;
	float totWeight = 0;
	for (trav = L; trav != NULL; trav = trav->nextItem) {
		printf("Item: %-15s | Weight: %-15.2f\n", trav->item.itemName, trav->item.weight);
		totWeight += trav->item.weight;
	}
	printf("\nTotal Weight: %.2fkg\n\n", totWeight);
}

int main(void) {
	ItemDets item1 = {"Prog 1 Book", 0.35};
	ItemDets item2 = {"Shoes", 0.87};
	ItemDets item3 = {"Laptop", 2.35};
	ItemDets item4 = {"Keyboard", 1.17};

	Locker myLocker = {{"14101941", "Cris Militante", "BSCS"}, NULL, 1, 0};
	ItemList heavyItems;

	depositItem(&myLocker, "14101941", item4);
	depositItem(&myLocker, "14101941", item2);
	depositItem(&myLocker, "14101941", item3);
	depositItem(&myLocker, "14101941", item1);
	displayItemList(myLocker.IL);

	heavyItems = getHeavyItems(&myLocker, 1.00);
	displayItemList(myLocker.IL);
	displayItemList(heavyItems);

	return 0;
}
