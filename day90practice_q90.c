#include <stdio.h>
#include <stdlib.h>

int canPaint(int* boards, int n, int painters, int maxTime) {
    int paintersNeeded = 1;
    int currentSum = 0;
    
    for (int i = 0; i < n; i++) {
        if (currentSum + boards[i] <= maxTime) {
            currentSum += boards[i];
        } else {
            paintersNeeded++;
            currentSum = boards[i];
            if (paintersNeeded > painters) {
                return 0;
            }
        }
    }
    return 1;
}

int minTimeToPaint(int* boards, int n, int painters) {
    int left = 0, right = 0;
    
    for (int i = 0; i < n; i++) {
        if (boards[i] > left) left = boards[i];
        right += boards[i];
    }
    
    int result = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canPaint(boards, n, painters, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int n, painters;
    
    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &painters);
    
    int* boards = (int*)malloc(n * sizeof(int));
    
    printf("Enter board lengths: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }
    
    int result = minTimeToPaint(boards, n, painters);
    printf("Minimum time required: %d\n", result);
    
    free(boards);
    return 0;
}