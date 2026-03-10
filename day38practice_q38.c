#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int count;
    int capacity;
} Deque;

Deque* createDeque(int k) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->arr = (int*)malloc(sizeof(int) * k);
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
    dq->capacity = k;
    return dq;
}

bool push_front(Deque* dq, int val) {
    if (dq->count == dq->capacity) return false;
    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->arr[dq->front] = val;
    dq->count++;
    return true;
}

bool push_back(Deque* dq, int val) {
    if (dq->count == dq->capacity) return false;
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->arr[dq->rear] = val;
    dq->count++;
    return true;
}

int pop_front(Deque* dq) {
    if (dq->count == 0) return -1;
    int val = dq->arr[dq->front];
    dq->front = (dq->front + 1) % dq->capacity;
    dq->count--;
    return val;
}

int pop_back(Deque* dq) {
    if (dq->count == 0) return -1;
    int val = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->count--;
    return val;
}

int front(Deque* dq) {
    return (dq->count == 0) ? -1 : dq->arr[dq->front];
}

int back(Deque* dq) {
    return (dq->count == 0) ? -1 : dq->arr[dq->rear];
}

bool empty(Deque* dq) {
    return dq->count == 0;
}

int size(Deque* dq) {
    return dq->count;
}

void clear(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
}

void display(Deque* dq) {
    if (empty(dq)) {
        printf("Deque empty\n");
        return;
    }
    for (int i = 0; i < dq->count; i++) {
        int idx = (dq->front + i) % dq->capacity;
        printf("%d ", dq->arr[idx]);
    }
    printf("\n");
}

int main() {
    int k, n, val;
    char op[20];
    
    scanf("%d", &k);
    scanf("%d", &n);
    
    Deque* dq = createDeque(k);
    
    while (n--) {
        scanf("%s", op);
        
        if (strcmp(op, "push_f") == 0) {
            scanf("%d", &val);
            if (push_front(dq, val)) printf("ok\n");
            else printf("full\n");
        }
        else if (strcmp(op, "push_b") == 0) {
            scanf("%d", &val);
            if (push_back(dq, val)) printf("ok\n");
            else printf("full\n");
        }
        else if (strcmp(op, "pop_f") == 0) {
            int x = pop_front(dq);
            if (x == -1) printf("empty\n");
            else printf("%d\n", x);
        }
        else if (strcmp(op, "pop_b") == 0) {
            int x = pop_back(dq);
            if (x == -1) printf("empty\n");
            else printf("%d\n", x);
        }
        else if (strcmp(op, "front") == 0) {
            int x = front(dq);
            if (x == -1) printf("empty\n");
            else printf("%d\n", x);
        }
        else if (strcmp(op, "back") == 0) {
            int x = back(dq);
            if (x == -1) printf("empty\n");
            else printf("%d\n", x);
        }
        else if (strcmp(op, "empty") == 0) {
            printf(empty(dq) ? "true\n" : "false\n");
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size(dq));
        }
        else if (strcmp(op, "clear") == 0) {
            clear(dq);
            printf("ok\n");
        }
        else if (strcmp(op, "display") == 0) {
            display(dq);
        }
    }
    
    free(dq->arr);
    free(dq);
    return 0;
}