#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

typedef struct {
    int* table;
    int size;
} HashTable;

HashTable* createHashTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (int*)malloc(m * sizeof(int));
    ht->size = m;
    
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
    
    return ht;
}

int hashFunction(int key, int m) {
    return key % m;
}

void insert(HashTable* ht, int key) {
    int index = hashFunction(key, ht->size);
    int i = 0;
    
    while (i < ht->size) {
        int pos = (index + i * i) % ht->size;
        
        if (ht->table[pos] == EMPTY || ht->table[pos] == DELETED) {
            ht->table[pos] = key;
            return;
        }
        
        i++;
    }
    
    printf("Hash table is full!\n");
}

int search(HashTable* ht, int key) {
    int index = hashFunction(key, ht->size);
    int i = 0;
    
    while (i < ht->size) {
        int pos = (index + i * i) % ht->size;
        
        if (ht->table[pos] == EMPTY) {
            return 0; // Not found
        }
        
        if (ht->table[pos] == key) {
            return 1; // Found
        }
        
        i++;
    }
    
    return 0; // Not found
}

void freeHashTable(HashTable* ht) {
    free(ht->table);
    free(ht);
}

int main() {
    int m, n;
    char op[10];
    int key;
    
    printf("Enter table size: ");
    scanf("%d", &m);
    
    printf("Enter number of operations: ");
    scanf("%d", &n);
    
    HashTable* ht = createHashTable(m);
    
    printf("\nEnter operations (INSERT/SEARCH key):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        
        if (strcmp(op, "INSERT") == 0) {
            insert(ht, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(ht, key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }
    
    freeHashTable(ht);
    
    return 0;
}