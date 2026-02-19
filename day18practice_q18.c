#include <stdio.h>
#include <stdlib.h>

void reverse(int* arr, int start, int end){ 
 	while (start < end) 
	{
		int temp = arr[start];
 		arr[start] = arr[end];
 		arr[end] = temp;
 		start++;
 		end--;
 	}
}

int main() {
 	int n, k;
	// Read number of elements
	printf("Enter the number of elements: ");
	scanf("%d", &n);
 	// Allocate and read array
 	int* arr = (int*)malloc(n * sizeof(int));
	printf("Enter the elements: ");
 	for (int i = 0; i < n; i++) 
	{
 		scanf("%d", &arr[i]);
 	}
 	// Read rotation value
	printf("enter the roatation value: ");
 	scanf("%d", &k);
 	// Normalize k (handle cases where k > n)
 	k = k % n;
	if (k > 0) 
	{
 		// Reverse entire array
 		reverse(arr, 0, n - 1);
 		// Reverse first k elements
 		reverse(arr, 0, k - 1);
        	// Reverse remaining n-k elements
		reverse(arr, k, n - 1);
 	}
	// Print rotated array
	for (int i = 0; i < n; i++) 
	{
		printf("%d", arr[i]);
 		if (i < n - 1) 
		{
 			printf(" ");
		}
 	}
	printf("\n");
	free(arr);
	return 0;
}
