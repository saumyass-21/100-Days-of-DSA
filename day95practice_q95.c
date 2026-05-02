#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node* next;
} Node;

Node* createNode(float val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(Node** head, float val) {
    Node* newNode = createNode(val);
    
    if (*head == NULL || (*head)->data >= val) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL && current->next->data < val) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    Node** buckets = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }
    
    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        insertSorted(&buckets[bucketIndex], arr[i]);
    }
    
    // Concatenate all buckets
    int idx = 0;
    for (int i = 0; i < n; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[idx++] = current->data;
            current = current->next;
        }
    }
    
    // Free memory
    for (int i = 0; i < n; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    float* arr = (float*)malloc(n * sizeof(float));
    
    printf("Enter %d real numbers in [0,1): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    
    bucketSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}