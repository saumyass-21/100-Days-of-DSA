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

int dfs(Node** adj, int* vis, int* recStack, int node) {
    vis[node] = 1;
    recStack[node] = 1;
    
    Node* temp = adj[node];
    while (temp != NULL) {
        int nei = temp->data;
        
        if (!vis[nei]) {
            if (dfs(adj, vis, recStack, nei)) return 1;
        }
        else if (recStack[nei]) return 1;
        
        temp = temp->next;
    }
    
    recStack[node] = 0;
    return 0;
}

int hasCycle(Node** adj, int n) {
    int* vis = (int*)calloc(n, sizeof(int));
    int* recStack = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(adj, vis, recStack, i)) {
                free(vis);
                free(recStack);
                return 1;
            }
        }
    }
    
    free(vis);
    free(recStack);
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
    
    printf("Enter %d directed edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    
    if (hasCycle(adj, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    freeGraph(adj, n);
    
    return 0;
}