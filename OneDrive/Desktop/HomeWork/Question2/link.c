#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};


struct Deque {
    struct Node *front;
    struct Node *rear;
};

void initDeque(struct Deque *node) {
    node->front = node->rear = NULL;
}


int isEmpty(struct Deque *node) {
    return node->front == NULL;
}

void insertFront(struct Deque *node, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = node->front;
    newNode->prev = NULL;
    
    if (isEmpty(node)) {
        node->rear = newNode;
    } else {
        node->front->prev = newNode;
    }
    node->front = newNode;
    printf("Inserted %d at the front.\n", value);
}

void insertRear(struct Deque *node, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = node->rear;

    if (isEmpty(node)) {
        node->front = newNode;
    } else {
        node->rear->next = newNode;
    }
    node->rear = newNode;
    printf("Inserted %d at the rear\n", value);
}


int deleteFront(struct Deque *node) {
    if (isEmpty(node)) {
        printf("Deque is empty!\n");
        return -1;
    }
    
    struct Node *temp = node->front;
    int value = temp->data;
    node->front = node->front->next;
    if (node->front == NULL) {
       node->rear = NULL;
    } else {
        node->front->prev = NULL;
    }
    free(temp);
    return value;
}


int deleteRear(struct Deque *node) {
    if (isEmpty(node)) {
        printf("Deque is empty!\n");
        return -1;
    }
    
    struct Node *temp = node->rear;
    int value = temp->data;
    node->rear = node->rear->prev;
    if (node->rear == NULL) {
        node->front = NULL;
    } else {
        node->rear->next = NULL;
    }
    free(temp);
    return value;
}

void displayDeque(struct Deque *node) {
    if (isEmpty(node)) {
        printf("Deque is empty\n");
        return;
    }
    
    struct Node *temp = node->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque node;
    initDeque(&node);
    
    int n, value;
    printf("Enter the number of elements you want to insert into the deque: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter a value to insert at the rear: ");
        scanf("%d", &value);
        insertRear(&node, value);
    }

    displayDeque(&node);

    printf("Deleting from front: %d\n", deleteFront(&node));
    displayDeque(&node);

    printf("Deleting from rear: %d\n", deleteRear(&node));
    displayDeque(&node);

    return 0;
}
