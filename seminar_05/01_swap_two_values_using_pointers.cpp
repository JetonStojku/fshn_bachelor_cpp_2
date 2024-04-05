#include <stdio.h>

/**
 * Function to swap two values using pointers.
 * @param a Pointer to the first value
 * @param b Pointer to the second value
 * @return Void
 * @details
 * This function swaps two values using pointers.
 * The function takes two pointers to the values to be swapped.
 * @attention
 * The function does not return anything.
 */
void swapTwoValuesUsingPointers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10, b = 20;
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swapTwoValuesUsingPointers(&a, &b);
    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}