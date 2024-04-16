#include <stdio.h>

/**
 * @brief Counts the number of occurrences of a given character in a string.
 *
 * @param str The string to search in.
 * @param ch The character to search for.
 * @return The number of occurrences of the character in the string.
 */
int countOccurrences(char str[], char ch)
{
    /* The number of occurrences of the character in the string. */
    int count = 0;

    /* Iterate over the characters in the string. */
    for (int i = 0; str[i] != '\0'; ++i)
    {
        /* If the current character is the search character, increment the count. */
        if (str[i] == ch)
        {
            count++;
        }
    }

    /* Return the number of occurrences of the character in the string. */
    return count;
}

int main()
{
    char str[100], ch;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter a character to count: ");
    scanf(" %c", &ch); // Note the space before %c to consume whitespace characters

    printf("Occurrences of '%c': %d\n", ch, countOccurrences(str, ch));

    return 0;
}
