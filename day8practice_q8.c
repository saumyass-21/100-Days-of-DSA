#include <stdio.h>

int power(int a, int b)    // Function to compute a^b recursively
{
    if (b == 0)    // Base case: any number to power 0 is 1
    {
        return 1;    // a^0 = 1
    }
    if (b == 1)    // Base case: any number to power 1 is itself
    {
        return a;    // a^1 = a
    }
    return a * power(a, b - 1);    // Recursive case: a^b = a * a^(b-1)
}

int main()
{
    int a, b;
    printf("Enter base (a) and exponent (b): ");
    scanf("%d %d", &a, &b);    // Read both numbers
    
    int result = power(a, b);    // Call recursive function
    printf("%d raised to power %d is: %d\n", a, b, result);    // Print result
    
    return 0;
}
