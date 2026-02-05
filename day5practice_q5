#include <stdio.h>

int main() 
{
int size1, size2;
printf("Enter number of arrivals for Server 1: ");
scanf("%d", &size1);    // Read size of first array
int server1[size1];    // Create array for server 1
printf("Enter %d arrival times for Server 1: ", size1);
for (int i = 0; i < size1; i++)     // Loop to read all times
    {
        scanf("%d", &server1[i]);    // Read each time
    }
printf("Enter number of arrivals for Server 2: ");
scanf("%d", &size2);    // Read size of second array
int server2[size2];    // Create array for server 2
printf("Enter %d arrival times for Server 2: ", size2); // Prompt for times
    for (int i = 0; i < size2; i++)    // Loop to read all times 
    {
        scanf("%d", &server2[i]);    // Read each time
    }
printf("Merged chronological log: ");   // Print result header
int i = 0, j = 0;    // Pointers for both arrays
while (i < size1 && j < size2)    // While both have elements 
    {                
        if (server1[i] < server2[j])    // Compare current elements 
        {              
            printf("%d ", server1[i]);     // Print smaller one
            i++;    // Move pointer in server1
        } 
        else  
        {
            printf("%d ", server2[j]);    // Print smaller one
            j++;    // Move pointer in server2
        }
    }
    while (i < size1)    // If server1 has leftovers 
    {
        printf("%d ", server1[i]);   //Print remaining elements
        i++;    //Move pointer
    }
    while (j < size2)    //If server2 has leftovers 
    { 
        printf("%d ", server2[j]);    //Print remaining elements
        j++;    //Move pointer
    }
printf("\n");    //New line at end
return 0;    //Program ends
}
