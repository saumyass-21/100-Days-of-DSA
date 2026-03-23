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

Node* findNode(Node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }
    
    if (val < root->data) {
        return findNode(root->left, val);
    } else {
        return findNode(root->right, val);
    }
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL) return NULL;
    
    // If both nodes are smaller, go left
    if (p->data < root->data && q->data < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    }
    // If both nodes are larger, go right
    else if (p->data > root->data && q->data > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    }
    // Found LCA
    else {
        return root;
    }
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n, val1, val2;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    Node* root = NULL;
    
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insertBST(root, val);
    }
    
    printf("Enter two node values: ");
    scanf("%d %d", &val1, &val2);
    
    Node* p = findNode(root, val1);
    Node* q = findNode(root, val2);
    
    Node* lca = lowestCommonAncestor(root, p, q);
    
    printf("LCA: %d\n", lca->data);
    
    freeTree(root);
    
    return 0;
}