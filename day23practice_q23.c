#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
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

// Function to create a linked list from an array
struct Node* createList(int arr[], int n) {
    if (n <= 0) return NULL;
    
    struct Node* head = createNode(arr[0]);
    struct Node* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    // Handle empty list cases
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    // Create a dummy node to simplify logic
    struct Node* dummy = createNode(0);
    struct Node* current = dummy;
    
    // Traverse both lists and add the smaller element to result
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // Add remaining nodes from either list
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    
    // Save the head of merged list
    struct Node* mergedHead = dummy->next;
    free(dummy);  // Free the dummy node
    return mergedHead;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to free allocated memory
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n, m;
    
    // Read first list
    scanf("%d", &n);
    int* arr1 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    
    // Read second list
    scanf("%d", &m);
    int* arr2 = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    
    // Create linked lists
    struct Node* list1 = createList(arr1, n);
    struct Node* list2 = createList(arr2, m);
    
    // Merge the lists
    struct Node* mergedList = mergeLists(list1, list2);
    
    // Print the result
    printList(mergedList);
    
    // Free allocated memory
    freeList(mergedList);  // This frees all nodes
    free(arr1);
    free(arr2);
    
    return 0;
}