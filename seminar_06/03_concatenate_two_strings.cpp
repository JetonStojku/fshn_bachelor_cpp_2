/**
 * @file 03_concatenate_two_strings.cpp
 * @brief Concatenates two strings using strcat() function.
 */
#include <cstdio>   // For printf()
#include <cstring>  // For strcat()

int main() {
    // Declare variables to store two strings
    char str1[100] = "";  // First string
    char str2[100] = "";  // Second string

    // Get input from user
    printf("Enter first string: ");
    scanf("%99s", str1);  // Limit input size to avoid buffer overflow

    printf("Enter second string: ");
    scanf("%99s", str2);

    // Concatenate two strings using strcat() function
    strcat(str1, str2);

    // Print the concatenated string
    printf("Concatenated string: %s\n", str1);

    return 0;
}
