#include <stdio.h>
#include <stdlib.h>

// node structure for circular linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert at the end of circular linked list
struct node* insertend(struct node* head, int data) {
    struct node* newnode = createnode(data);
    
    // If list is empty
    if (head == NULL) {
        newnode->next = newnode;  // Point to itself
        return newnode;
    }
    
    // Find the last node
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    // Insert at the end
    temp->next = newnode;
    newnode->next = head;  // New node points back to head
    
    return head;
}

// Function to traverse and print circular linked list
void printcircularlist(struct node* head) {
    if (head == NULL) {
        return;
    }
    
    struct node* temp = head;
    
    // Traverse until we come back to head
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

// Function to free the entire circular list
void freecircularlist(struct node* head) {
    if (head == NULL) {
        return;
    }
    
    // Break the circular link first to avoid infinite loop
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = NULL;  // Break the circle
    
    // Now free as a normal linked list
    temp = head;
    struct node* next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    int n, value;
    struct node* head = NULL;
    
    // Read number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Read n elements and create circular linked list
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertend(head, value);
    }
    
    // Print the circular linked list
    printf("Circular linked list elements: ");
    printcircularlist(head);
    
    // Free allocated memory
    freecircularlist(head);
    
    return 0;
}