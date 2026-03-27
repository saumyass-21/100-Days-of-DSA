#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

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

void rightSideView(Node* root) {
    if (root == NULL) return;
    
    Node** queue = (Node**)malloc(sizeof(Node*) * 10000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        int levelSize = rear - front;
        
        for (int i = 0; i < levelSize; i++) {
            Node* current = queue[front++];
            
            // Last node in current level is visible from right
            if (i == levelSize - 1) {
                printf("%d ", current->data);
            }
            
            if (current->left) queue[rear++] = current->left;
            if (current->right) queue[rear++] = current->right;
        }
    }
    
    free(queue);
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
    
    if (n == 0) {
        printf("No nodes to display\n");
        return 0;
    }
    
    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter level order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    
    printf("Right View: ");
    rightSideView(root);
    printf("\n");
    
    freeTree(root);
    free(arr);
    
    return 0;
}