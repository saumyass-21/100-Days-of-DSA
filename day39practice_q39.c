#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

int main() {
    int n, val;
    char op[20];
    
    printf("Enter number of operations: ");
    scanf("%d", &n);
    
    int *heap = (int*)malloc(n * sizeof(int));
    int size = 0;
    
    printf("\nAvailable operations:\n");
    printf("  insert <value>\n");
    printf("  extractMin\n");
    printf("  peek\n\n");
    
    for (int i = 0; i < n; i++) {
        printf("Operation %d: ", i+1);
        scanf("%s", op);
        
        if (strcmp(op, "insert") == 0) {
            printf("  Enter value: ");
            scanf("%d", &val);
            heap[size] = val;
            int curr = size++;
            while (curr > 0 && heap[curr] < heap[(curr - 1) / 2]) {
                swap(&heap[curr], &heap[(curr - 1) / 2]);
                curr = (curr - 1) / 2;
            }
            printf("  Inserted %d\n", val);
        }
        else if (strcmp(op, "extractMin") == 0) {
            if (size == 0)
                printf("  Result: -1 (heap empty)\n");
            else {
                printf("  Result: %d\n", heap[0]);
                heap[0] = heap[--size];
                heapify(heap, size, 0);
            }
        }
        else if (strcmp(op, "peek") == 0) {
            if (size == 0)
                printf("  Result: -1 (heap empty)\n");
            else
                printf("  Result: %d\n", heap[0]);
        }
        else {
            printf("  Invalid command! Use insert, extractMin, or peek\n");
            i--; // Don't count invalid operations
        }
    }
    
    printf("\nFinal heap state: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
    
    free(heap);
    return 0;
}