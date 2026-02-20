#include <stdio.h>
#include <stdlib.h>

// Simple hash map implementation for this problem
#define HASH_SIZE 10007

typedef struct Node {
    int sum;
    int count;
    struct Node* next;
} Node;

int hashFunction(int key) {
    return abs(key) % HASH_SIZE;
}

void insert(Node** hashMap, int sum) {
    int index = hashFunction(sum);
    Node* current = hashMap[index];
    
    // Search for existing sum
    while (current != NULL) {
        if (current->sum == sum) {
            current->count++;
            return;
        }
        current = current->next;
    }
    
    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->count = 1;
    newNode->next = hashMap[index];
    hashMap[index] = newNode;
}

int find(Node** hashMap, int sum) {
    int index = hashFunction(sum);
    Node* current = hashMap[index];
    
    while (current != NULL) {
        if (current->sum == sum) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

void freeHashMap(Node** hashMap) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = hashMap[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Initialize hash map
    Node** hashMap = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    
    // Insert initial prefix sum 0 with count 1
    // This handles subarrays starting from index 0
    insert(hashMap, 0);
    
    int prefixSum = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        // If this prefix sum was seen before, all subarrays ending at i
        // between the previous occurrence and i have sum zero
        int frequency = find(hashMap, prefixSum);
        count += frequency;
        
        // Update frequency for current prefix sum
        insert(hashMap, prefixSum);
    }
    
    printf("%d\n", count);
    
    // Clean up
    free(arr);
    freeHashMap(hashMap);
    free(hashMap);
    
    return 0;
}
