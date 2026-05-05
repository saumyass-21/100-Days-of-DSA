#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Element;

void merge(Element* arr, int* counts, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Element* L = (Element*)malloc(n1 * sizeof(Element));
    Element* R = (Element*)malloc(n2 * sizeof(Element));
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    int smallerCount = 0;
    
    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            counts[L[i].idx] += smallerCount;
            arr[k++] = L[i++];
        } else {
            smallerCount++;
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        counts[L[i].idx] += smallerCount;
        arr[k++] = L[i++];
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
    }
    
    free(L);
    free(R);
}

void mergeSort(Element* arr, int* counts, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, counts, left, mid);
        mergeSort(arr, counts, mid + 1, right);
        merge(arr, counts, left, mid, right);
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)calloc(numsSize, sizeof(int));
    
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }
    
    mergeSort(arr, counts, 0, numsSize - 1);
    
    free(arr);
    return counts;
}

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* nums = (int*)malloc(n * sizeof(int));
    
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int returnSize;
    int* result = countSmaller(nums, n, &returnSize);
    
    printf("Counts: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(nums);
    free(result);
    return 0;
}