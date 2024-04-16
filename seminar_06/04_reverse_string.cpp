#include <stdio.h>
#include <string.h>

/**
 * Reverses the given string in place.
 *
 * @param str the string to reverse
 */
void reverseString(char str[])
{
    // Find the length of the string
    int length = strlen(str);

    // Iterate through the string, swapping characters
    // starting from the first and last character
    for (int i = 0; i < length / 2; ++i)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
