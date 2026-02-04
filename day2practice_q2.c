#include <stdio.h>

int main() 
{
int n, pos;
printf("Enter number of elements: ");
scanf("%d", &n);    // Read number of elements
int arr[n];    // Declare array with size n
printf("Enter elements: ");
for (int i = 0; i < n; i++)    // Read array elements 
    {
        scanf("%d", &arr[i]);
    }
printf("Enter position to delete: ");
scanf("%d", &pos);    // Read position to delete 
if (pos < 1 || pos > n)    // Validate position 
    {
        printf("Invalid position!\n");
        return 1;  // Exit with error code
    }
int index_to_delete = pos - 1;    // Convert 1-based position to 0-based index
for (int i = index_to_delete; i < n - 1; i++)    // Shift elements to the left starting from the deletion position 
    {
        arr[i] = arr[i + 1];
    }
for (int i = 0; i < n - 1; i++)    // Print the updated array
    {  
        printf("%d", arr[i]);
        if (i < n - 2) 
        {
            printf(" ");
        }
    }
printf("\n");
return 0;
}
