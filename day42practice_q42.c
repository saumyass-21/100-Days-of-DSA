#include <stdio.h>
#include <stdlib.h>

// Node structure for queue and stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Stack structure
typedef struct {
    Node* top;
} Stack;

// Queue functions
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return val;
}

// Stack functions
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) return -1;
    
    Node* temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Reverse queue using stack
void reverseQueue(Queue* q) {
    Stack* s = createStack();
    
    // Dequeue all elements and push to stack
    while (q->front != NULL) {
        push(s, dequeue(q));
    }
    
    // Pop all elements and enqueue back
    while (!isEmpty(s)) {
        enqueue(q, pop(s));
    }
    
    free(s);
}

// Display queue
void display(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    Queue* q = createQueue();
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }
    
    printf("\nOriginal queue: ");
    display(q);
    
    reverseQueue(q);
    
    printf("Reversed queue: ");
    display(q);
    
    // Free memory
    while (q->front != NULL) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
    
    return 0;
}