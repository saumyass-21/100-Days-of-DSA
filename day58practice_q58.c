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

Node* buildTree(int* preorder, int* inorder, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }
    
    int rootVal = preorder[preStart];
    Node* root = createNode(rootVal);
    
    // Find root in inorder
    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }
    
    int leftSize = rootIndex - inStart;
    
    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, 
                          preStart + 1, preStart + leftSize,
                          inStart, rootIndex - 1);
    
    root->right = buildTree(preorder, inorder,
                           preStart + leftSize + 1, preEnd,
                           rootIndex + 1, inEnd);
    
    return root;
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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
    
    int* preorder = (int*)malloc(sizeof(int) * n);
    int* inorder = (int*)malloc(sizeof(int) * n);
    
    printf("Enter preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }
    
    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    
    Node* root = buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    
    freeTree(root);
    free(preorder);
    free(inorder);
    
    return 0;
}