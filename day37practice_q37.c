#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* arr;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPQ(int cap) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->arr = (int*)malloc(sizeof(int) * cap);
    pq->size = 0;
    pq->capacity = cap;
    return pq;
}

void insert(PriorityQueue* pq, int val) {
    if (pq->size == pq->capacity) return;
    
    // Add at end
    pq->arr[pq->size] = val;
    pq->size++;
    
    // Bubble up (smaller value = higher priority)
    int i = pq->size - 1;
    while (i > 0 && pq->arr[i] < pq->arr[(i-1)/2]) {
        int temp = pq->arr[i];
        pq->arr[i] = pq->arr[(i-1)/2];
        pq->arr[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int delete(PriorityQueue* pq) {
    if (pq->size == 0) return -1;
    
    int min = pq->arr[0];
    
    // Move last to root
    pq->arr[0] = pq->arr[pq->size-1];
    pq->size--;
    
    // Bubble down
    int i = 0;
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;
        
        if (left < pq->size && pq->arr[left] < pq->arr[smallest])
            smallest = left;
        if (right < pq->size && pq->arr[right] < pq->arr[smallest])
            smallest = right;
            
        if (smallest == i) break;
        
        int temp = pq->arr[i];
        pq->arr[i] = pq->arr[smallest];
        pq->arr[smallest] = temp;
        i = smallest;
    }
    
    return min;
}

int peek(PriorityQueue* pq) {
    if (pq->size == 0) return -1;
    return pq->arr[0];
}

void freePQ(PriorityQueue* pq) {
    free(pq->arr);
    free(pq);
}

int main() {
    int n;
    scanf("%d", &n);
    
    PriorityQueue* pq = createPQ(n);
    
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(pq, x);
        }
        else if (strcmp(op, "delete") == 0) {
            int val = delete(pq);
            if (val != -1) printf("%d\n", val);
            else printf("-1\n");
        }
        else if (strcmp(op, "peek") == 0) {
            int val = peek(pq);
            if (val != -1) printf("%d\n", val);
            else printf("-1\n");
        }
    }
    
    freePQ(pq);
    return 0;
}