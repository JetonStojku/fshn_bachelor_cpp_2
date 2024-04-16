#include <stdio.h>
#include <string.h>

/**
 * @brief Checks if a given string is a palindrome.
 * @param str The string to check.
 * @return 1 if the string is a palindrome, 0 otherwise.
 */
int isPalindrome(char str[])
{
    // Get the length of the string
    int length = strlen(str);

    // Iterate through the string until the middle
    for (int i = 0; i < length / 2; ++i)
    {
        // If the characters at the current position and the end of the string
        // (length - i - 1) do not match, then the string is not a palindrome
        if (str[i] != str[length - i - 1])
        {
            return 0; // Not a palindrome
        }
    }

    // If the loop completed successfully, then the string is a palindrome
    return 1; // Palindrome
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
    {
        printf("String is a palindrome.\n");
    }
    else
    {
        printf("String is not a palindrome.\n");
    }

    return 0;
}
