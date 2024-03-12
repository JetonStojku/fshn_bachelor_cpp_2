#include <stdio.h>
#include <stdlib.h>

// Function to count the number of even and odd elements in an array and return a vector
void sum(int arr[], int n, int counts[])
{
    counts[0] = 0; // Index 0 for odd count
    counts[1] = 0; // Index 1 for even count

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % 2 == 0)
        {
            counts[1]++; // Increment even count
        }
        else
        {
            counts[0]++; // Increment odd count
        }
    }
}

int main()
{
    int n = 9;
    int my_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Declare counts array to store the results
    int counts[2];

    // Call the sum function to populate the counts array
    sum(my_list, n, counts);

    // Print the results
    printf("Odd count: %d\n", counts[0]);
    printf("Even count: %d\n", counts[1]);

    printf("\nEnter any number to exit: ");
    scanf("%d");
    return 0;
}
