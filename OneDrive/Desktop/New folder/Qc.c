#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 100

typedef struct {
    char stack[SIZE];
    int top;
} CharStack;

typedef struct {
    double stack[SIZE];
    int top;
} DoubleStack;

void pushChar(CharStack *s, char value) {
    if (s->top == SIZE - 1) {
        printf("Stack is overflow\n");
        return;
    }
    s->stack[++s->top] = value;
}

char popChar(CharStack *s) {
    if (s->top == -1) {
        printf("Stack is underflow\n");
        return '\0';
    }
    return s->stack[s->top--];
}

char peekChar(CharStack *s) {
    if (s->top == -1) return '\0';
    return s->stack[s->top];
}

void pushDouble(DoubleStack *s, double value) {
    if (s->top == SIZE - 1) {
        printf("The stack  is overflow\n");
        return;
    }
    s->stack[++s->top] = value;
}

double popDouble(DoubleStack *s) {
    if (s->top == -1) {
        printf("The stack is underflow\n");
        return 0;
    }
    return s->stack[s->top--];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char *infix, char *postfix) {
    CharStack stack = {.top = -1};
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch; 
        } else if (ch == '(') {
            pushChar(&stack, ch);
        } else if (ch == ')') {
            while (stack.top != -1 && peekChar(&stack) != '(') {
                postfix[j++] = popChar(&stack);
            }
            popChar(&stack); 
        } else if (isOperator(ch)) {
            while (stack.top != -1 && precedence(peekChar(&stack)) >= precedence(ch)) {
                postfix[j++] = popChar(&stack);
            }
            pushChar(&stack, ch);
        }
        i++;
    }

    while (stack.top != -1) {
        postfix[j++] = popChar(&stack);
    }
    postfix[j] = '\0'; 
}

double evaluatePostfix(char *postfix, double values[]) {
    DoubleStack stack = {.top = -1};
    int i = 0;

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if (isalpha(ch)) {
            pushDouble(&stack, values[ch - 'a']); 
        } else if (isOperator(ch)) {
            double operand2 = popDouble(&stack);
            double operand1 = popDouble(&stack);
            switch (ch) {
                case '+': pushDouble(&stack, operand1 + operand2);
				 break;
                case '-': pushDouble(&stack, operand1 - operand2); 
				break;
                case '*': pushDouble(&stack, operand1 * operand2);
				 break;
                case '/': pushDouble(&stack, operand1 / operand2);
				 break;
                case '^': pushDouble(&stack, pow(operand1, operand2));
				 break;
            }
        }
        i++;
    }
    return popDouble(&stack);
}

int main() {
    char infix[] = "((a+b)^((c/d)*e))";
    char postfix[SIZE];
    double values[26]; 

    values['a' - 'a'] = 2;
    values['b' - 'a'] = 6;
    values['c' - 'a'] = 3;
    values['d' - 'a'] = 2;
    values['e' - 'a'] = -2;

    infixToPostfix(infix, postfix);

    printf("The infix expression: %s\n", infix);
    printf("The postfix expression: %s\n", postfix);

    double result = evaluatePostfix(postfix, values);
    printf("The evaluated  result : %.2f\n", result);

    return 0;
}
