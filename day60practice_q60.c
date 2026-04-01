#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isMinHeap(Node* root) {
    if (root == NULL) return true;
    
    // Check left child
    if (root->left != NULL) {
        if (root->data > root->left->data) {
            return false;
        }
    }
    
    // Check right child
    if (root->right != NULL) {
        if (root->data > root->right->data) {
            return false;
        }
    }
    
    // Recursively check left and right subtrees
    return isMinHeap(root->left) && isMinHeap(root->right);
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
        printf("YES\n");
        return 0;
    }
    
    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter level order traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    
    if (isMinHeap(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    freeTree(root);
    free(arr);
    
    return 0;
}