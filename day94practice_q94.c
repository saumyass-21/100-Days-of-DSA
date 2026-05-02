#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Create count array
    int* count = (int*)calloc(max + 1, sizeof(int));
    
    // Store frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Compute prefix sums (cumulative frequency)
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    int* output = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    free(count);
    free(output);
}

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d non-negative integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    countingSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}