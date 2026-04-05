#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node** adj, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
    
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

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

int isEmpty(Queue* q) {
    return q->size == 0;
}

void freeQueue(Queue* q) {
    free(q->arr);
    free(q);
}

void bfs(Node** adj, int n, int start) {
    int* visited = (int*)calloc(n, sizeof(int));
    Queue* q = createQueue(n);
    
    visited[start] = 1;
    enqueue(q, start);
    
    while (!isEmpty(q)) {
        int vertex = dequeue(q);
        printf("%d ", vertex);
        
        Node* temp = adj[vertex];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(q, neighbor);
            }
            temp = temp->next;
        }
    }
    
    free(visited);
    freeQueue(q);
}

void freeGraph(Node** adj, int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adj);
}

int main() {
    int n, m, s;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    Node** adj = (Node**)malloc(sizeof(Node*) * n);
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }
    
    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    
    printf("BFS Traversal: ");
    bfs(adj, n, s);
    printf("\n");
    
    freeGraph(adj, n);
    
    return 0;
}