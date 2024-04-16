#include <stdio.h>
#include <string.h>

/**
 * @file 01_compare_strings.cpp
 * @brief This program compares two strings and prints whether they are equal or not
 * @author
 */
int main()
{
    // Declare two character arrays to store the input strings
    char str1[100], str2[100];

    // Print a message to the user and read the string input
    printf("Enter first string: ");
    scanf("%s", str1);

    // Print a message to the user and read the string input
    printf("Enter second string: ");
    scanf("%s", str2);

    // Compare the two strings using the strcmp function
    // If the function returns 0, the strings are equal
    if (strcmp(str1, str2) == 0)
    {
        // Print a message to the user if the strings are equal
        printf("Strings are equal.\n");
    }
    else
    {
        // Print a message to the user if the strings are not equal
        printf("Strings are not equal.\n");
    }
    return 0;
}
