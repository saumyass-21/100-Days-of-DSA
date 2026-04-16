#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sum;
    int index;
} Pair;

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Array to store prefix sums
    int* prefixSum = (int*)malloc(n * sizeof(int));
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    
    int maxLen = 0;
    
    // Check all subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum;
            if (i == 0) {
                sum = prefixSum[j];
            } else {
                sum = prefixSum[j] - prefixSum[i - 1];
            }
            
            if (sum == 0 && (j - i + 1) > maxLen) {
                maxLen = j - i + 1;
            }
        }
    }
    
    printf("%d\n", maxLen);
    
    free(arr);
    free(prefixSum);
    
    return 0;
}