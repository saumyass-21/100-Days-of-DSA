#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

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
    
    newEdge = createEdge(u, w);
    newEdge->next = adj[v];
    adj[v] = newEdge;
}

int primMST(Edge** adj, int n) {
    int* key = (int*)malloc(n * sizeof(int));
    int* inMST = (int*)calloc(n, sizeof(int));
    int* parent = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < n - 1; count++) {
        // Find vertex with minimum key value not yet in MST
        int u = -1;
        int minKey = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }
        
        if (u == -1) break;
        inMST[u] = 1;
        
        // Update key values of adjacent vertices
        Edge* temp = adj[u];
        while (temp) {
            int v = temp->dest;
            int w = temp->weight;
            
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }
    
    // Calculate total weight
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        if (key[i] != INT_MAX) {
            totalWeight += key[i];
        }
    }
    
    free(key);
    free(inMST);
    free(parent);
    
    return totalWeight;
}

void freeGraph(Edge** adj, int n) {
    for (int i = 0; i < n; i++) {
        Edge* temp = adj[i];
        while (temp) {
            Edge* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adj);
}

int main() {
    int n, m;
    
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    Edge** adj = (Edge**)malloc(n * sizeof(Edge*));
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }
    
    printf("Enter %d edges (u v w):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u - 1, v - 1, w); // Convert to 0-based indexing
    }
    
    int mstWeight = primMST(adj, n);
    printf("Total weight of MST: %d\n", mstWeight);
    
    freeGraph(adj, n);
    
    return 0;
}