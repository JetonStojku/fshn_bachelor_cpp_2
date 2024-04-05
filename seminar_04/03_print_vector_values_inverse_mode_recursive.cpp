#include <stdio.h>

/**
 * Function to print the values of an array in inverse mode recursive mode.
 * @param arr Array of integers
 * @param n Number of elements in the array
 * @return Void
 * @details
 * This function prints the values of an array in inverse mode recursive mode.
 * The function uses recursion to print the values of the array.
 * @attention
 * The function does not return anything.
 */
void printArrayInverseRecursive(int arr[], int n)
{
    // Base case: if n is 1, print the first element
    if (n == 1)
    {
        printf("%d ", arr[0]);
        return;
    }
    // Recursive case: print the last element and call the function again with n - 1
    printf("%d ", arr[n - 1]);
    printArrayInverseRecursive(arr, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArrayInverseRecursive(arr, n);
    printf("\nEnter any number to exit: ");
    scanf("%d");
    return 0;
}