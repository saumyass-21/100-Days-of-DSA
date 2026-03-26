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

void zigzagTraversal(Node* root) {
    if (root == NULL) return;
    
    Node** stack1 = (Node**)malloc(sizeof(Node*) * 10000);
    Node** stack2 = (Node**)malloc(sizeof(Node*) * 10000);
    int top1 = -1, top2 = -1;
    
    stack1[++top1] = root;
    
    while (top1 >= 0 || top2 >= 0) {
        // Print nodes in current level from left to right
        while (top1 >= 0) {
            Node* current = stack1[top1--];
            printf("%d ", current->data);
            
            // Push children to stack2 in order (left then right)
            if (current->left) stack2[++top2] = current->left;
            if (current->right) stack2[++top2] = current->right;
        }
        
        // Print nodes in next level from right to left
        while (top2 >= 0) {
            Node* current = stack2[top2--];
            printf("%d ", current->data);
            
            // Push children to stack1 in reverse order (right then left)
            if (current->right) stack1[++top1] = current->right;
            if (current->left) stack1[++top1] = current->left;
        }
    }
    
    free(stack1);
    free(stack2);
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
    
    printf("Zigzag Traversal: ");
    zigzagTraversal(root);
    printf("\n");
    
    freeTree(root);
    free(arr);
    
    return 0;
}