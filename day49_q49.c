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
        
        if (i < n) {
            if (arr[i] != -1) {
                current->left = createNode(arr[i]);
                queue[rear++] = current->left;
            }
            i++;
        }
        
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

Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else if (val > root->data) {
        root->right = insertBST(root->right, val);
    }
    
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    
    Node** queue = (Node**)malloc(sizeof(Node*) * 10000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        Node* current = queue[front++];
        
        if (current) {
            printf("%d ", current->data);
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        } else {
            printf("-1 ");
        }
    }
    
    free(queue);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n, val;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = NULL;
    Node* root = NULL;
    
    if (n > 0) {
        arr = (int*)malloc(sizeof(int) * n);
        printf("Enter level order traversal (-1 for NULL): ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        root = buildTree(arr, n);
        free(arr);
    }
    
    printf("Enter value to insert: ");
    scanf("%d", &val);
    
    root = insertBST(root, val);
    
    printf("Level order traversal after insertion: ");
    levelOrderTraversal(root);
    printf("\n");
    
    freeTree(root);
    
    return 0;
}