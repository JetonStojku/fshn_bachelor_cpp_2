#include <stdio.h>
#include <string.h>

/**
 * @brief Takes a string as input, converts all lowercase letters to uppercase
 * and prints the resulting string.
 *
 * @returns 0 on success
 */
int main()
{
    char str[100]; // Buffer to store input string

    printf("Enter a string: ");
    scanf("%s", str); // Get input string from user

    // Iterate over every character in the string
    for (int i = 0; str[i] != '\0'; ++i)
    {
        // If current character is lowercase,
        // convert it to uppercase
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }

    printf("Uppercase string: %s\n", str); // Print uppercase string

    return 0; // Indicate success
}
