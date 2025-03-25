#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int removeAllOccurrences(Node **head, int value) {
    int count = 0;
    Node *temp = *head;
    Node *prev = NULL;

    while (temp != NULL) {
        if (temp->data == value) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
            count++;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    return count;
}

void insert(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void display(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    
    insert(&head, 2);
    insert(&head, 6);
    insert(&head, 2);
    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printf("Original list:\n");
    display(head);

    int value;
    printf("Enter value to remove: ");
    scanf("%d", &value);

    int removedCount = removeAllOccurrences(&head, value);
    printf("Number of elements removed: %d\n", removedCount);

    printf("Updated list:\n");
    display(head);

    return 0;
}