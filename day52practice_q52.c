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

Node* find(Node* root, int val) {
    if (!root) return NULL;
    if (root->data == val) return root;
    Node* left = find(root->left, val);
    if (left) return left;
    return find(root->right, val);
}

Node* LCA(Node* root, Node* p, Node* q) {
    if (!root || root == p || root == q) return root;
    
    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);
    
    if (left && right) return root;
    return left ? left : right;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n, v1, v2;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter level order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter two node values to find LCA: ");
    scanf("%d %d", &v1, &v2);
    
    Node* root = buildTree(arr, n);
    Node* p = find(root, v1);
    Node* q = find(root, v2);
    Node* lca = LCA(root, p, q);
    
    printf("Lowest Common Ancestor: %d\n", lca->data);
    
    freeTree(root);
    free(arr);
    return 0;
}