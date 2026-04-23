#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int result = n;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] >= x) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int upperBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int result = n;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] > x) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int n, x;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter sorted array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter target value: ");
    scanf("%d", &x);
    
    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);
    
    printf("Lower Bound: %d\n", lb);
    printf("Upper Bound: %d\n", ub);
    
    return 0;
}