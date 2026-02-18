#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // Read number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Allocate array and read elements
    printf("Enter elements: ");
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Initialize max and min with first element
    int max = arr[0];
    int min = arr[0];
    
    // Find max and min
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    // Print results
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    
    free(arr);
    return 0;
}
