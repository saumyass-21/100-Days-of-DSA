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
}

void dfs(Node** adj, int* vis, int* stack, int* top, int node) {
    vis[node] = 1;
    
    Node* temp = adj[node];
    while (temp != NULL) {
        int nei = temp->data;
        if (!vis[nei]) {
            dfs(adj, vis, stack, top, nei);
        }
        temp = temp->next;
    }
    
    stack[++(*top)] = node;
}

void topologicalSort(Node** adj, int n) {
    int* vis = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(adj, vis, stack, &top, i);
        }
    }
    
    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    
    free(vis);
    free(stack);
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
    
    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    
    topologicalSort(adj, n);
    
    freeGraph(adj, n);
    
    return 0;
}