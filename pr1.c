#include <stdio.h>

int main() 
{
int n, position, x;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n + 1];    //creating extra space for a new element

for (int i=0; i<n; i++)
    {
    scanf("%d", &arr[i]);
    }
printf("Enter position of the Element: ");
scanf("%d", &position);
printf("Enter the new element: ");
scanf("%d", &x);
position=position-1;    // adjusting position according to 0 index
for(int i=n; i>position; i--)
    {
    arr[i]=arr[i-1];
    }
arr[position]=x;
for(int i=0; i<n+1; i++)
    {
    if (i>0)
        {
        printf(" ");
        }
    printf("%d", arr[i]);
    }
printf("\n");
return 0;
}
