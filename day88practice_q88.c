#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int canPlace(int* stalls, int n, int cows, int dist) {
    int count = 1;  // Place first cow at first stall
    int lastPos = stalls[0];
    
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count >= cows) {
                return 1;
            }
        }
    }
    
    return count >= cows;
}

int largestMinDistance(int* stalls, int n, int cows) {
    // Sort stalls in ascending order
    qsort(stalls, n, sizeof(int), cmp);
    
    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canPlace(stalls, n, cows, mid)) {
            result = mid;
            left = mid + 1;  // Try for larger distance
        } else {
            right = mid - 1;  // Try smaller distance
        }
    }
    
    return result;
}

int main() {
    int n, cows;
    
    printf("Enter number of stalls and cows: ");
    scanf("%d %d", &n, &cows);
    
    int* stalls = (int*)malloc(n * sizeof(int));
    
    printf("Enter stall positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }
    
    int result = largestMinDistance(stalls, n, cows);
    printf("Maximum minimum distance: %d\n", result);
    
    free(stalls);
    return 0;
}