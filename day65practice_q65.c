#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

int hasCycleDFS(Node** adj, int* visited, int node, int parent) {
    visited[node] = 1;
    
    Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;
        
        if (!visited[neighbor]) {
            if (hasCycleDFS(adj, visited, neighbor, node)) {
                return 1;
            }
        }
        else if (neighbor != parent) {
            return 1;
        }
        
        temp = temp->next;
    }
    
    return 0;
}

int detectCycle(Node** adj, int n) {
    int* visited = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(adj, visited, i, -1)) {
                free(visited);
                return 1;
            }
        }
    }
    
    free(visited);
    return 0;
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
    int n, m;
    
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
    
    if (detectCycle(adj, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    freeGraph(adj, n);
    
    return 0;
}