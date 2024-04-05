#include <stdio.h>

/**
 * Recursive function to calculate the sum of elements of an array.
 * @param arr Array of integers
 * @param n Number of elements in the array
 * @return Sum of all elements in the array
 */
int sumOfArray(int arr[], int n)
{
    // Base case: if n is 1, return the first element
    if (n == 1)
    {
        return arr[0];
    }
    // Recursive case: return the last element + sum of remaining elements
    return arr[n - 1] + sumOfArray(arr, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of array elements: %d\n", sumOfArray(arr, n));
    printf("Enter any number to exit: ");
    scanf("%d");
    return 0;
}