#include <stdio.h>
#include <string.h>

/**
 * @brief Returns the length of the longest word in a string
 *
 * @param str is the input string
 * @return The length of the longest word in the string
 */
int longestWordLength(char str[])
{
    /**
     * The length of the current word
     */
    int length = 0;
    /**
     * The length of the longest word found so far
     */
    int max_length = 0;

    /**
     * Loop through the input string
     */
    for (int i = 0; str[i] != '\0'; ++i)
    {
        /**
         * If the current character is not a space, increment the length
         * of the current word.
         */
        if (str[i] != ' ')
        {
            length++;
        }
        /**
         * If the current character is a space, or we have reached the end
         * of the input string, check if the current word is longer than
         * the longest word found so far.
         */
        else
        {
            /**
             * If the length of the current word is greater than the
             * longest word found so far, update max_length
             */
            if (length > max_length)
            {
                max_length = length;
            }
            /**
             * Reset the length of the current word to 0
             */
            length = 0;
        }
    }
    // Check if the last word is the longest
    if (length > max_length)
    {
        max_length = length;
    }
    return max_length;
}

int main()
{
    char str[100];

    printf("Enter a sentence: ");
    scanf(" %[^\n]s", str);

    printf("Length of the longest word: %d\n", longestWordLength(str));

    return 0;
}
