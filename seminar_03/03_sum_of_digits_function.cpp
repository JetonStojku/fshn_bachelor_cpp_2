#include <stdio.h>

// Recursive function to calculate the sum of digits of a number
int sumOfDigits(int n) {
    // Base case: if n is less than 10, return n
    if (n < 10) {
        return n;
    }
    // Recursive case: return last digit + sum of digits of the remaining number
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    int num = 12345;
    printf("Sum of digits of %d is %d\n", num, sumOfDigits(num));
    return 0;
}
