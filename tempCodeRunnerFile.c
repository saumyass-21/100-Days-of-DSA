#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create a new node
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Function to insert at the end of doubly linked list
struct node* insertend(struct node* head, int data) {
    struct node* newnode = createnode(data);
    
    if (head == NULL) {							    	// If list is empty, new node becomes head
        return newnode;
    }
    
    struct node* temp = head;							// Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newnode;						    	// Update pointers for doubly linked list
    newnode->prev = temp;
    
    return head;
}

// Function to print the linked list in forward order
void printforward(struct node* head) {
    struct node* temp = head;
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to free the entire list
void freeList(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, value;
    struct node* head = NULL;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);								        // Read number of elements
    
    printf("Enter elements: ");							    // Read n elements and create doubly linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertend(head, value);
    }
    
    printf("Forward traversal: ");						    // Print the list in forward order
    printforward(head);
    
    freeList(head);								            // Free allocated memory
    
    return 0;
}