#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void removeDuplicates(struct Node* head) {
    struct Node *current = head, *prev = NULL, *temp;
    
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            temp = current->next;
            current->next = temp->next;  
            free(temp);
        } else {
            current = current->next;  
        }
    }
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* merged = NULL, *tail = NULL;
  
    while (head1 != NULL && head2 != NULL) {
        struct Node* newNode;
        
        if (head1->data < head2->data) {
            newNode = createNode(head1->data);
            head1 = head1->next;
        } else {
            newNode = createNode(head2->data);
            head2 = head2->next;
        }
        
        if (merged == NULL) {
            merged = newNode;
            tail = merged;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    while (head1 != NULL) {
        struct Node* newNode = createNode(head1->data);
        tail->next = newNode;
        tail = tail->next;
        head1 = head1->next;
    }
    
    while (head2 != NULL) {
        struct Node* newNode = createNode(head2->data);
        tail->next = newNode;
        tail = tail->next;
        head2 = head2->next;
    }

    return merged;
}

void removeSortedDuplicates(struct Node* head) {
    struct Node *current = head;
    
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}


int main() {
    struct Node* head1 = NULL, *head2 = NULL;
    struct Node* merged = NULL;
    int n, value;

    printf("Enter the number of nodes for the first linked list: ");
    scanf("%d", &n);
    printf("Enter values for the first linked list:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        newNode->next = head1;
        head1 = newNode;
    }

    // Input for second linked list
    printf("Enter the number of nodes for the second linked list: ");
    scanf("%d", &n);
    printf("Enter values for the second linked list:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        newNode->next = head2;
        head2 = newNode;
    }

    printf("\nFirst Linked List:\n");
    printList(head1);
    printf("Second Linked List:\n");
    printList(head2);


    merged = mergeLists(head1, head2);
    printf("\nMerged Linked List:\n");
    printList(merged);

    
    removeDuplicates(merged);
    printf("\nLinked List after removing duplicates:\n");
    printList(merged);

    printf("\nEnter a sorted linked list for part c:\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct Node* sortedHead = NULL;
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        newNode->next = sortedHead;
        sortedHead = newNode;
    }

    printf("\nSorted Linked List:\n");
    printList(sortedHead);

   
    removeSortedDuplicates(sortedHead);
    printf("\nSorted Linked List after removing duplicates:\n");
    printList(sortedHead);

    return 0;
}
