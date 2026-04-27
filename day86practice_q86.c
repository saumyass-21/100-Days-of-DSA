#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    
    int left = 1, right = n;
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // To avoid overflow, use division instead of multiplication
        if (mid <= n / mid) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    int sqrtVal = integerSqrt(n);
    printf("Integer square root: %d\n", sqrtVal);
    
    return 0;
}