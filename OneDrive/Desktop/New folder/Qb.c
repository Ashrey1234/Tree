#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* push(node *top, int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

void display(node *top) {
    printf("Stack: ");
    while (top) {
        printf("%d ", top->data);
        top = top->next;
    }
  
}

int main() {
    node *top = NULL;
    int number, value;

    printf("Enter the number of elements to be pushed: ");
    scanf("%d", &number);

    for (int i = 0; i < number; i++) {
        printf("Enter the value to be  pusheshed: ");
        scanf("%d", &value);
        top = push(top, value);
    }

    display(top);
    return 0;
}
