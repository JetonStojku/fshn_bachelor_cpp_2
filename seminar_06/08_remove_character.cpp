#include <stdio.h>
#include <string.h>

/**
 * Removes all occurrences of a given character from a C-style string.
 *
 * @param str The string to modify.
 * @param ch The character to remove.
 */
void removeCharacter(char str[], char ch) {
    /* Iterate over the string and copy all characters that are not equal to ch
     * to the beginning of the string, overwriting the original characters.
     * When the end of the string is reached, the null terminator is put in its
     * place to mark the end of the modified string. */
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; ++i) {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; // Mark the end of the modified string
}

int main() {
    char str[100], ch;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    printf("Enter a character to remove: ");
    scanf(" %c", &ch); // Note the space before %c to consume whitespace characters
    
    removeCharacter(str, ch);
    
    printf("String after removing '%c': %s\n", ch, str);

    return 0;
}
