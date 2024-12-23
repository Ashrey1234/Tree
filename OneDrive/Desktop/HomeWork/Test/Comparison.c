#include <stdio.h>

#define SIZE 100

int stack1[SIZE]; 
int stack2[SIZE];
int top1 = -1, top2 = -1;

void push(int stack[], int* top, int value) {
    if (*top >= SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = value;
}

int pop(int stack[], int* top) {
    if (*top == -1) {
        return -1;
    }
    return stack[(*top)--];
}

int compareStacks() {
    if (top1 != top2) {
        return 0; 
    }
    
    for (int i = 0; i <= top1; i++) {
        if (stack1[i] != stack2[i]) {
            return 0;  
        }
    }
    
    return 1; 
}

int main() {
    int size1, size2;
    
  
    printf("Enter the number of elements in a stack 1: ");
    scanf("%d", &size1);
    
    for (int i = 0; i < size1; i++) {
        int value;
        printf("Enter the element for stack 1  %d: ", i + 1);
        scanf("%d", &value);
        push(stack1, &top1, value);
    }


    printf("Enter the number of elements in a stack 2: ");
    scanf("%d", &size2);
    
    for (int i = 0; i < size2; i++) {
        int value;
        printf("Enter element for stack 2  %d: ", i + 1);
        scanf("%d", &value);
        push(stack2, &top2, value);
    }
    
    if (compareStacks()) {
        printf("The stacks are same\n");
    } else {
        printf("The stacks are not same\n");
    }
    
    return 0;
}
