#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int cap) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(sizeof(int) * cap);
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = cap;
    return q;
}

void enqueue(Queue* q, int val) {
    if (q->size == q->capacity) return;
    q->arr[q->rear] = val;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

int dequeue(Queue* q) {
    if (q->size == 0) return -1;
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

void display(Queue* q) {
    if (q->size == 0) return;
    for (int i = 0; i < q->size; i++) {
        int idx = (q->front + i) % q->capacity;
        printf("%d ", q->arr[idx]);
    }
}

void freeQueue(Queue* q) {
    free(q->arr);
    free(q);
}

int main() {
    int n, val;
    scanf("%d", &n);
    
    Queue* q = createQueue(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }
    
    display(q);
    freeQueue(q);
    
    return 0;
}