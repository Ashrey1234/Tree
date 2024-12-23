#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Queue {
    int data[SIZE];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}


int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return q->rear ==SIZE - 1;
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->data[++q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is underflow\n");
        return -1;
    }
    int dequeuedValue = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; 
    } else {
        q->front++;
    }
    return dequeuedValue;
}

int size(struct Queue *q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q->rear - q->front + 1;
}


int findMax(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is underflow\n");
        return -1;
    }
    
    int elementMax = q->data[q->front];
    int sizeOfQueue = size(q);
    
    int tempQueue[SIZE];
    int tempRear = -1;

    for (int i = 0; i < sizeOfQueue; i++) {
        int element = dequeue(q);
        if (element > elementMax) {
            elementMax = element;
        }
        tempQueue[++tempRear] = element; 
    }

    for (int i = 0; i <= tempRear; i++) {
        enqueue(q, tempQueue[i]);
    }
    
    return elementMax;
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    
    int value;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&q, value);
    }

    int elementMax = findMax(&q);
    if (elementMax!= -1) {
        printf("The maximum element in the queue is: %d\n", elementMax);
    }

    return 0;
}
