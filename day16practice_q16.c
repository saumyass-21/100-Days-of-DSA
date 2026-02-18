#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    int maxVal = -1000000;
    int minVal = 1000000;
    
    // Find range of values
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }
    
    // Create frequency array
    int range = maxVal - minVal + 1;
    int* freq = (int*)calloc(range, sizeof(int));
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i] - minVal]++;
    }
    
    // Print results
    int first = 1;
    for (int i = 0; i < range; i++) {
        if (freq[i] > 0) {
            if (!first) {
                printf(" ");
            }
            printf("%d:%d", i + minVal, freq[i]);
            first = 0;
        }
    }
    
    free(arr);
    free(freq);
    return 0;
}
