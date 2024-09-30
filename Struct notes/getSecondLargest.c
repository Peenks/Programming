#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef Node *Stack;

void displayStack(Stack stack) {
  while (stack != NULL) {
    printf("%d", stack->data);
    
    if (stack->next != NULL) {
      printf(", ");
    }
    
    stack = stack->next;
  }
  
  printf("\n");
}

int peekStack(Stack stack) {
  return (stack != NULL) ? stack->data : -1;
}

void push(Stack *stack, int data) {
  Node *temp = malloc(sizeof(Node));
  
  if (temp != NULL) {
    temp->data = data;
    temp->next = *stack;
    *stack = temp;
  }
}

void insertSorted(Stack *stack, int data) {
  Node *temp = malloc(sizeof(Node));
  
  if (temp == NULL) {
    return;
  }
  
  Stack dummy = NULL;
  
  while (*stack != NULL && peekStack(*stack) < data) {
    Node *next = (*stack)->next;
    
    (*stack)->next = dummy;
    dummy = *stack;
    
    *stack = next;
  }
  
  temp->data = data;
  temp->next = *stack;
  *stack = temp;
  
  while (dummy != NULL) {
    Node *next = dummy->next;
    
    dummy->next = *stack;
    *stack = dummy;
    
    dummy = next;
  }
}

void pop(Stack *stack) {
  Node *temp = *stack;
  *stack = (*stack)->next;
  free(temp);
}

int getSecondLargest(Stack stack) {
  Stack dummySecondLargest = NULL;
  Stack dummyStack = NULL;
  
  int secondLargestCount = 0;
  int limit = 2;
  
  while (stack != NULL) {
    Node *next = stack->next;
    
    stack->next = dummyStack;
    dummyStack = stack;
    
    int topStack = peekStack(stack);
    
    if (topStack > peekStack(dummySecondLargest) || secondLargestCount < limit) {
      insertSorted(&dummySecondLargest, topStack);
      secondLargestCount++;
      
      if (secondLargestCount > limit) {
        pop(&dummySecondLargest);
      }
    }
    
    stack = next;
  }
  
  while (dummyStack != NULL) {
    Node *next = dummyStack->next;
    
    dummyStack->next = stack;
    stack = dummyStack;
    
    dummyStack = next;
  }
  
  int secondLargest = peekStack(dummySecondLargest);
  
  while (dummySecondLargest != NULL) {
    pop(&dummySecondLargest);
  }
  
  return secondLargest;
}

int main() {
  Stack stack = NULL;
  
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  push(&stack, 4);
  push(&stack, 5);
  
  displayStack(stack);
  
  printf("Second Largest: %d\n", getSecondLargest(stack));
  
  return 0;
}