#include <stdio.h>
#include <stdlib.h>

// Lomuto partition scheme
int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

// Hoare partition scheme
int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        
        do {
            j--;
        } while (arr[j] > pivot);
        
        if (i >= j) {
            return j;
        }
        
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSortLomuto(int arr[], int low, int high) {
    if (low < high) {
        int pi = lomutoPartition(arr, low, high);
        quickSortLomuto(arr, low, pi - 1);
        quickSortLomuto(arr, pi + 1, high);
    }
}

void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        int pi = hoarePartition(arr, low, high);
        quickSortHoare(arr, low, pi);
        quickSortHoare(arr, pi + 1, high);
    }
}

int main() {
    int n, choice;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Choose partition scheme:\n");
    printf("1. Lomuto Partition\n");
    printf("2. Hoare Partition\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        quickSortLomuto(arr, 0, n - 1);
        printf("Sorted using Lomuto: ");
    } else {
        quickSortHoare(arr, 0, n - 1);
        printf("Sorted using Hoare: ");
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}