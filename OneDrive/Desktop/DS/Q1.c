#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the node
typedef struct Node {
    char device[20];  // Device name
    int priority;     // Priority level
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(char *device, int priority) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->device, device);
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a request into the priority queue
Node* insertRequest(Node *head, char *device, int priority) {
    Node *newNode = createNode(device, priority);

    // If the list is empty or the new node has the highest priority
    if (!head || priority < head->priority) {
        newNode->next = head;
        return newNode;
    }

    // Traverse the list to find the correct position
    Node *current = head;
    while (current->next && current->next->priority <= priority) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Function to process and remove the highest priority request
Node* processRequest(Node *head) {
    if (!head) {
        printf("No requests to process.\n");
        return NULL;
    }

    Node *temp = head;
    printf("Processing request from: %s (Priority: %d)\n", head->device, head->priority);
    head = head->next;
    free(temp);

    return head;
}

// Function to display the queue
void displayQueue(Node *head) {
    if (!head) {
        printf("The queue is empty.\n");
        return;
    }

    printf("Current Priority Queue:\n");
    while (head) {
        printf("%s (Priority: %d) -> ", head->device, head->priority);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int choice, priority;
    char device[20];

    do {
        printf("\nDevice Request Management System:\n");
        printf("1. Add Request\n");
        printf("2. Process Request\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", device);
                printf("Enter priority (1-Keyboard, 2-Mouse, 3-Scanner, 4-Printer): ");
                scanf("%d", &priority);
                head = insertRequest(head, device, priority);
                break;
            case 2:
                head = processRequest(head);
                break;
            case 3:
                displayQueue(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
