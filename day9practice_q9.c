#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];    // Declare character array to store string
    
    printf("Enter string: ");
    scanf("%s", str);    // Read input string
    
    int len = strlen(str);    // Get length of string
    
    printf("Mirrored : ");
    for (int i = len - 1; i >= 0; i--)    // Loop from last character to first
    {
        printf("%c", str[i]);    // Print each character in reverse order
    }
    printf("\n");
    
    return 0;
}
