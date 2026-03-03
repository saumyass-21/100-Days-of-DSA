#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // Maximum size of stack

// Stack structure
struct stck {
    int arr[MAX];
    int top;
};

// Function to initialize stack
struct stck* createstck() {
    struct stck* stack = (struct stck*)malloc(sizeof(struct stck));
    stack->top = -1;
    return stack;
}

// Function to check if stack is full
int isfull(struct stck* stack) {
    return stack->top == MAX - 1;
}

// Function to check if stack is empty
int isempty(struct stck* stack) {
    return stack->top == -1;
}

// Function to push an element onto stack
void push(struct stck* stack, int value) {
    if (isfull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from stack
int pop(struct stck* stack) {
    if (isempty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to display stack elements from top to bottom
void display(struct stck* stack) {
    if (isempty(stack)) {
        return;
    }
    
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    int n, op, value;
    struct stck* stack = createstck();
    
    // Read number of operations
    scanf("%d", &n);
    
    // Process each operation
    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        
        switch(op) {
            case 1:  // Push
                scanf("%d", &value);
                push(stack, value);
                break;
                
            case 2:  // Pop
                value = pop(stack);
                if (value != -1) {
                    printf("%d\n", value);
                }
                break;
                
            case 3:  // Display
                display(stack);
                break;
                
            default:
                printf("Invalid operation\n");
        }
    }
    
    // Free allocated memory
    free(stack);
    
    return 0;
}