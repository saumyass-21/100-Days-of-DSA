#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for stack using linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to push an element onto stack
struct Node* push(struct Node* top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

// Function to pop an element from stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        return 0;
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expression) {
    struct Node* stack = NULL;
    char* token = strtok(expression, " ");
    
    while (token != NULL) {
        // If token is a number, push to stack
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            stack = push(stack, atoi(token));
        }
        // If token is an operator
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;
            
            switch(token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    result = 0;
            }
            stack = push(stack, result);
        }
        token = strtok(NULL, " ");
    }
    
    int finalResult = pop(&stack);
    return finalResult;
}

// Function to free the entire stack
void freeStack(struct Node* top) {
    struct Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    char expression[1000];
    
    // Read postfix expression
    fgets(expression, 1000, stdin);
    
    // Remove newline character if present
    int len = strlen(expression);
    if (expression[len-1] == '\n') {
        expression[len-1] = '\0';
    }
    
    // Evaluate and print result
    int result = evaluatePostfix(expression);
    printf("%d\n", result);
    
    return 0;
}