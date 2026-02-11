#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];    // Declare character array
    printf("Enter string: ");
    scanf("%s", s);    // Read input string
    int len = strlen(s);    // Get length of string
    int left = 0;    // Pointer at start
    int right = len - 1;    // Pointer at end
    int isPalindrome = 1;    // Flag to check palindrome (1 = true, 0 = false)
    while (left < right)    // Continue until pointers meet
    {
        if (s[left] != s[right])    // If characters don't match
        {
            isPalindrome = 0;    // Not a palindrome
            break;    // Exit loop
        }
        left++;    // Move left pointer forward
        right--;    // Move right pointer backward
    }
    if (isPalindrome == 1)    // If flag is still true
    {
        printf("YES!\n");    // Print YES
    }
    else
    {
        printf("NO\n");    // Print NO
    }
    return 0;
}
