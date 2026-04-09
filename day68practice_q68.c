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

void topologicalSort(Node** adj, int n) {
    int* indegree = (int*)calloc(n, sizeof(int));
    
    // Calculate indegree for each vertex
    for (int i = 0; i < n; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            indegree[temp->data]++;
            temp = temp->next;
        }
    }
    
    // Initialize queue with vertices having indegree 0
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    int* result = (int*)malloc(n * sizeof(int));
    int index = 0;
    
    while (front < rear) {
        int vertex = queue[front++];
        result[index++] = vertex;
        
        Node* temp = adj[vertex];
        while (temp != NULL) {
            int neighbor = temp->data;
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    
    if (index != n) {
        printf("Graph has a cycle! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    
    free(indegree);
    free(queue);
    free(result);
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