#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL, *newNode;
    
    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Create linked list by reading values one by one
    printf("Enter elements of linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        
        // Create new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        
        if (head == NULL) {
            // First node
            head = newNode;
            tail = newNode;
        } else {
            // Add to the end
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Traverse and print
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
    // Free memory
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}