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
        Node* current = queue[front++];
        
        // Left child
        if (i < n) {
            if (arr[i] != -1) {
                current->left = createNode(arr[i]);
                queue[rear++] = current->left;
            }
            i++;
        }
        
        // Right child
        if (i < n) {
            if (arr[i] != -1) {
                current->right = createNode(arr[i]);
                queue[rear++] = current->right;
            }
            i++;
        }
    }
    
    free(queue);
    return root;
}

int countLeaves(Node* root) {
    if (root == NULL) return 0;
    
    // If it's a leaf node
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    // Otherwise count leaves in left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n == 0) {
        printf("Number of leaf nodes: 0\n");
        return 0;
    }
    
    int* arr = (int*)malloc(sizeof(int) * n);
    
    printf("Enter level order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    
    int leafCount = countLeaves(root);
    printf("Number of leaf nodes: %d\n", leafCount);
    
    freeTree(root);
    free(arr);
    
    return 0;
}