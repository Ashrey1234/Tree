#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100  
struct stack {
    char arr[SIZE];
    int top;
} st;

int empty() {
    return st.top == -1;
}

int full() {
    return st.top >= SIZE - 1;
}

void push(char value) {
    if (!full()) {
        st.arr[++st.top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

char pop() {
    if (!empty()) {
        return st.arr[st.top--];
    }
    printf("Stack underflow\n");
    return 0;
}

char peek() {
    if (!empty()) {
        return st.arr[st.top];
    }
    return 0;
}

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void infixToPrefix(const char* infix, char* prefix) {
    char reversed[SIZE], postfix[SIZE];
    int j = 0;

    strcpy(reversed, infix);
    reverse(reversed);

    // Replace '(' with ')' and vice versa
    for (int i = 0; reversed[i] != '\0'; i++) {
        if (reversed[i] == '(') {
            reversed[i] = ')';
        } else if (reversed[i] == ')') {
            reversed[i] = '(';
        }
    }

    // Convert the reversed expression to postfix
    for (int i = 0; reversed[i] != '\0'; i++) {
        char current = reversed[i];

        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            push(current);
        } else if (current == ')') {
            while (!empty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from the stack
        } else if (isOperator(current)) {
            while (!empty() && prec(peek()) >= prec(current)) {
                postfix[j++] = pop();
            }
            push(current);
        }
    }

    // Pop remaining operators from the stack
    while (!empty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    // Reverse the postfix expression to get the prefix expression
    strcpy(prefix, postfix);
    reverse(prefix);
}

int main() {
    st.top = -1;
    char infix[SIZE], prefix[SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
