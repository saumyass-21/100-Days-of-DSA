#include <stdio.h>

int main() 
{
int n, k;
printf("Enter size of array: ");
scanf("%d", &n);    // Read array size
int arr[n];    // Declare array
printf("Enter elements of array: ");
for(int i = 0; i < n; i++)    // Read array elements 
    {
        scanf("%d", &arr[i]);
    }
printf("Enter element to search: ");
scanf("%d", &k);    // Read key to search
int comparisons = 0;
int found = 0; // 0 for false, 1 for true
int index = -1;
for(int i = 0; i < n; i++)    // Linear search 
    {
        comparisons++;
        if(arr[i] == k) 
        {
            found = 1;
            index = i;
            break;
        }
    }
if(found)    // Output result 
    {
        printf("Found at index %d\n", index);
    } 
    else 
    {
        printf("Not Found\n");
    }
printf("position in array = %d\n", comparisons);
return 0;
}
