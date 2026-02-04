#include <stdio.h>

int main() 
{
int n;
printf("Enter size of array: ");
scanf("%d", &n);     // Read array size
int arr[n];    // Declare array
 printf("Enter elements of array: ");   
for(int i = 0; i < n; i++)    // Read array elements 
    {
        scanf("%d", &arr[i]);
    }
int left = 0;    // Two-pointer approach to reverse in-place
int right = n - 1;
while(left < right) 
    {
        int temp = arr[left];    // Swap elements
        arr[left] = arr[right];
        arr[right] = temp;
        left++;     // Move pointers
        right--;
    }
printf("reversed array: ");
for(int i = 0; i < n; i++)    // Print reversed array 
   {
        printf("%d", arr[i]);
        if(i < n - 1) 
        {
            printf(" ");
        }
    }
printf("\n");
return 0;
}
