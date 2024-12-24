#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insertFront(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

Node* insertend(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (!head) {
        return newNode; 
    }

    Node *temp = head;
    while (temp->next) {
        temp = temp->next; 
    }
    temp->next = newNode;
    return head;
}

void display(Node *head) {
    printf("Linked List: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int choice, value;

    do {
        printf("\nLinked List Operations:\n");
        printf("1 Insert at Front\n");
        printf("2 Insert at end\n");
        printf("3 Display \n");
        printf("4 Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                head = insertFront(head, value);
                break;
            case 2:
                printf("Enter value to insert at back: ");
                scanf("%d", &value);
                head = insertend(head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting  the program\n");
                break;
            default:
                printf("Invalid choice \n");
        }
    } while (choice != 4);

    return 0;
}
