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

bool isMirror(Node* left, Node* right) {
    // Both empty
    if (left == NULL && right == NULL) return true;
    
    // One empty, one not
    if (left == NULL || right == NULL) return false;
    
    // Check current nodes and recursively check subtrees
    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(Node* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
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
    printf("Enter level order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    
    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    freeTree(root);
    free(arr);
    
    return 0;
}