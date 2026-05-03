#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    long long invCount = 0;
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            // All remaining elements in L are greater than R[j]
            invCount += (n1 - i);
        }
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    free(L);
    free(R);
    
    return invCount;
}

long long mergeSort(int arr[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        invCount += mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);
        invCount += merge(arr, left, mid, right);
    }
    return invCount;
}

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    long long inversions = mergeSort(arr, 0, n - 1);
    
    printf("Number of inversions: %lld\n", inversions);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}