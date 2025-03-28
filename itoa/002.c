// Exercise:
// Create a function to convert an integer to string.
// This solution don't use pointers.

// How to compile this exercise?
// gcc -g 00.c -o 002
// -g: adds debug information for gdb debugger.
// How to execute the binary file?
// Sets the file as executable: chmod +x 002
// Runs the file: ./002

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @fn itoa(int n, char s[])
 * @brief Converts an integer into a string.
 * @param[in]  n The integer value to convert.
 * @param[out] s The char array to store the converted integer.
 */
void itoa(int n, char s[]);

/**
 * @fn int ilen(int n)
 * @brief Return the length of an integer n.
 * @param[in] n The integer whose length to calculate.
 * @return The length of n.
 * @retval A positive integer.
 */
int ilen(int n);

int main() {
    // The integer to convert into string
    int n = 2024;
    char ns[256];

    itoa(n, ns);
    printf("%s\n", ns);

    return EXIT_SUCCESS;
}

void itoa(int n, char s[]) {
    int nlen, nlen2;
    int to_add = 0;

    // Handles INT_MIN overflow
    if (n == INT_MIN) {
        // n: -2147483648
        n++;
        to_add = 1;
    }

    // Calculates the nlen
    nlen = nlen2 = ilen(n) - 1;

    // Handles a negative integer
    if (n < 0) {
        n = -n;
        s[0] = '-';
        nlen++;
        nlen2++;
    }

    // Adds the last char in the string
    s[nlen + 1] = '\0';

    // Converts n to string from right to left
    do s[nlen--] = n % 10 + '0'; while (n /= 10);

    // Adds the rest of the INT_MIN
    if (to_add) {
        int nlen = ilen(n);
        s[nlen2] = s[nlen2] + 1;
    }
}

int ilen(int n) {
    int nlen = 1;
    while (n /= 10) nlen++;
    return nlen;
}