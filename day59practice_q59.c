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

Node* buildTree(int* inorder, int* postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }
    
    // Last element in postorder is root
    int rootVal = postorder[postEnd];
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
    int rightSize = inEnd - rootIndex;
    
    // Build left and right subtrees
    root->left = buildTree(inorder, postorder,
                          inStart, rootIndex - 1,
                          postStart, postStart + leftSize - 1);
    
    root->right = buildTree(inorder, postorder,
                           rootIndex + 1, inEnd,
                           postStart + leftSize, postEnd - 1);
    
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
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
    
    int* inorder = (int*)malloc(sizeof(int) * n);
    int* postorder = (int*)malloc(sizeof(int) * n);
    
    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    
    printf("Enter postorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }
    
    Node* root = buildTree(inorder, postorder, 0, n - 1, 0, n - 1);
    
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    freeTree(root);
    free(inorder);
    free(postorder);
    
    return 0;
}