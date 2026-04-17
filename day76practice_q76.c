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

void dfs(Node** adj, int* visited, int node) {
    visited[node] = 1;
    
    Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            dfs(adj, visited, neighbor);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    Node** adj = (Node**)malloc((n + 1) * sizeof(Node*));
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }
    
    printf("Enter %d edges:\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    
    int* visited = (int*)calloc(n + 1, sizeof(int));
    int components = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, i);
            components++;
        }
    }
    
    printf("Number of connected components: %d\n", components);
    
    // Free memory
    for (int i = 1; i <= n; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adj);
    free(visited);
    
    return 0;
}