#include <stdio.h>
#include <ctype.h>

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
        st.top++;
        st.arr[st.top] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

char pop() {
    if (!empty()) {
        char value = st.arr[st.top];
        st.top--;
        return value;
    } else {
        printf("Stack underflow!\n");
        return '\0';
    }
}

int prec(char c) {
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}


int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


void infix_to_postfix(const char* expression, char* output) {
    int j = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];

        if (current == ' ') continue;

        if (isalnum(current)) { 
            output[j++] = current;
        } else if (current == '(') {  
            push(current);
        } else if (current == ')') {  
            while (!empty() && st.arr[st.top] != '(') {
                output[j++] = pop();
            }
            if (!empty()) pop();  
        } else if (is_operator(current)) { 
            while (!empty() && prec(st.arr[st.top]) >= prec(current)) {
                output[j++] = pop();
            }
            push(current);
        }
    }

    while (!empty()) {
        output[j++] = pop();
    }
    output[j] = '\0';
}

int main() {
    st.top = -1; 
    char expression[SIZE], output[SIZE];

    printf("Enter the  expression: ");
    scanf("%s", expression);

    infix_to_postfix(expression, output);
    printf("Postfix expression: %s\n", output);

    return 0;
}
