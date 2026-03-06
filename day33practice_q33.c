#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// Stack structure for characters
struct Stack {
    char arr[MAX];
    int top;
};

// Function to initialize stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto stack
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->arr[stack->top--];
}

// Function to get top element without popping
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->arr[stack->top];
}

// Function to return precedence of operators
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack();
    int j = 0;  // Index for postfix expression
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        // If character is operand (A-Z, a-z, 0-9), add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If character is '(', push to stack
        else if (ch == '(') {
            push(stack, ch);
        }
        // If character is ')', pop until '(' is found
        else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);  // Remove '(' from stack
        }
        // If character is operator
        else if (isOperator(ch)) {
            // Pop operators with higher or equal precedence from stack
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(ch)) {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        }
        // Ignore spaces
        else if (ch == ' ') {
            continue;
        }
    }
    
    // Pop remaining operators from stack
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    
    postfix[j] = '\0';  // Null terminate the postfix expression
    
    free(stack);
}

int main() {
    char infix[MAX], postfix[MAX];
    
    // Read infix expression
    //printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    
    // Remove newline character if present
    int len = strlen(infix);
    if (infix[len-1] == '\n') {
        infix[len-1] = '\0';
    }
    
    // Convert to postfix
    infixToPostfix(infix, postfix);
    
    // Print postfix expression
    printf("%s\n", postfix);
    
    return 0;
}