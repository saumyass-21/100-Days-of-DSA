#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to create a linked list from array
struct node* createll(int arr[], int n) {
    if (n <= 0) return NULL;
    
    struct node* head = createnode(arr[0]);
    struct node* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = createnode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Function to print the linked list
void printll(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to rotate the linked list right by k places
struct node* rotater(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k <= 0) {
        return head;
    }
    
    // Find the length of the linked list
    int length = 1;
    struct node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }
    
    // Optimize k to handle cases where k > length
    k = k % length;
    if (k == 0) {
        return head;
    }
    
    // Connect the last node to the head to form a circular list
    tail->next = head;
    
    // Find the new tail (the (length - k - 1)th node)
    int stepnewtail = length - k - 1;
    struct node* newtail = head;
    for (int i = 0; i < stepnewtail; i++) {
        newtail = newtail->next;
    }
    
    // The new head is the next node after the new tail
    struct node* newhead = newtail->next;
    
    // Break the circular connection
    newtail->next = NULL;
    
    return newhead;
}

// Function to free the memory allocated for the linked list
void freell(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n, k;
    
    // Read the number of elements
    scanf("%d", &n);
    
    if (n <= 0) {
        return 0;
    }
    
    // Read the array elements
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read k
    scanf("%d", &k);
    
    // Create the linked list
    struct node* head = createll(arr, n);
    
    // Rotate the linked list
    head = rotater(head, k);
    
    // Print the rotated linked list
    printll(head);
    
    // Free the allocated memory
    freell(head);
    free(arr);
    
    return 0;
}