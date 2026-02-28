#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
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

// Function to count occurrences of key
int countocc(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {					// Traverse the list
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    
    return count;
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
    
    printf("Enter number of elements: ");
    scanf("%d", &n);						// Read number of elements
    
    printf("Enter elements of list: ");
    for (int i = 0; i < n; i++) {				// Read n elements and create list
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }
    printf("Enter element to check Occurrences: ");
    scanf("%d", &key);						// Read key to count
    int result = countocc(head, key);				// Count occurrences
    printf("%d\n", result);					// Print the result
    freeList(head);						// Free allocated memory
    return 0;
}