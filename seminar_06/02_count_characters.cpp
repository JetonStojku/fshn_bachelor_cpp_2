#include <stdio.h>
#include <string.h>

/**
 * @brief Returns the number of characters in a given string.
 * @param str The string to be evaluated.
 * @return The number of characters in the given string.
 */
int countCharacters(char str[])
{
    // Returns the number of characters in a given string using the strlen function
    // from the string.h library.
    return strlen(str);
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Number of characters: %d\n", countCharacters(str));

    return 0;
}
