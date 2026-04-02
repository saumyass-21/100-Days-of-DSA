#include <stdio.h>

int main() {
    int n, m;
    
    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);

    int adj[n][n];

    // Initialize matrix with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;

    // Input edges
    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;

        // For directed graph, comment above line and use:
        // adj[u][v] = 1;
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}