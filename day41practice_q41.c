#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

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
    printf("  Enqueued: %d\n", val);
}

int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;
    
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return val;
}

int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    
    printf("\nAvailable operations:\n");
    printf("enqueue <value> - Add element to queue\n");
    printf("dequeue - Remove element from queue\n\n");
    
    Queue* q = createQueue();
    
    for (int i = 0; i < n; i++) {
        char op[10];
        printf("Operation %d: ", i+1);
        scanf("%s", op);
        
        if (strcmp(op, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(q, x);
        } else if (strcmp(op, "dequeue") == 0) {
            int val = dequeue(q);
            if (val == -1)
                printf("Queue empty! Cannot dequeue\n");
            else
                printf("Dequeued: %d\n", val);
        } else {
            printf("Invalid operation! Use 'enqueue' or 'dequeue'\n");
            i--; // Don't count invalid operations
        }
    }
    
    // Clean up
    while (q->front != NULL) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
    
    return 0;
}