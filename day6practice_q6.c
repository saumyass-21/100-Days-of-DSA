#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);    // Read array size
    int arr[n];    // Create array of size n
    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++)    // Loop to read all numbers
    {
        scanf("%d", &arr[i]);    // Read each number into array
    }
    int j = 0;    // Pointer to track unique elements
    for (int i = 1; i < n; i++)    // Loop through array
    {
        if (arr[i] != arr[j])    // If element is different
        {
            j++;    // Move to next position
            arr[j] = arr[i];    // Store unique element
        }
    }
    printf("Unique elements: ");    // Print result header
    for (int i = 0; i <= j; i++)    // Loop through unique elements
    {
        printf("%d ", arr[i]);    // Print each element with space
    }
    printf("\n");
    return 0;
}
