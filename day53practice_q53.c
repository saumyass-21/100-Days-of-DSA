#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QueueNode {
    Node* treeNode;
    int hd;  // horizontal distance
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

typedef struct MapNode {
    int hd;
    int* values;
    int count;
    int capacity;
    struct MapNode* next;
} MapNode;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    Node* root = createNode(arr[0]);
    Node** queue = (Node**)malloc(sizeof(Node*) * n);
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    int i = 1;
    while (i < n && front < rear) {
        Node* cur = queue[front++];
        
        if (i < n && arr[i] != -1) {
            cur->left = createNode(arr[i]);
            queue[rear++] = cur->left;
        }
        i++;
        
        if (i < n && arr[i] != -1) {
            cur->right = createNode(arr[i]);
            queue[rear++] = cur->right;
        }
        i++;
    }
    
    free(queue);
    return root;
}

void enqueue(Queue* q, Node* node, int hd) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->hd = hd;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

QueueNode* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    
    QueueNode* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    return temp;
}

MapNode* createMapNode(int hd) {
    MapNode* newNode = (MapNode*)malloc(sizeof(MapNode));
    newNode->hd = hd;
    newNode->values = (int*)malloc(sizeof(int) * 100);
    newNode->count = 0;
    newNode->capacity = 100;
    newNode->next = NULL;
    return newNode;
}

void addValue(MapNode** head, int hd, int val) {
    MapNode* current = *head;
    MapNode* prev = NULL;
    
    // Find or create node for this horizontal distance
    while (current != NULL && current->hd != hd) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        current = createMapNode(hd);
        if (prev == NULL) {
            *head = current;
        } else {
            prev->next = current;
        }
    }
    
    // Add value to the list
    if (current->count >= current->capacity) {
        current->capacity *= 2;
        current->values = (int*)realloc(current->values, sizeof(int) * current->capacity);
    }
    current->values[current->count++] = val;
}

void freeMap(MapNode* head) {
    while (head) {
        MapNode* temp = head;
        head = head->next;
        free(temp->values);
        free(temp);
    }
}

void verticalTraversal(Node* root) {
    if (root == NULL) return;
    
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    
    MapNode* map = NULL;
    
    enqueue(q, root, 0);
    
    while (q->front != NULL) {
        QueueNode* current = dequeue(q);
        Node* node = current->treeNode;
        int hd = current->hd;
        
        addValue(&map, hd, node->data);
        
        if (node->left) {
            enqueue(q, node->left, hd - 1);
        }
        if (node->right) {
            enqueue(q, node->right, hd + 1);
        }
        
        free(current);
    }
    
    // Sort map by horizontal distance (simple bubble sort for linked list)
    MapNode* sorted = map;
    while (sorted) {
        MapNode* next = sorted->next;
        while (next) {
            if (sorted->hd > next->hd) {
                int tempHd = sorted->hd;
                sorted->hd = next->hd;
                next->hd = tempHd;
                
                int* tempVals = sorted->values;
                int tempCount = sorted->count;
                int tempCap = sorted->capacity;
                
                sorted->values = next->values;
                sorted->count = next->count;
                sorted->capacity = next->capacity;
                
                next->values = tempVals;
                next->count = tempCount;
                next->capacity = tempCap;
            }
            next = next->next;
        }
        sorted = sorted->next;
    }
    
    // Print results
    sorted = map;
    while (sorted) {
        for (int i = 0; i < sorted->count; i++) {
            printf("%d ", sorted->values[i]);
        }
        printf("\n");
        sorted = sorted->next;
    }
    
    free(q);
    freeMap(map);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    if (n == 0) return 0;
    
    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter level order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    
    printf("\nVertical Order Traversal:\n");
    verticalTraversal(root);
    
    freeTree(root);
    free(arr);
    
    return 0;
}