#include <stdio.h>

/**
 * Function to return sum of array elements using pointers
 * @param arr Array of integers
 * @param n Number of elements in the array
 * @return Sum of all elements in the array
 * @details
 * This function returns the sum of all elements in the array using pointers.
 * @attention
 */
int findVectorSumUsingPointers(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of array elements: %d\n", findVectorSumUsingPointers(arr, n));
    printf("Enter any number to exit: ");
    scanf("%d");
    return 0;
}