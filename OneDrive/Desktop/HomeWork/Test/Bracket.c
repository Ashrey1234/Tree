#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

int checkParentheses(char expression[]) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];
        
        if (current == '(') {
            push(current);
        } else if (current == ')') {
            if (pop() == -1) {
                return 0;  
            }
        }
    }
    
    return top == -1;  
}

int main() {
    char expression[SIZE];
    printf("Enter an expression with parentheses: ");
    scanf("%s", expression);
    
    if (checkParentheses(expression)) {
        printf("Parentheses are properly nested.\n");
    } else {
        printf("Parentheses are not properly nested.\n");
    }
    
    return 0;
}
