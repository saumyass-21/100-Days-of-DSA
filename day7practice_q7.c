#include <stdio.h>

int fib(int n)    // Function to compute nth Fibonacci number
{
    if (n == 0)    // Base case for n=0
    {
        return 0;    // Fibonacci(0) = 0
    }
    if (n == 1)    // Base case for n=1
    {
        return 1;    // Fibonacci(1) = 1
    }
    return fib(n - 1) + fib(n - 2);    // Recursive case
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);    // Read input number
    
    int result = fib(n);    // Call recursive function
    printf("Fibonacci number at position %d is: %d\n", n, result);    // Print the result
    
    return 0;
}
