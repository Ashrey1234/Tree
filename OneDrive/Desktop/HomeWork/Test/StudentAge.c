#include <stdio.h>
#include <string.h>

#define SIZE 5 

struct Student {
    char name[30];  
    int age;       
};


struct Student stack[SIZE];
int top = -1; 

int isFull() {
    return top == SIZE - 1;
}

int isEmpty() {
    return top == -1;
}


void push(struct Student student) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = student;  
    printf("Student added: %s, Age: %d\n", student.name, student.age);
}

struct Student pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        struct Student empty = {"", 0};
        return empty;
    }
    return stack[top--];  
}

void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Students in the stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("Name: %s, Age: %d\n", stack[i].name, stack[i].age);
    }
}

int main() {
    int n;
    struct Student student;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]%*c", student.name); 
        printf("Enter age of student %d: ", i + 1);
        scanf("%d", &student.age);
        
        push(student);
    }

    displayStack();
    
 
    printf("\nThe deleted  students from the stack:\n");
    while (!isEmpty()) {
        struct Student deleted = pop();
        printf("deleted: %s, Age: %d\n", deleted.name, deleted.age);
    }

    return 0;
}
