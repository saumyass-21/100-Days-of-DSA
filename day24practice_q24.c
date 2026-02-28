#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {						// Function to create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete first occurrence of ptr
struct Node* deletefirst(struct Node* head, int ptr) {
    // If list is empty
    if (head == NULL) {
        return NULL;
    }
    
    // If head node itself contains the key
    if (head->data == ptr) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    // Search for the key in remaining nodes
    struct Node* current = head;
    struct Node* prev = NULL;
    
    while (current != NULL && current->data != ptr) {
        prev = current;
        current = current->next;
    }
    
    // If key was found
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
    
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to free the entire list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, key, value;
    struct Node* head = NULL;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);								// Read number of elements
    
    printf("Enter the elements of linked list: ");
    for (int i = 0; i < n; i++) {						// Read n elements and create list
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }
    printf("Enter the element to delete: ");
    scanf("%d", &key);								// Read key to delete
    
    head = deletefirst(head, key);						// Delete first occurrence of key
   
    printList(head);								// Print the result
    
    freeList(head);								// Free allocated memory
    
    return 0;
}