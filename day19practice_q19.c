#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	printf("Enter the elemnts: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	//sorting array
	qsort(arr, n, sizeof(int), compare);
	int left = 0;		//points to the smallest
	int right = n - 1;	//point to the largest
	int minsum = INT_MAX;
	//track closest to sum of zero
	int result1 = arr[left];
	int result2 = arr[right];

	while (left < right) {
		int currentsum = arr[left] + arr[right];

		//updating if closer to zero
		if (abs(currentsum) < abs(minsum)) {
			minsum = currentsum;
			result1 = arr[left];
			result2 = arr[right];
		}

		//moving pointers based on sum
		if (currentsum < 0) {
			left++;		//needs bigger number
		} else if (currentsum > 0) {
			right--;	//need smaller number
		} else {
			break;		//exact zero found
		}
	}

	//printing smaller first
	if (result1 > result2) {
		int temp = result1;
		result1 = result2;
		result2 = temp;
	}
	printf("%d %d\n", result1, result2);
	free(arr);
	return 0;
}
