#include <stdio.h>

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n)
{
    // Base cases: Fibonacci of 0 is 0, Fibonacci of 1 is 1
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    // Recursive case: Fibonacci of n is the sum of Fibonacci of (n-1) and Fibonacci of (n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int num = 7;
    printf("Fibonacci number at index %d is %d\n", num, fibonacci(num));
    return 0;
}
