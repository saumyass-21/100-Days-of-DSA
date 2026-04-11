#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int u;
    int v;
    int w;
} Edge;

void bellmanFord(Edge* edges, int n, int m, int src) {
    int* dist = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    
    // Relax edges n-1 times
    for (int i = 1; i < n; i++) {
        int updated = 0;
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = 1;
            }
        }
        if (!updated) break;
    }
    
    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            free(dist);
            return;
        }
    }
    
    // Print shortest distances
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("Vertex %d: INF\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
    
    free(dist);
}

int main() {
    int n, m, src;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    Edge* edges = (Edge*)malloc(m * sizeof(Edge));
    
    printf("Enter %d edges (u v w):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
    bellmanFord(edges, n, m, src);
    
    free(edges);
    
    return 0;
}