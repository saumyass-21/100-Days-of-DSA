#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Node {
    int vertex;
    int dist;
} Node;

Edge* createEdge(int dest, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(Edge** adj, int u, int v, int w) {
    Edge* newEdge = createEdge(v, w);
    newEdge->next = adj[u];
    adj[u] = newEdge;
}

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Node* heap, int* pos, int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;
    
    if (smallest != i) {
        pos[heap[i].vertex] = smallest;
        pos[heap[smallest].vertex] = i;
        swap(&heap[i], &heap[smallest]);
        heapify(heap, pos, size, smallest);
    }
}

void push(Node* heap, int* size, int* pos, int vertex, int dist) {
    int i = *size;
    heap[i].vertex = vertex;
    heap[i].dist = dist;
    pos[vertex] = i;
    (*size)++;
    
    while (i > 0 && heap[i].dist < heap[(i-1)/2].dist) {
        pos[heap[i].vertex] = (i-1)/2;
        pos[heap[(i-1)/2].vertex] = i;
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

Node pop(Node* heap, int* size, int* pos) {
    Node min = heap[0];
    heap[0] = heap[--(*size)];
    pos[heap[0].vertex] = 0;
    heapify(heap, pos, *size, 0);
    return min;
}

void dijkstra(Edge** adj, int n, int src) {
    int* dist = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));
    int* pos = (int*)malloc(n * sizeof(int));
    Node* heap = (Node*)malloc(n * sizeof(Node));
    int size = 0;
    
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        pos[i] = -1;
    }
    
    dist[src] = 0;
    push(heap, &size, pos, src, 0);
    
    while (size > 0) {
        Node current = pop(heap, &size, pos);
        int u = current.vertex;
        
        if (visited[u]) continue;
        visited[u] = 1;
        
        Edge* temp = adj[u];
        while (temp != NULL) {
            int v = temp->dest;
            int w = temp->weight;
            
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (pos[v] != -1) {
                    heap[pos[v]].dist = dist[v];
                    heapify(heap, pos, size, pos[v]);
                } else {
                    push(heap, &size, pos, v, dist[v]);
                }
            }
            temp = temp->next;
        }
    }
    
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
    
    free(dist);
    free(visited);
    free(pos);
    free(heap);
}

void freeGraph(Edge** adj, int n) {
    for (int i = 0; i < n; i++) {
        Edge* temp = adj[i];
        while (temp != NULL) {
            Edge* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adj);
}

int main() {
    int n, m, src;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    Edge** adj = (Edge**)malloc(sizeof(Edge*) * n);
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }
    
    printf("Enter %d edges (u v w):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w);
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
    dijkstra(adj, n, src);
    
    freeGraph(adj, n);
    
    return 0;
}