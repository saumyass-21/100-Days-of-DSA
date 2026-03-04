#include <stdio.h>
#include <stdlib.h>

#define MAX 1000  // Maximum size of stack

// Stack structure
struct Stck {
    int arr[MAX];
    int top;
};

// Function to initialize stack
struct Stck* createStck() {
    struct Stck* stck = (struct Stck*)malloc(sizeof(struct Stck));
    stck->top = -1;
    return stck;
}

// Function to check if stack is empty
int isEmpty(struct Stck* stck) {
    return stck->top == -1;
}

// Function to check if stack is full
int isFull(struct Stck* stck) {
    return stck->top == MAX - 1;
}

// Function to push an element onto stack
void push(struct Stck* stck, int value) {
    if (isFull(stck)) {
        printf("Stack Overflow\n");
        return;
    }
    stck->arr[++stck->top] = value;
}

// Function to pop an element from stack
int pop(struct Stck* stck) {
    if (isEmpty(stck)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stck->arr[stck->top--];
}

// Function to display stack from top to bottom
void display(struct Stck* stck) {
    if (isEmpty(stck)) {
        return;
    }
    
    for (int i = stck->top; i >= 0; i--) {
        printf("%d ", stck->arr[i]);
    }
    printf("\n");
}

int main() {
    int n, m, value;
    struct Stck* stck = createStck();
    
    // Read number of elements to push
    scanf("%d", &n);
    
    // Read and push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(stck, value);
    }
    
    // Read number of pops
    scanf("%d", &m);
    
    // Perform m pop operations
    for (int i = 0; i < m; i++) {
        if (isEmpty(stck)) {
            break;  // Stop if stack becomes empty
        }
        pop(stck);
    }
    
    // Display remaining stack elements
    display(stck);
    
    // Free allocated memory
    free(stck);
    
    return 0;
}